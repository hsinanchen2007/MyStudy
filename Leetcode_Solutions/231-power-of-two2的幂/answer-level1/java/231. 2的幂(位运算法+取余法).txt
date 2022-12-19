### 解题思路
可用使用位运算法，或者取余法来进行

### 位运算法
关键在于n的二进制数只能有1个1，如果有不止1个就一定不是2的幂
主要步骤：
1.拿数<1都去除
2.增加计数器=0
3.只要不为0就循环，由于每次循环都右移所以不会死循环。
4.和1位与运算，如果=1说明该位为1，计数。
5.判断计数器>1则返回false

```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n<1)return false;
        int count=0;
        while(n!=0){
            if((n&1)==1){
                count++;
            }
            if(count>1){
                return false;
            }
            n=n>>1;
        }
        return true;
    }
}
```
### 取余法
关键在于2的0次幂=1，只要是2的次幂不断除2最后的结果一定是1，如果不是1就返回false
```
class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n==0)return false;
        while((n%2)==0){
            n/=2;
        }
        return n==1?true:false;
    }
}
```
