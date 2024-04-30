//Subject:Image
//Author:Louis w Pierce lll/Isaiah Marzan
//Date:4-29-24
	
#include <stdio.h>
#define FILENAME "currentimage.txt"
 void displayImage(FILE* out);
 int greyScale(int rec1,int rec2);
 int edit(int chg1,int chg2);
 
 int main(){
 	double height,width;
 	int rec1,rec2,dis,chg1,chg2;
 	char i;
	FILE* fptr;
 	int images[1];
 		printf("Pick image to load, display, and edit.\n");
									
 	for(int i = 0; i < 1; i++){
 		printf("(1)Load Image\n");
 		printf("(2)Display Image\n");
 		printf("(3)Edit Image\n");
 		printf("(4)Exit\n");
 		scanf("%d", &images[i]);
 	}
	for(int i = 0; i < 1; i++ ) {
		switch (images[i]){
	 		case 1:
	 			printf("\n");
	 			printf("Load greyscale image: ");
	 			scanf("%d", &rec1);
	 			
	 			height = rec1;
				width = rec2;
	 			printf("The height %.2f and the width %.2f of the image.\n ", height, width);
				
	 		break;
	 		case 2:
	 			printf("\n");
	 			printf("Select file image to load: ");
	 			scanf("%d", &dis);
	 			fptr = fopen(FILENAME, "w");
			if(fptr == NULL){
				printf("Cannot open file. Exiting program. \n");
	 			height = dis;
	 			width = dis;
	 			printf("The height %.2f and the width %.2f of the image.\n ", height, width);
	 			displayImage(fptr);
				fclose(fptr);
			}
	 		break;
	 		case 3:
	 			printf("\n");
	 			printf("Enter height between (1-600): ");
	 			scanf("%d", &chg1);
	 			printf("Enter height between (1-600): ");
	 			scanf("%d", &chg2);
	 			height = chg1;
	 			width = chg2;
	 			printf("The height %.2f and the width %.2f of the image.\n ", height, width);
		
			
	 		break;	
	 		case 4:
	 			return 0;
	 		default:
	 			printf("The picture you have loaded or modified needs to be reloaded!");
	 		break;
	 	}
	}
	return 0;
}

//case 1 Load image
int greyScale(int rec1,int rec2){
	int height, width;
	height = rec1;
	width = rec2;
	return height;
}
			
//case 2 Display image
void displayImage(FILE* out){
	int height, width;
	height = 0;
	width = 0;	
}
			
			
//case 3 Edit image
int edit(int chg1,int chg2){
	int height, width;
	height = chg1;
	width = chg2;			
	return height;
}
		
			
