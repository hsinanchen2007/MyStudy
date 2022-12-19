### 解题思路
这不跟三数之和一样么，先排序，固定一位置然后该位置右侧双指针。记录一下当前最接近的sum即可。

### 代码

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int n = nums.length;
        if (n < 3) return -1;

        Arrays.sort(nums);

        int nearSum = nums[0] + nums[1] + nums[2];
        int sub = Math.abs(nearSum - target);

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int curSub = Math.abs(sum - target);
                if (curSub < sub){
                    nearSum = sum;
                    sub = curSub;
                }
                if (sum < target)
                    l++;
                else if (sum > target)
                    r--;
                else return sum;
            } 
        }
        return nearSum;
    }
}
```