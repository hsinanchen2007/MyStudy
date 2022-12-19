如果有主要元素，则二分后，该主要元素肯定也超过一半。那么，对两边超过一半的元素计数，取两边较多的元素，计算出现次数，如果大于原数组一半则该元素为主要元素。
```
class Solution {
    int[] nums;
    public int majorityElement(int[] nums) {
        this.nums = nums;
        return solve(0, nums.length);
    }

    private int solve(int l, int r){
        if(l == r - 1){
            return nums[l];
        }
        int middle = (l + r) >> 1;
        int left = solve(l, middle);
        int right = solve(middle, r);
        if(left == right){
            return left;
        }
       
        int leftCount = count(left, l, middle);
        int rightCount = count(right, middle, r);
    
        int leftNum = (middle - l) >> 1;
        int rightNum = (r - middle) >> 1;
        if(leftCount > leftNum && leftCount >= rightCount){
            return left;
        }
        if(rightCount > rightNum && rightCount > leftCount){
            return right;
        }
        return -1;
    }

    private int count(int a, int l, int r){
        int res = 0;
        for(int i = l; i < r; i ++){
            if(nums[i] == a){
                res ++;
            }
        }
        return res;
    }
}
```
题外话：该数组不是正整数数组。。所以正常情况可能出现-1，不要过早剪枝了。。。会吃亏。。
