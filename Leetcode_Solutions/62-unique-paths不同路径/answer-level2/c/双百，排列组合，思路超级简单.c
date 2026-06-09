### 解题思路
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :5.1 MB, 在所有 C 提交中击败了100.00%的用户
//总共向右走m-1次，向下走n-1次。其实就是有m-1个A 有n-1个B,有多少种排列方式。比如又5个A，2个B。 = c72（数学符号不会打，7为下标2为上标）
// 有m行n列 =c（m+n-2,n-1）==c（m+n-2,m-1）

### 代码

```c


int cmn(int m ,int n)
{
    long int ret =1;
    for(int i=1;i<=n;i++){
        ret *=(m-i+1);
        ret /=i;
    }
    return ret;
}
int uniquePaths(int m, int n){
    int ret = 0;
    if((n <=1)||(m<=1))
        return 1;
    if(n<m)
        ret =cmn(m+n-2 ,n-1);//选计算方式少的一种
    else    
        ret =cmn(m+n-2 ,m-1); 
    return ret ;
}

```