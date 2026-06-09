### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums == null || nums.length == 0){
            return new int[0];
        }
        int[] res = new int[nums.length - k + 1];
        for(int i = 0;i < nums.length - k + 1;i++){
            int[] temp = new int[k];
            for(int j = 0;j < k;j++){
                temp[j] = nums[i+j];
            }
            Arrays.sort(temp);
            res[i] = temp[k-1];
        }

        return res;
    }
}
```