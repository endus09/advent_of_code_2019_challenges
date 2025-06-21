#include <stdio.h>
#include <stdint.h>

int main(){
    FILE *input = fopen("intcode.txt", "r");
    if(input == NULL) return 0;
    uint64_t nums[500] = {0};
    uint16_t i = 0;
    uint16_t j = 0;
    uint8_t end = 1;
    char read;

    while((read = fgetc(input)) != EOF){
        if(read != ','){
            nums[i] *= 10;
            nums[i] += read - '0';
        }
        else {
//      printf("%d ", nums[i]);       // checking if input is reading correctly
            i++;
        }
    }

    nums[1] = 12;
    nums[2] = 2;

    while(end != 0){
        if(nums[j] == 1){
            nums[nums[j+3]] = nums[nums[j+1]] + nums[nums[j+2]];
            j += 4;
           // printf("%d \n", nums[0]);     // testing
        }
        else if(nums[j] == 2){
            nums[nums[j+3]] = nums[nums[j+1]] * nums[nums[j+2]];
            j += 4;
           // printf("%d \n", nums[0]);     // testing
        }
        else end = 0;
    }

    printf("answer: %d", nums[0]);

    fclose(input);
    return 0;
}