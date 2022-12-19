记录每个人被信任和信任的次数
int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    int numTrust[1000] = {0};
    int numTrusted[1000] = {0};
    for (int i = 0; i < trustSize; i++){
        numTrust[trust[i][0] - 1] += 1;
        numTrusted[trust[i][1] - 1] += 1;
    }
    for (int i = 0; i < N; i++){
        if (numTrusted[i] == (N - 1)) {
            if (numTrust[i] == 0){
                return i + 1;
            }
        }
    }
    return -1;
}