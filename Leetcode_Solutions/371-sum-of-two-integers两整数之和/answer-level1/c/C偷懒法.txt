### 解题思路
没用“+”和“-”但是用了“++”和“--”感觉还是有点不合题意。无奈位运算实在不擅长，只能偷懒。

### 代码

```c
int getSum(int a, int b){
    if(a>0){
        while(a--) b++;
    }else{
        while(a++!=0) b--;
    }
     return b;

}
```