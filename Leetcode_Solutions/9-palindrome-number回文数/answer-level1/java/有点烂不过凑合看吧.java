### 解题思路
我想的是依次比较，X的最低位和最高位的数字

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        int numLength = (int)(Math.log10(x)+1);

        int y = x,z = x;
        for(int i=0;i<numLength;i++){
            int k = (int)(z/(Math.pow(10,numLength-1-i)));
            if(y%10 != k){
                return false;
            }
            y = y/10;
            z = z-k*(int)Math.pow(10,numLength-1-i);
        }
        return true;
    }
}
```