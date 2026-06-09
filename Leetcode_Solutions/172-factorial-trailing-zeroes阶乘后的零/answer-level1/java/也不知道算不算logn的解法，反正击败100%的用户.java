### 解题思路
隐藏的坑啊！！！！！！！！！！
注意啊 for循环里面务必用long，否则会发生溢出而计算错误。
### 代码

```java
class Solution {
    public int trailingZeroes(int n) {
        int sum=0;
        for(long i=5;;i*=5){
            if(n/i==0)
                break;
            sum+=n/i;
        }
        return sum;
    }
}
```