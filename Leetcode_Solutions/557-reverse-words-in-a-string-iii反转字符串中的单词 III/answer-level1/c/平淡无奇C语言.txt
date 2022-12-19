### 解题思路
![image.png](https://pic.leetcode-cn.com/e097b8d7c3cf5df9d85687004a250f48d3bf1fdc6e659c1915c19473304c5c46-image.png)


### 代码

```c
char * reverseWords(char * s){
    int i, j;
    int len = strlen(s);
    int size = -1;
    int locate = 0;
    char temp;

    for(i = 0; i < len; i++) {
        size++;
        if(s[i] == ' ') {
            for(j = 0; j < size / 2; j++) {
                temp = s[locate + j];
                s[locate + j] = s[locate + size - j - 1];
                s[locate + size - j - 1] = temp;
            }
            printf("%d ", size);
            size = -1;
            locate = i + 1;
        }
    }
    for(j = 0 ; j < (len - locate) / 2; j++) {
        temp = s[locate + j];
        s[locate + j] = s[len - j - 1];
        s[len - j - 1] = temp;
    }
    return s;
}
```