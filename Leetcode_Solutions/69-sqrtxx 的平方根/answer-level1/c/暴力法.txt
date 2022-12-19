### 解题思路
此处撰写解题思路

### 代码

```c
int mySqrt(int x){
    long i;
for(i=1;i*i<=x;i++);
return i-1;
}
```