//Subject:Image
//Author:Louis w Pierce lll and Isaiah Marzan
//Date:4-29-24
	
#include <stdio.h>
 
 int greyScale(int rec1,int rec2);
 
 int disPlay(int a,int b);
 
 int edit(int chg1,int chg2);
 
 //cropImage function here
 
 //dimImage function here
 
 //brightenImage function here
 
 int main(){
 	double height, width;
 	int rec1,rec2,dis,chg1,chg2;
 	char i;

 	int images[1];
 		printf("Pick image to load, display, and edit.\n");
									
 	for(int i = 0; i < 1; i++){
 		printf("(1)Load Image");
 		printf("(2)Display Image");
 		printf("(3)Edit Image\n");
 		scanf("%d", &images[i]);
 	}
		for(int i = 0; i < 1; i++ ) {
 		switch (images[i])
 	{
 		case 1:
 				printf("\n");
 			printf("Load greyscale image: ");
 			scanf("%d", &rec1, &rec2);
 			
 			height = rec1;
			width = rec2;
 			printf("The height %.2f and the width %.2f of the image.\n ", height,width);
			
 		break;
 		case 2:
 			printf("\n");
 			printf("Select file image to load: ");
 			scanf("%d", &dis);
 			height = dis;
 			width = dis;
 			printf("The height %.2f and the width %.2f of the image.\n ", height,width);

 		break;
 		case 3:
 			printf("\n");
 			printf("Enter height between (1-600): ");
 			scanf("%d", &chg1);
 			printf("Enter height between (1-600): ");
 			scanf("%d", &chg2);
 			height = chg1;
 			width = chg2;
 			printf("The height %.2f and the width %.2f of the image.\n ", height,width);

		
 		break;
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
			
		return height,width;
		}
			
		//case 2 Display image
			int disPlay(int a,int b){
			int height, width;
				height = a;
				width = b;
				
		return height,width;
		}
			
			
 		//case 3 Edit image
 			int edit(int chg1,int chg2){
 			int height, width, userOption;
				height = chg1;
				width = chg2;
				
			printf("(1)Load Image\n");
 			printf("(2)Display Image\n");
 			printf("(3)Edit Image\n");
			printf("Choose an option: ");
			scanf(" %c", &userOption);
			
				
		return height,width;
		}
		
			//cropImage function here
			
			//dimImage function here
			
			//brightenImage function here
