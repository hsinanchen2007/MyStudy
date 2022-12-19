一开始没看清以为是只能跳相应的步数，那么就是i+nums[i]==length-1
从后往前看满足这个条件的i，满足条件的可以把i加到队列，这样i+nums[i]的值在队列中或者是end都可以到达
最后看i=0是否满足条件。
然后仔细一看题目发现是最多跳相应的个数，其实更简单了，满足的条件变成了i+nums[i]>=length-1
这时都不需要记录所有的位置，只需要记录最小的位置点。从后往前遍历i+nums[i]>=这个位置即可到达
最小位置点是0就表明可以从头到尾到达
class Solution {
    public boolean canJump(int[] nums) {
        int end=nums.length-1;
        for (int j=nums.length-1;j>=0;j--){
            if(j+nums[j]>=end){
                end=j;
            }
        }
        return end==0?true:false;
    }
}