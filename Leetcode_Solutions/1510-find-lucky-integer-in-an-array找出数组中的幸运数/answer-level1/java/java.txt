### 解题思路
先对每个数计数，然后逆序循环找到第一个即为所求

### 代码

```java
class Solution {
    public int findLucky(int[] arr) {
       //先对每个数计数
        int[] count = new int[501];
        for(int a:arr){
            count[a]++;
        }
        
        for(int i=500;i>=1;i--){
            if(i == count[i]){
                return i;
            }
        }
        
        return -1;
    }
}
```