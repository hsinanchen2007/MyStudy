### 解题思路
很菜的位运算解法
### 代码

```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        int mask=1;
        for(int i=0;i<31;i++){
            if(mask==n){
                return true;
            }
            mask=mask<<1;
        }
        return false;
    }
}
```