#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct 
{
    uint16_t x;
    uint16_t y;
} Vec2;

int main()
{
FILE *input = fopen("wire_reading.txt", "r");

uint32_t edge_length = 30000;
uint32_t grid_size = edge_length * edge_length;
Goat *goats = malloc(sizeof(Goat) * 3);
uint16_t *map_one = malloc(sizeof(uint8_t) * grid_size);
uint16_t *map_two = malloc(sizeof(uint8_t) * grid_size);
uint16_t starting = edge_length/2;
Vec2 pos_one = 
{
    .x = starting, 
    .y = starting
};
Vec2 pos_two = 
{
    .x = starting, 
    .y = starting
};

uint16_t debug = 1;
uint16_t steps = 0;
uint8_t map = 1;
char read, direction;
memset(map_one,0,grid_size);
memset(map_two,0,grid_size);

// printf("GOOD\n");                       // testing
while((read = fgetc(input)) != EOF)
{
    if(read == 'U' || read == 'D' || read == 'R' || read == 'L'){direction = read;}
    else if(read == ',' || read == '\n')
    {
        printf("Steps: %c%d\n", direction,steps);
        if(read == '\n') {map++;}
    //    printf("STEPS: %d\n", steps);       // testing
        switch(map)
        {
            case 1:
            if(direction == 'U')
            {
                for(int i = 1; i <= steps; i++)
                {
                    size_t index = ((pos_one.y + i) * edge_length) + pos_one.x;
                    map_one[index] = 1;
                }
                pos_one.y += steps;
            }
            if(direction == 'D')
            {
                for(int i = 1; i <= steps; i++)
                {
                    map_one[x_y[0][0]][x_y[0][1] - i] = 1;
                }
                x_y[0][1] -= steps;
            }
            if(direction == 'R')
            {
                for(int i = 1; i <= steps; i++)
                {
                    map_one[x_y[0][0] + i][x_y[0][1]] = 1;
                }
                x_y[0][0] += steps;
            }
            if(direction == 'L')
            {
                for(int i = 1; i <= steps; i++)
                {
                    map_one[x_y[0][0] - i][x_y[0][1]] = 1;
                }
                x_y[0][0] -= steps;
            }
            steps = 0;
            // printf("Loop %d\n",debug++);            // testing
            break;

            case 2:
            if(direction == 'U')
            {
                for(int i = 1; i <= steps; i++)
                {
                    map_two[x_y[1][0]][x_y[1][1] + i] = 1;
                }
                x_y[1][1] += steps;
            }
            if(direction == 'D')
            {
                for(int i = 1; i <= steps; i++)
                {
                    map_two[x_y[1][0]][x_y[1][1] - i] = 1;
                }
                x_y[1][1] -= steps;
            }
            if(direction == 'R')
            {
                for(int i = 1; i <= steps; i++)
                {
                    map_two[x_y[1][0] + i][x_y[1][1]] = 1;
                }
                x_y[1][0] += steps;
            }
            if(direction == 'L')
            {
               //  printf("STEPS ON LEFT 2: %d\n", steps);     // testing
                for(int i = 1; i <= steps; i++)
                {
                    map_two[x_y[1][0] - i][x_y[1][1]] = 1;
                }
                x_y[1][0] -= steps;
            }
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
printf("Steps: %c%d\n", direction,steps);
if(direction == 'U')
{
    for(int i = 1; i <= steps; i++)
    {
        map_two[x_y[1][0]][x_y[1][1] + i] = 1;
    }
    x_y[1][1] += steps;
}
if(direction == 'D')
{
    for(int i = 1; i <= steps; i++)
    {
        map_two[x_y[1][0]][x_y[1][1] - i] = 1;
    }
    x_y[1][1] -= steps;
}
if(direction == 'R')
{
    for(int i = 1; i <= steps; i++)
    {
        map_two[x_y[1][0] + i][x_y[1][1]] = 1;
    }
    x_y[1][0] += steps;
}
if(direction == 'L')
{
    //  printf("STEPS ON LEFT 2: %d\n", steps);     // testing
    for(int i = 1; i <= steps; i++)
    {
        map_two[x_y[1][0] - i][x_y[1][1]] = 1;
    }
    x_y[1][0] -= steps;
}
fclose(input);

// done reading and mapping

// now finding closest intersection 

int16_t distance = 0;
int8_t loop = 1;

while(loop != 0){
    for(int i = 0; i < distance; i++)
    {
   //     printf("Map one: %d Map two: %d \n",map_one[starting + i][starting + distance - i], map_two[starting + i][starting + distance - i] );
        printf("\nCoordinates: %d,%d\n",starting + i, starting + distance - i);
        if(map_one[starting + i][starting + distance - i] == 1 && map_two[starting + i][starting + distance - i] == 1)
        {
            printf("\nDISTANCE!!!!!!: %d\n", distance);
            loop = 0;
        } 
    }
    if(loop == 0) break;
    for(int i = 0; i < distance; i++)
    {
        printf("Map one: %d Map two: %d \n",map_one[starting + distance - i][starting - i],map_two[starting + distance - i][starting - i] );
        printf("\nCoordinates: %d,%d\n", starting + distance - i, starting - i);
        if(map_one[starting + distance - i][starting - i] == 1 && map_two[starting + distance - i][starting - i] == 1) 
        {
            printf("\nDISTANCE!!!!!!: %d\n", distance);
            loop = 0;
            break;
        } 
    }
    if(loop == 0) break;
    for(int i = 0; i < distance; i++)
    {
   //     printf("Map one: %d Map two: %d \n",map_one[starting - i][starting - distance + i],map_two[starting - i][starting - distance + i]  );
          printf("\nCoordinates: %d,%d\n", starting - i, starting - distance + i);
        if(map_one[starting - i][starting - distance + i] == 1 && map_two[starting - i][starting - distance + i] == 1)
        {
            printf("\nDISTANCE!!!!!!: %d\n", distance);
            loop = 0;
            break;
        } 
    }
    if(loop == 0) break;
    for(int i = 0; i < distance; i++)
    {
     //   printf("Map one: %d Map two: %d \n", map_one[starting - distance + i][starting + i],  map_two[starting - distance + i][starting + i]);
        printf("\nCoordinates: %d,%d\n", starting - distance + i, starting + i);
        if(map_one[starting - distance + i][starting + i] == 1 && map_two[starting - distance + i][starting + i] == 1)
        {   
            printf("\nDISTANCE!!!!!!: %d\n", distance);
            loop = 0;
            break;
        } 
    }
    if(loop != 0) distance++;
}
printf("\nDistance: %d\n", distance);
}