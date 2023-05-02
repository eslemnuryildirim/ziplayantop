#include<stdio.h>
#include <stdlib.h>
#include <time.h>

float calculate_the_new_height(float height , float ratio){
	float new_height = height * ratio;
	return new_height;
}
float calculate_the_vertical_distance(float height, int count){
	float distance= 0.0;
	for (int i = 0; i<count; i++){
		distance += height;
		height= calculate_the_new_height(height, 0.4 +((float) rand()/ RAND_MAX) * 0.4);
		if (height < 1.0){
			break;
		}
	}
	return distance;
}
int count_the_number(float height){
	int count = 0;
	while (height >= 1.0){
		height = calculate_the_new_height(height,0.4 +((float) rand() / RAND_MAX) * 0.4);
		count++;
	}
	return count;
}

int main() {
    srand(time(NULL));
    float first_height = (float) (rand() % 31 + 10);
    float ratio = 0.4 + ((float) rand() / RAND_MAX) * 0.4;
    float total_distance = calculate_the_vertical_distance(first_height, count_the_number(first_height));
    int total_jumps = count_the_number(first_height);
    
    FILE *fp;
    fp = fopen("results.txt", "w");
    fprintf(fp, "First Height: %.2f feet\n", first_height);
    fprintf(fp, "Ratio: %.2f\n", ratio);
    fprintf(fp, "Total Jumps: %d\n", total_jumps);
    fprintf(fp, "Total Vertical Distance: %.2f feet\n", total_distance);
    fclose(fp);
}