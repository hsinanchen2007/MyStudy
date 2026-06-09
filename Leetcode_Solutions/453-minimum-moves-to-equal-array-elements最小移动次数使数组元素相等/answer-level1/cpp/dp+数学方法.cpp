class Solution {
public:
    int minMoves(vector<int>& nums) {
        /*法一:dp
        假设有数组长度为i，先从小到大排序。假设直到 i-1 位置的元素都已经相等，我们只需要考虑 i 位的元素，那么即需要移动差值 diff=a[i]-a[i-1] 才可使整个数组相等，
        移动次数就是moves=moves+diff。而在实际情况中自底向上操作的过程中，从i=2，操作i=1加1时，i=2后面的元素也会加1，可最终结果我们要的是与整个数组中最后的那个
        也就是最大的那个相等，所以，我们不是给i=2后面的加1，而是给i=2加1，这样一步一步操作到最后。
        sort(nums.begin(),nums.end());
        int moves=0;
        for(int i=1;i<nums.size();i++)
        {
            nums[i]+=moves;
            moves+=nums[i]-nums[i-1];
        }
        return moves;
        */
        /*法二:math
        给n-1个数+1，就代表着给那个数-1
        */
        long min=nums[0],sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            min<=nums[i]?:min=nums[i];
        }
        return sum-nums.size()*min;
    }
};