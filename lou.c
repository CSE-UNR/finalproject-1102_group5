//Subject:Image
//Author:Louis w Pierce lll/Isaiah Marzan
//Date:4-29-24
	
#include <stdio.h>


void DisplayImage(int imageArray[80][80], int h, int w);
void LoadImage(int imageArray[80][80], int* height, int* width);
// int edit(int chg1,int chg2);

int main() {
	int choice = 0;
    int change = 0;
	int imageArray[80][80];
    int height = 0;
    int width = 0;
	do {	
        printf("====================\n");
        printf("Image Modifier\n");
        printf("====================\n");
        printf("1. Load Image\n");
        printf("2. Display Image\n");
        printf("3. Edit Image\n");
        printf("4. Exit\n");
        printf("====================\n");
        printf("Enter your choice: \n");
   
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                LoadImage(imageArray, &height, &width); 
                break;
            case 2:
                DisplayImage(imageArray, height, width);           
                break;
            case 3:
                // EditImage();
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("The picture you have loaded or modified needs to be reloaded!");
                break;
        }	
	}while (choice !=4);
	
	return 0;
}

//case 1 Load image
void LoadImage(int imageArray[80][80], int* h, int* w) {
   
    int height = 0;
    int width = 0;
    char fileName[100];
    printf("What is the name of the image file? ");
    scanf("%s", fileName);

    FILE* filePtr;
    filePtr = fopen(fileName, "r");

    if (filePtr == NULL) {
        fprintf(stderr, "Could not open file.");
        return;
    }

    printf("\n");
    printf("Image successfully loaded!\n\n");
    char line[250];
    while (fgets(line, sizeof(line), filePtr)) {
        height++;
        int i = 0;
        width = 0;
        while (line[i] != '\0') {
            if (line[i] != ' ' && line[i] != '\n') {
                width++;
            }
            i++;
        }
    }
    rewind(filePtr);
    for (int i = 0; i < height; i++) {
        for (int j= 0; j < width; j++) {
            char ch;
            do {
                fscanf(filePtr, "%c", &ch);
            } while (ch == ' ' || ch == '\n'); // Skip spaces and newlines
            imageArray[i][j] = ch - '0'; // Convert character to integer
        }
    }
    fclose(filePtr);
    *w = width;
    *h = height;
}
			
//case 2 Display image
void DisplayImage(int imageArray[80][80], int h, int w){
    printf("\n");
    for(int j = 0; j < h; j++){
        for (int i = 0; i < w; i++){
            if(imageArray[j][i] == 0) {
                printf(" ");
            }
            else if(imageArray[j][i] == 1){
                printf(".");
            }
            else if(imageArray[j][i] == 2){
                printf("o");
            }
            else if(imageArray[j][i] == 3){
                printf("O");
            }
            else if(imageArray[j][i] == 4){
                printf("0");
            }
        }
        printf("\n");
    }
    printf("\n");
}
					
	
			
//case 3 Edit image
// int edit(int chg1,chg2){

// 	printf("	**EDITING** \n");
// 	printf("1: Crop image\n");
// 	printf("2: Dim image\n");
// 	printf("3: Brighten image\n");
//  printf("0: Return to main menu\n");
// 	switch (change) {
//          case 1:
//             CropImage();
//             break;
//          case 2:
//             DimImage();           
//             break;
// 	        case 3:
//             BrightenImage();
//             break;
// 	        case 0:
//             Return();
//             break;
// 	 default:
// 	 printf("The picture you have loaded or modified needs to be reloaded!");
// 	 		break; 	
// 	}	
// 	printf("Choose from one of the options above: "); 
// 	int height, width;
// 	height = chg1;
// 	width = chg2;
// 	printf("The image you want to crop is %d", &DisplayImage);
// 	printf("The row and column values start in the upper lefthand corner.");			
// 	return height;
// }

	
			
