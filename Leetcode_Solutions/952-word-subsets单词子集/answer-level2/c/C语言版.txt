### 解题思路
此处撰写解题思路

### 代码

```c
bool isInside(int* a, char* b);
char** wordSubsets(char** A, int ASize, char** B, int BSize, int* returnSize)
{
    char** result = (char**)malloc(10000 * sizeof(char*));
    *returnSize = 0;

    // merge B
    int data[128] = {0};
    for (int i = 0; i < BSize; i++) {
        int tmp[128] = {0};
        for (int j = 0; j < strlen(B[i]); j++) {
            tmp[B[i][j]]++;
            if (data[B[i][j]] < tmp[B[i][j]])
                data[B[i][j]] = tmp[B[i][j]];
        }
    }
    int sum = 0;
    for (int i = 0; i < 128; i++)
        sum += data[i];
    char* newB = (char*)malloc((sum + 1) * sizeof(char));
    int count = 0;
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < data[i]; j++) {
            newB[count++] = (char)i;
        }
    }
    newB[count] = '\0';

    for (int i = 0; i < ASize; i++) {
        bool flag = true;
        int dataA[128] = {0};
        char* a = A[i];
        for (int i = 0; i < strlen(a); i++) {
            dataA[*(a + i)]++;
        }
        flag = isInside(dataA, newB);
        if (flag == true) {
            result[*returnSize] = (char*)malloc((strlen(A[i]) + 1) * sizeof(char));
            memcpy(result[*returnSize], A[i], strlen(A[i]) + 1);
            (*returnSize)++;
        }
    }

    return result;
}

bool isInside(int* data, char* b)
{
    for (int i = 0; i < strlen(b); i++) {
        if (data[*(b + i)] == 0) {
            return false;
        } else {
            data[*(b + i)]--;
        }
    }

    return true;
}

```