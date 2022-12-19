int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize){
    int map[9][9] = {0};
    int sum = 0;
    int i;
    for (i = 0; i < dominoesSize; i++) {
        map[dominoes[i][0]-1][dominoes[i][1]-1]++;
    }
    for (i = 0; i < 9; i++) {
        for (int j = i; j < 9; j++) {
            if (i == j) {
                sum += (map[i][j] * (map[i][j] - 1))/2; //对角线0°
            }
            else {
                sum += ((map[i][j] * (map[i][j] - 1))/2 + (map[j][i] * (map[j][i] - 1))/2); //0°
                sum += map[i][j]*map[j][i];  //180°
            }
        }
    }
    return sum;
}