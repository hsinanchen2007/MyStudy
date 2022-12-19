### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int i,j,cnt,k = 0;
        int[] ans = new int[nums.length];
        for(i = 0; i < nums.length; i++){
            cnt = 0;
            for(j = 0; j < nums.length; j++){
                if(nums[j] < nums[i]){
                    cnt++;
                }
            }
            ans[k++] = cnt;
        }
        return ans;
    }
}
```