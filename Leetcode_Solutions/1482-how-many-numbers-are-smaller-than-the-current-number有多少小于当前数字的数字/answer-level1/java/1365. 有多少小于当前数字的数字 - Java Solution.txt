### 暴力求解
采用枚举法进行暴力求解。

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] ret= new int[nums.length];
        for(int i=0;i<nums.length;i++){
            for(int j=0;j<nums.length;j++){
                if(i==j){
                    continue;
                }
                if(nums[i]>nums[j]){
                    ret[i]++;
                }
            }
        }
        return ret;
    }
}
```
### 复杂度
- 时间：$O(n^2)$ 
- 空间：$O(1)$