
### 代码

```c
int sumNums(int n) {
    int tmp=0;
    (n-1!=0)&&(bool)(tmp=sumNums(n-1));
    return tmp+n;
}
```