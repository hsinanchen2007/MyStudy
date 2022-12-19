### 解题思路
解题思路详见公众号
![gzh.jpg](https://pic.leetcode-cn.com/57d1906e21951ada9f1bf4688b4306290048f7e92e9405677c50f2c3bec6531a-gzh.jpg)

### 代码

```java
class Solution {
    public int fib(int n) {
        Long result = Long.valueOf(0); //int类型在n=47时结果会溢出 所以用Long类型变量
        Long num1 = Long.valueOf(0);   //定义一个指针，用来指示待计算的加数之一
        Long num2 = Long.valueOf(1);   //定义一个指针，用来指示待计算的加数之一
        int sum = 0 ;
        for(int i=0;i<=n;i++){
            if(i == 0 ){
                sum = 0;
            }else if( i == 1){
                sum = 1;
            }else{
                    result = (num1 + num2) % 1000000007 ;  //取模
                    sum = new Long(result).intValue();  //将值赋给最终结果
                    num1 = num2;      //将第一个加数向后移一位
                    num2 = result;    //将结果赋给第二个变量 
            }
        }
        return sum;
    }
}
```