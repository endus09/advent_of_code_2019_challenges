#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
FILE *input = fopen("wire_reading.txt", "r");

uint32_t grid_size = 10000;
uint16_t **map_one = malloc(sizeof(uint16_t *) * grid_size);
uint16_t **map_two = malloc(sizeof(uint16_t *) * grid_size);
uint16_t steps = 0;
uint8_t map = 1;
char read, direction;

for(int i = 0; i < grid_size; i++)
{
    map_one[i] = malloc(sizeof(uint16_t) * grid_size);
    map_two[i] = malloc(sizeof(uint16_t) * grid_size);
}

for(int i = 0; i < grid_size; i++){
    for(int j = 0; j < grid_size; j++){
        map_one[i][j] = 0;
        map_two[i][j] = 0;
}
}

while((read = fgetc(input)) != EOF)
{
    if(read == 'U' || read == 'D' || read == 'R' || read == 'L') direction = read;
    else if (read == '\n') map++;
    else if(read == ',')
    {
        switch(map)
        {
            case 1:
            
            steps = 0;
            break;
            case 2:

            steps = 0;
            break;
            default:
            printf("ERROR");
            break;
        } 
    }
    else
    {
        steps *= 10;
        steps += read - '0';
    }
}

fclose(input);
}