### 解题思路
![image.png](https://pic.leetcode-cn.com/2c4c563fbc51e0678a0b9e0238d0a978ceedde4d34c0aaa0553e8187a3a201cd-image.png)


### 代码

```c
int titleToNumber(char * s){
    int len = strlen(s);
    int i;
    int sum = 0;

    for(i = 0; i < len; i++) {
        sum *= 26;
        sum += (s[i] - 'A' + 1);
    }
    return sum;
}
```