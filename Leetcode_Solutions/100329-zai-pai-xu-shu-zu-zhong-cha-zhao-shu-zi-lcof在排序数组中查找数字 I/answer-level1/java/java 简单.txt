class Solution {
    public int search(int[] nums, int target) {
        return findLen(nums, target, 0, nums.length);
    }
    
    //左闭右开
    public int findLen(int[] nums, int t, int l, int r){
        if(l>=r){
            return 0;
        }
        int m = l+(r-l)/2;
        if(nums[m] == t){
            //从mid展开
            int n1 = m, n2 = m;
            while(n1>=l && nums[n1] == t){
                n1--;
            }
            while(n2<r && nums[n2] == t){
                n2++;
            }
            return n2-n1-1;
        }else if(nums[m] < t){
            return findLen(nums, t, m+1, r);
        }else{
            return findLen(nums, t, l, m);
        }
    }
}