#分别计算左积与右积
1. 用数组int[] left存放{1,1\*nums[0],1\*nums[1],...,1\*nums[1]\*...\*nums[n-2]};
2. 数组int[] right存放{nums[1]\*nums[2]\*...\*nums[n-1],...,nums[n-1]\*1,1};
3. 最后一次循环，使得结果a[i] = left[i] \* right[i].
- 执行用时 :2 m, 在所有 Java 提交中击败了98.29%的用户
- 内存消耗 :41.9 MB, 在所有 Java 提交中击败了96.20%的用户
```
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int len = nums.length;
        int[] left = new int[len];
        int[] right = new int[len];
        int[] a = new int[len];
        left[0] = 1;
        right[len-1] = 1;
        for(int i=1;i<len;i++){
            left[i] = nums[i-1] * left[i-1];
            right[len-i-1] = nums[len-i] * right[len-i]; 
        }
        for(int i=0;i<len;i++){
            a[i] = left[i]*right[i];
        }
        return a;
    }
}
```
