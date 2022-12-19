### 解题思路
![image.png](https://pic.leetcode-cn.com/2b0fa33cb9a0c73328068b22be38545faab1522953a924905cda786759dc1519-image.png)

### 代码

```c
char * getHint(char * secret, char * guess){
    char* ret = (char*)malloc(sizeof(char) * 100);
    int A_num = 0, B_num = 0;
    int len = strlen(secret);
    int i;
    int* hash1 = (int*)malloc(sizeof(int) * 10);
    int* hash2 = (int*)malloc(sizeof(int) * 10);
    for(i = 0; i < 10; i++) {
        hash1[i] = 0;
        hash2[i] = 0;
    }

    for(i = 0; i < len; i++) {
        hash1[secret[i] - '0']++;
        hash2[guess[i] - '0']++;
    }
    for(i = 0; i < 10; i++) {
        B_num += fmin(hash1[i], hash2[i]);
    }

    for(i = 0; i < len; i++) {
        if(secret[i] == guess[i]) {
            A_num++;
        }
    }
    B_num = B_num - A_num;
    sprintf(ret, "%dA%dB", A_num, B_num);
    return ret; 
}
```