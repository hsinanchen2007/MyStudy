### 解题思路
1.每次都对x取余数，并x/=10，当x==0时，个位数正好×了10的x位数-1次方，十位数×了10^x位数-2次方，依此类推。
2.long类型是为了防止逆置的时候超出Integer的最大值。最后需要强转一下，因为输入的是int类型，所以不用担心转换丢失精度
3.输入负数的情况：x%10默认保留x前的符号。所以也不用担心,符号总会是对的
### 代码

```java
class Solution {
  public int reverse(int x) {
        long count=0;
    while(x!=0){
        count=count*10+x%10;
        x=x/10;
    }
    return (count>2147483647 || count<-2147483648) ? 0 : (int)count;
    
  }
    
}
```