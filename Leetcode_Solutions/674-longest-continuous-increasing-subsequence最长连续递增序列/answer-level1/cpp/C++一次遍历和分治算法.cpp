**1.一次遍历算法：**
借鉴了动态规划和贪心算法的思路，但是个人认为严格意义上来说并不算动态规划或贪心算法。
思路如下：设置两个变量，一个变量current用于存储当前递增序列的长度，另一个ans存储最目前找到的最大长度。
在移动指针i时，current首先判断当前值是否大于前一个值，如果大于则current加一。否则代表当前递增序列结束，current置为1，从当前值再开始重新计算下一个递增序列的长度。ans则在不断判断新的递增子序列是否目前找到的最长的。
代码如下：
```
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int current = 1;
        int ans = 1;
        for(int i = 1;i<len;i++){
            if(nums[i]>nums[i-1]) current+=1;
            else current = 1;
            ans = max(ans,current);
        }
        return ans;
    }
};
```
时间复杂度为O(n)，空间复杂度为O(1)。

**2.分治算法**
此算法比上一个算法复杂度要高，但思路也不错，值得借鉴。
思路如下：首先将原nums数组分为两个数组leftnums和rightnums，那么原数组的最长递增子序列只有可能是下面三种情况之一：
（1）nums数组的最长递增子序列与数组leftnums相同；
（2）nums数组的最长递增子序列与数组rightnums相同；
（3）nums数组的最长递增子序列位于中间部分，即这个序列有一部分位于leftnums，一部分位于rightnums。
基于此思路，可以写出代码：
```
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        return helper(nums,0,nums.size()-1);
    }
    int helper(vector<int>& nums,int left,int right){
        if(left==right)  return 1;
        int middle = left + (right-left) / 2;
        int resofleft = helper(nums,left,middle);
        int resofright = helper(nums,middle+1,right);
        int countleft = 1;
        int countright = 0;
        for(int i=middle;i>left;i--){
            if(nums[i]>nums[i-1]) countleft++;
            else break;
        }
        for(int i=middle;i<right;i++){
            if(nums[i+1]>nums[i]) countright++;
            else break;
        }
        int countofmiddle = countright + countleft;
        return max(max(countofmiddle,resofleft),resofright);
    }
};
```
在每一次递归时，原数组分为两个新的数组，并且要从中间元素向两侧执行一定的操作寻找中间部位的递增子序列。
因此递归方程为：T(n) = 2T(n/2) + O(n)。
进而时间复杂度为O(nlogn)，由于递归调用了logn次，每一次都需要常量的空间，因此空间复杂度为O(logn)。
