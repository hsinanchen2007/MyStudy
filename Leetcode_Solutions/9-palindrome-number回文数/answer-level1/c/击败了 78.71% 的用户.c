### 解题思路
1. 将整型转化为字符串，设置两个指针，一个指向开始一个指向结束，依次遍历

### 代码

```c
bool isPalindrome(int x){
    char arr[512];
    char *pstart, *pend;
    int len;

    len = sprintf(arr, "%d", x);
    pstart = arr;
    pend = arr + len - 1;

    while (pstart < pend)
    {
        if (*pstart != *pend) return false;
        pstart++;
        pend--;
    }
    return true;
}
```