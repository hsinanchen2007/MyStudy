### 解题思路
![捕获8.PNG](https://pic.leetcode-cn.com/9eeef9df92df4f8cf72d4e28e98c46c46bc95f67fb4ccaa5b46cd6ba24ccbdc5-%E6%8D%95%E8%8E%B78.PNG)
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n<1){
            return false;
        }
        for(int i=32;i>=0;i--){
            if((1<<i)==n){
                return true;
            }
        }
        return false;
    }
}
```