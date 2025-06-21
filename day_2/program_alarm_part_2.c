#include <stdio.h>
#include <stdint.h>

int main(){
    FILE *input = fopen("intcode.txt", "r");
    if(input == NULL) return 0;
    uint64_t nums[500] = {0};
    uint64_t run[500] = {0};
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
    fclose(input);
    


        for (int a = 0; a <= 99; a++)
        {
            for (int b = 0; b <= 99; b++)
            {
                for (int c = 0; c < 500; c++)
                {
                    run[c] = nums[c];
                }
                run[1] = a;
                run[2] = b;
                j = 0;
                end = 1; 
                while(end != 0)
                {
                if(run[j] == 1){
                    run[run[j+3]] = run[run[j+1]] + run[run[j+2]];
                    j += 4;
                   //  printf("%d \n", run[0]);     // testing
        }
                else if(run[j] == 2){
                    run[run[j+3]] = run[run[j+1]] * run[run[j+2]];
                    j += 4;
                   //  printf("%d \n", run[0]);     // testing
        }
                else end = 0;
                }
                if(run[0] == 19690720) break;
            }
                if(run[0] == 19690720) break;
        }
    printf("Zero Val: %d\n", run[0]);
    printf("Values: \n1: %d \n2: %d\n", run[1], run[2]);
    printf("Answer: %d%d\n", run[1], run[2]);
    
    return 0;
}