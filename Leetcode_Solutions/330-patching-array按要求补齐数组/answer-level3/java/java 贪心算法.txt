### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minPatches(int[] nums, int n) {
        int  result=0;
        long miss=1;
        int i=0;
        while(miss<=n){
            if(i<nums.length&&nums[i]<=miss){
                miss=miss+nums[i];
                i=i+1;
            }
            else{
                miss=miss*2;
                result++;
            }
        }
        return result;
    }
}
```