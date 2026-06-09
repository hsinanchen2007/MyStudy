### 解题思路
位运算 异或 执行用时 : 0 ms , 在所有 C 提交中击败了 100.00% 的用户 内存消耗 : 5.4 MB , 在所有 C 提交中击败了 100.00% 的用户
### 代码

```c
char findTheDifference(char * s, char * t){
    int sum = 0;
    while(*s){
        sum ^= (*s);
        s ++;
    }
    while(*t){
        sum ^= (*t);
        t ++;
    }

    return (char)sum;
}
```