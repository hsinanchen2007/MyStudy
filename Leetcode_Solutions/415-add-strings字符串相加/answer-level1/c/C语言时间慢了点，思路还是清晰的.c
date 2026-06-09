### 解题思路
![image.png](https://pic.leetcode-cn.com/b4a7e2e2ebdc800a930d61c4c366a8f06d15c597b4e463de66892027e3d37fd5-image.png)


### 代码

```c
void reverseString(char* s, int sSize){
    char temp;
    for(int i = 0; i < sSize / 2; i++) {
        temp = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = temp;
    }
    return;
}
char * addStrings(char * num1, char * num2){
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    reverseString(num1, len1);
    reverseString(num2, len2);
    int add = 0;
    char* ret = (char*)malloc(sizeof(char) * (fmax(len1, len2) + 2));
    int i;
    int n1, n2, sum;

    for(i = 0; i < fmax(len1, len2); i++) {
        n1 = i < len1 ? num1[i] - '0' : 0;
        n2 = i < len2 ? num2[i] - '0' : 0;
        sum = (n1 + n2 + add) % 10;
        add = (n1 + n2 + add) / 10;
        sprintf(ret + i, "%d", sum); 
        printf("n1=%d, n2=%d, sum=%d,add=%d\n",n1,n2,sum,add);    
    }
    if(add) {
        sprintf(ret + i, "%d", add); 
        reverseString(ret, (fmax(len1, len2) + 1));
    } else {
        reverseString(ret, fmax(len1, len2));
    }
    return ret;
}
```