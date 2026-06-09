### 解题思路
# 本人水平有限，没想到位运算，查看了大神的思路写的
### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        long bitLow = 0;//低64位
        long bitHigh = 0;//高64位

        for(char c : astr.toCharArray()){

            if(c>64){
                long bitStatus = 1L<<c-64;
                if((bitHigh & bitStatus) != 0){
                    return false;
                }

                bitHigh |= bitStatus;
            }else {
                long bitStatus = 1<<c;
                if((bitLow & bitStatus) != 0){
                    return false;
                }

                bitLow |= bitStatus;
            }

        }
        return true;
    }
}
```