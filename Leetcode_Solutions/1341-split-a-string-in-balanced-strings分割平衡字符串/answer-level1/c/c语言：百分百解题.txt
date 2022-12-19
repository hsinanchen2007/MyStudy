### 解题思路
利用整型数组t记录字符数组s中的字符信息：
1. s[i] == 'R', t[i] = 1;
2. s[i] == 'L', t[i] = -1;
再将数组t[i]的值从头到尾加一遍，出现等于零，就得到一个题目要求的平衡字符串 
![surprise.png](https://pic.leetcode-cn.com/b7e297d0aefeffe535b29a474f01c00929cfe9a9bf98795b2482518ffa496cee-surprise.png)


### 代码

```c
int balancedStringSplit(char * s){
    int len = strlen(s);

    int* t = (int*)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++){
        if (s[i] == 'R')
            t[i] = 1;
        else
            t[i] = -1;
    }
    int sum = t[0], cnt = 0;
    for (int i = 1; i < len; i++){
        sum += t[i];
        if (sum == 0)
            cnt++;
    }
    return cnt;
}
```