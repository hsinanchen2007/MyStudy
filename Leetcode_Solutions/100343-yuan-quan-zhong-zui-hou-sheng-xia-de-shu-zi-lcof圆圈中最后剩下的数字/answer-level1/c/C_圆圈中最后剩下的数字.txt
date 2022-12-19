### 解题思路
还是不太明白递归的思路。链表费时间空间，但是好想

### 代码

```c
int lastRemaining(int n, int m){
    if (n == 1) return 0;
    return (m + lastRemaining(n-1, m)) % n;
}
```