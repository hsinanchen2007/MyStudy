int cmp(const int *a, const int *b){
    return *(int *)a - *(int *)b;
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    int * gap = (int *)malloc(sizeof(int)*costsSize);
    int numA = 0;
    int numB = 0;
    int sideA;
    int sideB;
    int sum = 0;
    int temp;
    int mid = costsSize/2;
    for (int i = 0; i < costsSize; i++){
        gap[i] = costs[i][0] - costs[i][1];
    }
    qsort(gap,costsSize,sizeof(int),cmp);
    sideA = gap[mid - 1];
    sideB = gap[mid];
    for (int i = 0; i < costsSize; i++){
        temp = costs[i][0] - costs[i][1];
        if (temp < sideA){
            sum += costs[i][0];
            numA++;
        } else if (temp > sideB){
            sum += costs[i][1];
            numB++;
        } 
    }
    for (int i = 0; i < costsSize; i++){
        temp = costs[i][0] - costs[i][1];
        if (temp == sideA){
            if (numA < mid){
                sum += costs[i][0];
                numA++;
            } else {
                sum += costs[i][1];
                numB++;
            }
        } else if (temp == sideB) {
            if (numB < mid){
                sum += costs[i][1];
                numB++;
            } else {
                sum += costs[i][0];
                numA++;
            }
        }
    }
    return sum;
}