### 解题思路
方法一的思路，就是看最后一个0前面有单数 还是双数个1。

方法二是 从头到尾数，每遇到1，计算器就加2，如果最后的0不在这个1的覆盖范围，就代表这个0是1比特。

方法二的执行用时要38ms

两种方法都没什么技巧，靠的是对题目的分析

### 代码
方法一：
```java

class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int len = bits.length;
        int count = 0;
        for(int i = len - 2; i >= 0; i--){
            if(bits[i] == 1){
                count++;
            } else{
                break;
            }
        }
        return count % 2 == 0 ? true : false;
    }
}
```
方法二：
```java
class Solution {
    public boolean isOneBitCharacter(int[] bits) {

        int len = bits.length;
        for(int i = 0; i < len; i++){
            if(bits[i] == 1){
                i++;
                continue;
            }else if(bits[i] == 0 && i == len - 1){
                return true;
            }
        }
        return false;
    }
}
```