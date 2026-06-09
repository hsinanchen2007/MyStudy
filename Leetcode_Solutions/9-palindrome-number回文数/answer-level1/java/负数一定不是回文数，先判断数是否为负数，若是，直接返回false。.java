### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        int num = 0;
        int val = x;

        if(val < 0){
            return false;
        }else{
            while(x != 0){
                num = num * 10 + x % 10;
                x = x / 10;
            }
            
            if(num == val){
                return true;
            }else{
                return false;
            }
        }
    }
}
```