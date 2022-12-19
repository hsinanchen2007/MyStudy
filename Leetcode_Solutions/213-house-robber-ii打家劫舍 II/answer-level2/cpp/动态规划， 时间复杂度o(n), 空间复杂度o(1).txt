因为这个数据使环状排列，可以考虑将这个环分成两个串，一个包含头不包含尾，一个包含尾不包含头，分别做动态规划，最后输出最大值。具体代码如下，代码里有一些注释。
```
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 0) return 0;
        if (n <= 3) return *max_element(nums.begin(), nums.end());
        
        return max(find_most(nums, 0, n-1), find_most(nums, 1, n));
   
    }
    int find_most(vector<int> nums, int begin, int end){
        int m0 = nums[begin], m1, flag; 
        if (nums[begin+1] > nums[begin]) m1 = nums[begin+1], flag = 1; // flag用来标记这个家是否被打劫
        else m1 = m0, flag = 0;
        for (int i=begin+2; i<end; i++){         
            int temp = m0; m0 = m1;
            if (flag){  //上一家是被打劫的
               if (temp + nums[i] > m0) m1 = temp + nums[i], flag = 1;   //判断到上上家为止打劫的最大值加上当前这家的财产是否大于到上家为止被打劫的财产
               else m1 = m0, flag = 0;
            }
            else {
                m1 = m0 + nums[i]; flag = 1;
            }
        } 
        return m1;
    }
};
```
