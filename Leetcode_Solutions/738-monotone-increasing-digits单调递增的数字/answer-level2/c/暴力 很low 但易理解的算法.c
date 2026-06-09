### 解题思路
![1.png](https://pic.leetcode-cn.com/1c8d182c284ee5c1423ab78760cd71eed2473a034084ffb2dccb5dc8d9f38f38-1.png)

害 暴力就完事了 很low 仅供参考

总体思路是：
1,将整型转成整型数组
2,从后往前遍历，对整型数组的每一位进行处理。
  若当前位i的值小于i-1位的值，则将此两位的值都重新赋值。详细见代码注释
3,将整型数组转化为整型数。

### 代码

```c
int monotoneIncreasingDigits(int N){
//1,将int类型N转化为int[]类型的digits
    int len = 0;
    int a = N;
    while(a){
        len++;
        a/=10;
    }
    if(len == 1) return N;
    a = N;
    int digits[10] = {0};       //N最大为10^9 因此申请数组长度为10
    for(int i=len-1; i>=0; i--){
        digits[i] = a%10 ;
        a/=10;
    }
//2,从末位开始遍历 若前一位的数字比当前位大 则将前一位-1 末位变为9
    for(int i=len-1; i>0; i--){
        if(digits[i-1]>digits[i]){
            if(digits[i-1]==0){}        //若前一位等于0，先暂时不处理(for循环执行完之后再处理)
            else digits[i-1]--;         //若前一位大于0，则将其减一
            digits[i] = 9;              //当前位置为9
        }
    }
    //若从某一位开始为9，则后面每一位全置为9
    int index = 0;
    while(index<len && digits[index]!=9) index++;   //先找第一个为9的下标index
    for(int i=index+1; i<len; i++) digits[i] = 9;   //从index+1开始后面每一位都置为9
//3,再将int[]类型的digits转化为int类型的res并返回
    int res = 0;
    int i=0;
    while(digits[i] == 0) i++;      //i指向第一位不为0的值
    for(; i<len; i++){
        res = res*10 + digits[i] ;
    }

    return res;
}
```