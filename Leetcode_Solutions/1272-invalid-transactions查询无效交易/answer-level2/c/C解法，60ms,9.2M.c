**思路**
搞个结构体填写好了，再慢慢比较。
```

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    char name[11];
    int time;
    int amount;
    char city[11];
}INFO;

int char2int(char *chr, int charLen) 
{
    int output = chr[0] - '0';
    for (int i = 1; i < charLen; i++) {
        output *= 10;
        output += (chr[i] - '0');
    }
    return output;
}

char ** invalidTransactions(char ** transactions, int transactionsSize, int* returnSize){
    INFO *info;
    info = (INFO *)malloc(transactionsSize * sizeof(INFO));
    int outIdx[1000] = {0};

    int k = 0;
    for (int i = 0; i < transactionsSize; i++) {
        int totalLen = strlen(transactions[i]);
        int nameLen;
        int timeLen;
        int amountLen;
        int p = 0;
        int cnt = 0;
        while (transactions[i][p] != '\0') {
            if (transactions[i][p] == ',') {
                cnt++;            
            if (cnt == 1) {
                nameLen = p;
            } else if (cnt == 2) {
                timeLen = p;
            } else if (cnt == 3) {
                amountLen = p;
            }
            }
            p++;
        }
        memcpy(info[i].name, transactions[i], nameLen);
        info[i].name[nameLen] = '\0';
        info[i].time = char2int(transactions[i] + nameLen + 1, timeLen - nameLen - 1);
        info[i].amount = char2int(transactions[i] + timeLen + 1, amountLen - timeLen - 1);
        memcpy(info[i].city, transactions[i] + amountLen + 1, totalLen - amountLen - 1);
        info[i].city[totalLen - amountLen - 1] = '\0';
        
        for (int j = 0; j < i; j++) {
            if (strcmp(info[i].name, info[j].name) == 0) {
                if (strcmp(info[i].city, info[j].city) != 0) {
                    if (abs(info[i].time - info[j].time) <= 60) {
                        outIdx[i]++;
                        outIdx[j]++;                        
                    }
                }
            }
        }        
        if (info[i].amount > 1000) {
            outIdx[i]++;
        }
        //printf("%s %d %d %s \n", info[i].name, info[i].time, info[i].amount, info[i].city);        
    }
    
    char **output = (char **)malloc(transactionsSize * sizeof(char *));
    int j = 0;
    for (int i = 0; i < transactionsSize; i++) {
        if (outIdx[i]) {
            output[j] = transactions[i];
            j++;
        }
    }
    *returnSize = j;
    return output;
}


```
