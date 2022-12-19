### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
        int ans = 0 ;
        for(int n : nums){
            if(((int)Math.log10(n)+1)%2==0){
                ans++;
            }
        }
        return ans;
    }
}
```