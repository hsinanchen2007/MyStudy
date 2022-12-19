### 解题思路
回溯算法，关键在这个地方
int len0 = strlen(arr[index]) + DFS(arr, index + 1, t, arrSize);
int len1 = DFS(arr, index + 1, used, arrSize);

以及怎么记录字母是否重复

### 代码

bool isRepeat(char *s, bool used[]) {
    for (int i = 0; i < strlen(s); i++){
        if (!used[s[i]])
             used[s[i]] = true;
        else
            return true;
    }
    return false;
}

int DFS(char ** arr, int index, bool used[], int arrSize) {
    if (arrSize == index)
        return 0;

    bool t[128] = {false};
    memcpy(t, used, 128);
    
    if (!isRepeat(arr[index], t)) {
        int len0 = strlen(arr[index]) + DFS(arr, index + 1, t, arrSize);
        int len1 = DFS(arr, index + 1, used, arrSize);

        if (len0 > len1)
            return len0;
        else
            return len1;        
    }
    
    return DFS(arr, index + 1, used, arrSize);
}

int maxLength(char ** arr, int arrSize){
    bool used[128] = {false};
    return DFS(arr, 0, used, arrSize);
}

```