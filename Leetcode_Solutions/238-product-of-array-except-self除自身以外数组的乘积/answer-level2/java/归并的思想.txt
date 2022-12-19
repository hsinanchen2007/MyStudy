### 解题思路
归并的思路，一步一步合并。

### 代码

```java
class Solution {
   public int[] productExceptSelf(int[] nums) {
        int[] res = new int[nums.length];
        Arrays.fill(res, 1);
        mergeArray(nums, res, 0, res.length-1);
        return res;
    }

    private void mergeArray(int[] nums,int[] res,int i,int j){
        if (i >= j)
            return;
        int mid = (i + j) / 2;
        mergeArray(nums,res,i,mid);
        mergeArray(nums,res,mid + 1,j);
        toOne(nums,res,i,mid,j);
    }

    private void toOne(int[] nums,int[] res,int i,int mid,int j){
        int left = 1;
        int right = 1;
        for(int k = i ;k <= mid;k++)
            left *= nums[k];
        for(int k = mid+1 ;k <= j;k++)
            right *= nums[k];
        for (int k = i; k <= mid; k++)
            res[k] = res[k] * right;
        for(int k = mid+1 ;k <= j;k++)
            res[k] = res[k] * left;
    }
}
```