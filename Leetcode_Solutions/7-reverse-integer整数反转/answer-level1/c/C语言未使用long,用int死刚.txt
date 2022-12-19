### 解题思路
直接采用int，外加判断实现逆序和错误处理。
> 执行用时 :4 ms, 在所有 C 提交中击败了76.82%的用户.
> 内存消耗 :5.2 MB, 在所有 C 提交中击败了100.00%的用户

菜鸡上手被血虐，如有问题和优化，望各位大佬指出。

### 代码

```c
int reverse(int inNum){
int reverse(int inNum){
    int temp,isError,isMinus = 0, outNum = 0;
    if(inNum==-2147483648)  return 0;   //复数最小值取绝对值时会溢出，直接逆序也会溢出，直接返回0。
    if(inNum<0){
        inNum = abs(inNum);
        isMinus = 1;    //判断正负。
    }
    for(temp=inNum; temp>9; temp/=10){
        outNum = (temp%10 + outNum) ;   //与if判断之后的步骤实现逆序。
        if(temp/10>7 && outNum>214748364){    //当运算到第9位时，判断第十位是否存在并大于7，接着判断前九位*10后是否溢出，
            return 0;
        }
        outNum *= 10;
    }
    outNum += temp;
    if(isMinus) outNum = -outNum;  
    return outNum;
}
```