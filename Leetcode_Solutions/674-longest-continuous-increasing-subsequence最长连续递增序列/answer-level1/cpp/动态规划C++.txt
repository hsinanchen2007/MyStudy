```
class Solution {
public:
    //sort默认使用less升序排列 因此自定义比较函数 做降序排列
    static bool comp(int a, int b){
        return a>b;
    }
    //使用动态规划来实现
    //过程分析：
    //设定max[i]为nums遍历到第i元素对应的最长连续增序列的长度，max可以理解为一个整形数组
    //那么max[i]有两种情况：
    // A.nums[i]>nums[i-1] 则max[i]=max[i-1]+1 即当前元素大于前一个元素
    // B.nums[i]<=nums[i-1] 则max[i]=1 即当前元素小于等于前一个元素
    //完成nums的所有元素的遍历 最后再返回max数组中最大的值即可
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        //边界条件处理
        if(len<=1)
            return len;
        //正常情况处理
        int max[len];
        max[0]=1;//第一个元素的初始化
        for(int i=1;i<len;i++){
            // 情况A：
            if(nums[i]>nums[i-1])
                max[i]=max[i-1]+1;
            // 情况B：
            else
                max[i]=1;
        }
        //默认less
        //sort(max,max+len);
        //return max[len-1];
        //自定义great
        sort(max,max+len,comp);
        return max[0];
    }
};
```
