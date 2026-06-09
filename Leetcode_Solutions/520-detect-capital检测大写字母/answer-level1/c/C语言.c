### 解题思路

![image.png](https://pic.leetcode-cn.com/0a7d86a04175ee7814b453f972dc883114d0346cea32f743c490e9706ed1060c-image.png)

### 代码

```c
bool detectCapitalUse(char * word){
    int head = isupper(word[0]) ? 1 : 0;
    if (strlen(word) == 1) {
        return true;
    }

    int i;
    int flag = 0;
    for (i = 1; i < strlen(word); i++) {
        flag += isupper(word[i]) ? 1 : 0;
        if (head == 0 && flag != 0) {
                return false;
        }
        if (head == 1 && flag != 0 && flag < i) {
            return false;
        }
    }

    return true;
}
```