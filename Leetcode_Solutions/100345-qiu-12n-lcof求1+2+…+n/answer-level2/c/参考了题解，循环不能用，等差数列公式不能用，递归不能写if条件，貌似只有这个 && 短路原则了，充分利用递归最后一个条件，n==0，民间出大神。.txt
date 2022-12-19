### 解题思路
此处撰写解题思路

### 代码

```c
int sumNums(int n){
    int res = n;

    res && (res += sumNums(n - 1));
    return res;
}
```