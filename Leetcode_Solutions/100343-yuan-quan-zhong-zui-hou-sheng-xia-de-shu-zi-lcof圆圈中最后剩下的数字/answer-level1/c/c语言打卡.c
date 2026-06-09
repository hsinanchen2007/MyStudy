### 解题思路
此处撰写解题思路

### 代码

```c
int lastRemaining(int n, int m){
    int i, index = 0;
    for(i = 1;i <= n;i ++)
        index = (index + m) % i;
    return index;
}
```