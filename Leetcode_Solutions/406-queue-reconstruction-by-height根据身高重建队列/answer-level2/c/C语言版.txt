int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){


    *returnColumnSizes = (int *)malloc(peopleSize*sizeof(int));
    int** output = (int **)malloc(peopleSize*sizeof(int *));

    int i,j;
    *returnSize = peopleSize;
    for (i = 0; i < peopleSize; i++) {
        (*returnColumnSizes)[i] = 2;
        output[i] = (int *)malloc(sizeof(int)*2);
        output[i][0] = 0;
        output[i][1] = 0;
    }

    for (i = 0; i < peopleSize; i++) {
        for (j = i; j < peopleSize; j++) {
            int *temp;
            if (people[i][0] < people[j][0]) {
                temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }

            if (people[i][0] == people[j][0] && people[i][1] > people[j][1]) {
                temp = people[i];
                people[i] = people[j];
                people[j] = temp; 
            }
        }
    }
    
    for (i = 0; i < peopleSize; i++) {
        int temp1 = people[i][1];
        for (j = i; j > temp1; j--) {
            output[j][0] = output[j-1][0];
            output[j][1] = output[j-1][1];
        }
        output[temp1][0] = people[i][0];
        output[temp1][1] = people[i][1];
    }

 
    return output;  
}