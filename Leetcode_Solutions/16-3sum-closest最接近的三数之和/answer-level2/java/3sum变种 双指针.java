### 解题思路
此处撰写解题思路
执行用时 :
6 ms
, 在所有 Java 提交中击败了
87.44%
的用户
内存消耗 :
39 MB
, 在所有 Java 提交中击败了
5.24%
的用户
### 代码

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int res = nums[0] + nums[1] + nums[2];
        int len = nums.length;
        for (int i = 0; i < len - 2; i++){
            int mid = i + 1;
            int right = len - 1;
            while (mid < right){
                int sum = nums[i] + nums[mid] + nums[right];
                if (Math.abs(sum - target) < Math.abs(res - target)){
                        res = sum;
                    }
                if (sum < target){
                    mid++;
                }
                else if (sum > target){
                    right--;
                }
                else{
                    return res;
                }
            }
        }
        return res;
    }
}
```