//Subject:Image
//Author:Louis w Pierce lll/Isaiah Marzan
//Date:4-29-24
	
#include <stdio.h>


void DisplayImage(int** imageArray);
void LoadImage(int** imageArray);
int edit(int chg1,int chg2);

int main() {
	int height, width, choice, change;
	
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
    int** imageArray;
		switch (choice) {
         case 1:
            LoadImage(imageArray);
            break;
         case 2:
            DisplayImage(imageArray);           
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
	
	}	while (choice !=4);
	
	return 0;
}

//case 1 Load image
void LoadImage(int** imageArray) {
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
    int height = 0;
    int width = 0;
    char line[100];
    while (fgets(line, sizeof(line), filePtr)) {
        height++;
        int i = 0;
        while (line[i] != '\0') {
            if (line[i] != ' ' && line[i] != '\n') {
                width++;
            }
            i++;
        }
    
		for (int i = 0; i < height; i++) {
    
    			for (int j= 0; j < width; j++) {
    	
    				fscanf (filePtr,"%d", &imageArray[i][j]);
    		
    			}
    	
    		}
    
    }

    
    
    fclose(filePtr);
}
			
//case 2 Display image
void DisplayImage(int** imageArray){
    for(int j = 0; j < sizeof(imageArray); j++){
        for (int i = 0; i < sizeof(imageArray[0]); i++){
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
    }
}
					
	
			
//case 3 Edit image
int edit(int chg1){

	printf("	**EDITING** \n");
	printf("1: Crop image\n");
	printf("2: Dim image\n");
	printf("3: Brighten image\n");
	printf("0: Return to main menu\n");
	
	switch (change) {
         case 1:
            CropImage();
            break;
         case 2:
            DimImage();           
            break;
	 case 3:
            BrightenImage();
            break;
	 case 4:
            Return();
            break;
	 default:
	 printf("The picture you have loaded or modified needs to be reloaded!");
	 		break;
	 	
	}	
	
	
	printf("Choose from one of the options above: "); 





	int height, width;
	height = chg1;
	width = chg2;
	
	
	
	printf("The image you want to crop is %d", &DisplayImage);
	printf("The row and column values start in the upper lefthand corner.");			
	return height;
}

	
			
