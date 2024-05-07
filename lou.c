//Subject:Image
//Author:Louis w Pierce lll/Isaiah Marzan
//Date:4-29-24
	
#include <stdio.h>


void DisplayImage(int imageArray[80][80], int h, int w);
void LoadImage(int imageArray[80][80], int* height, int* width);
void EditImage(int imageArray[80][80], int* height, int* width);
//void DimImage(int imageArray[80][80], int* height, int* width);
//void BrightenImage(int imageArray[80][80], int* height, int* width);
void CropImage(int imageArray[80][80], int* height, int* width);

int main() {
	int choice = 0;
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
        printf("Choose from one of the options above: ");
       
   
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                LoadImage(imageArray, &height, &width); 
                break;
            case 2:
                DisplayImage(imageArray, height, width);           
                break;
            case 3:
                EditImage(imageArray, &height, &width);
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
            } while (ch == ' ' || ch == '\n'); 
            imageArray[i][j] = ch - '0'; 
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
void EditImage(int imageArray[80][80], int* height, int* width){
	int userInput = 0;
	printf("\n");
 	printf("	**EDITING** \n");
 	printf("1: Crop image\n");
 	printf("2: Dim image\n");
 	printf("3: Brighten image\n");
  	printf("0: Return to main menu\n\n");
  	printf("Choose from one of the options above: ");
  	
  	scanf("%d", &userInput);
 	switch (userInput) {
          case 1:
             CropImage(imageArray, height, width);
             break;
          //case 2:
             //DimImage();           
             //break;
 	  //case 3:
             //BrightenImage();
             //break;
 	  //case 0:
             //Return();
             //break;
 	default:
 	printf("The picture you have loaded or modified needs to be reloaded!");
 	     break; 	
 	//}	
 	//printf("Choose from one of the options above: "); 
 	
 	//printf("The image you want to crop is %d", &DisplayImage);
 	//printf("The row and column values start in the upper lefthand corner.");			
 	return;
}
//case 4 Dim image
//void DimImage(int imageArray[80][80], int* height, int* width){
	//for(int i = 0; i < height; i++) {
		//for(int j = 0; j < width; j++) {
		
			//if(imageArray[i][j] != 0){
				//imageArray[i][j] -= 1;
			//}
		//}
	//}		
	//DisplayImage(int imageArray[80][80], int* height, int* width);
   // }
   // printf("\n");
		//printf("Would you like to save the file? (y/n)");
		//printf("What do you want to name the image file? (include the extension)");
	//int height = 0;
    	//int width = 0;
    	//char fileName[100];
    		//printf("What is the name of the image file? ");
    		//scanf("%s", fileName);

    		//FILE* filePtr;
    		//filePtr = fopen(fileName, "r");

    	//if (filePtr == NULL) {
        //fprintf(stderr, "Could not open file.");
       // return;
   // }
//case 5 Brighten image
//void BrightenImage(int imageArray[80][80], int* height, int* width){
	//for(int i = 0; i < height; i++) {
		//for(int j = 0; j < width; j++) {		
			//if(imageArray[i][j] != 4){
				//imageArray[i][j] += 1;
			//}
		//}
	//}		
	//DisplayImage(int imageArray[80][80], int* height, int* width);
   // }
   // printf("\n");
		//printf("Would you like to save the file? (y/n)");
		//printf("What do you want to name the image file? (include the extension)");
	//int height = 0;
    	//int width = 0;
    	//char fileName[100];
    		//printf("What is the name of the image file? ");
    		//scanf("%s", fileName);

    		//FILE* filePtr;
    		//filePtr = fopen(fileName, "r");

    	//if (filePtr == NULL) {
        //fprintf(stderr, "Could not open file.");
       // return;
   // }
//case 6 Crop Image
void CropImage(int imageArray[80][80], int* height, int* width) {
 	int userInput = 0;
 	int newLeftColumn = 0;
 	int newRightColumn = 0;
 	int newTop = 0;
 	int newBottom = 0;
 		printf(" 1\n");
 		printf("1 ");
 
 	for (int i = 0; i < *height; i++) {
 	if(i != 0 && i < *height - 1){
 		printf(" ");
 	}
 	if (i == *height - 1) {
 		printf("%d", *height);
 	}
 		for (int j = 0; j < *width; j++) {
 	if(imageArray[i][j] == 0) {
 		printf(" ");
 	}
 	else if(imageArray[i][j] == 1){
 		printf(".");
 	}
 	else if(imageArray[i][j] == 2){
 	printf("o");
 	}
 	else if(imageArray[i][j] == 3){
 		printf("O");
 	}
 	else if(imageArray[i][j] == 4){
 		printf("0");
 	}
 	}
 	if(i == 0) {
 		printf(" %d", *width);
 	}
 		printf("\n");
 	}
 		printf("\n");
 		printf("The Image You Want To Crop Is: %d x %d \n", *height, *width);
 		printf("Which Column Is The New Left Side?\n");
 		scanf("%d", &userInput);
 	while(userInput >= *width){
 		printf("Out Of Bounds\n");
 		scanf("%d", &userInput);
	 }
 	newLeftColumn = userInput;
 		printf("Which Column Do You Want To Be The Right Left Side?\n");
 		scanf("%d", &userInput);
 	while(userInput >= *width && userInput <= newLeftColumn){
 		printf("Out Of Bounds\n");
	 	scanf("%d", &userInput);
 	}
 	newRightColumn = userInput;
 		printf("Which Row Do You Want To Be The New Top?\n");
 		scanf("%d", &userInput);
 	while(userInput >= *height && userInput <= 0){
 		printf("Out Of Bounds\n");
 		scanf("%d", &userInput);
 	}
 	newTop = userInput;
 		printf("Which Row Do You Want To Be The New Bottom?\n");
 		scanf("%d", &userInput);
 	while(userInput >= *height && userInput <= newTop){
 		printf("Out Of Bounds\n");
 		scanf("%d", &userInput);
 	}
 	newBottom = userInput;
 	char userSave = 't';
 		printf("Would You Like To Save The File? (y/n)\n");
 		scanf(" %c", &userSave);
 	if(userSave == 'y' || userSave == 'Y'){
 	char fileName[100];
 		printf("What do you want to name the image file?\n");
 		scanf("%s", fileName);
 	FILE* filePtr;
 	filePtr = fopen(fileName, "w");
 	if (filePtr == NULL) {
 		fprintf(stderr, "Could not open file.");	
 	}
 	for(int i = newTop; i < newBottom; i++){
 		for(int j = newLeftColumn; j < newRightColumn; j++){
 	fprintf(filePtr, "%d", imageArray[i][j]);
 	}
 	fprintf(filePtr, "\n");
 		}
 	fclose(filePtr);
 		printf("Image successfully saved!\n");
 	}
 	else if(userSave == 'n' || userSave == 'N') {
 		printf("Image Not Saved\n");
 	}
 	return;
}
	
	

	
			
