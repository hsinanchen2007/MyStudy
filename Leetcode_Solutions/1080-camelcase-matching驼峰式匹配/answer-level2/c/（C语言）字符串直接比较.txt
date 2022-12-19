思路：query中的字符串和pattern逐个字母比较，如果不行同的十大写字母，返回false，如果是小写字母，继续跳过比较
bool* camelMatch(char ** queries, int queriesSize, char * pattern, int* returnSize){
    int count = 0;
    bool* res = (bool*)malloc(sizeof(bool) * queriesSize);

    int j, k;
    int len = strlen(pattern);
    int len1 = 0;
    for (int i = 0; i < queriesSize; i++) {
        j = 0;
        k = 0;
        len1 = strlen(queries[i]);
        while (j < len1) {
            if (queries[i][j] == pattern[k]) {
                j++;
                k++;
                continue;
            }
            // 如果是大写字母退出循环，小写字母跳过继续比较
            if (isupper(queries[i][j])) {
                break;
            }
            j++;
        }
        if ((j < len1) || (k < len))
            res[count++] = false;
        else
            res[count++] = true;
    }

    *returnSize = count;
    return res;
}