### 解题思路
要注意的
1. 当搜索到target时，判断左边是否为仍旧为该元素，如果是，继续搜索，直至找到最左边的target
2. 判断右边的时候也是同样的思路，直至找到最右边的target
3. 注意越界风险

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = new int[2];
        Arrays.fill(res, -1);
        dfs(nums, res, target, 0, nums.length-1);
        return res;
    }

    private void dfs(int[] nums,int[] res,int target,int i,int j){
        if (i > j)
            return;
        int mid = (i + j) / 2;
        if (target > nums[mid])
            dfs(nums, res, target,mid+1, j);
        else if(target < nums[mid])
            dfs(nums, res, target, i, mid-1);
        else {
            if (mid-1 < 0 || nums[mid-1] != target)
                res[0] = mid;
            else
                dfs(nums, res, target, i, mid-1);
            if (mid+1 >= nums.length || nums[mid+1] != target)
                res[1] = mid;
            else
                dfs(nums, res, target,mid+1, j);
        }
    }
}
```