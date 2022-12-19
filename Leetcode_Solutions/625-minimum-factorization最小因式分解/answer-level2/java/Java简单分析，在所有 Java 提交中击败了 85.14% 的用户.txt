### 解题思路
此处撰写解题思路
思路很简单：
因为是需要各个位数相乘，所以除数只需要考虑2~9 ，一共8个数；
然后从大的开始除法运算，也很简单，比如如果能被8整数，那肯定就往最终结果添加一个8，而不是222或者42或者24；
同理如果能被9整除肯定直接除以9而不是除以3再除以3；
从大的整除也就把大的单位数尽量往后面靠，比如29肯定比92小。

### 代码

```java
class Solution {
    public int smallestFactorization(int a) {
        if(a==1||a==0) return a;
        long res = 0;
        for(int i = 9; i >=2;i--){
            while( a%i==0 && a>1){
                res = res*10+i;
                a/=i;
            }           
        }
        StringBuilder sb = new StringBuilder();
        sb.append(res);
        sb.reverse();
        res = Long.parseLong(sb.toString());//需要反转
        return a==1&&res<=Integer.MAX_VALUE?(int)res:0;
    }
}
```