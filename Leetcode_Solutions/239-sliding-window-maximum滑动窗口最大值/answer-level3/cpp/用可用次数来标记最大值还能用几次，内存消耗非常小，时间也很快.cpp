### 解题思路
引入一个变量来记录之前查找到的最大值最多还能用几次，
在可用次数内，只需要和新出现的数值比一次既可以得到最大值：
    如果新出现的数组比较大，则可用次数重新变更为k-1;最大值为新出现的数
    如果历史最大值比较大，则可用次数减1
如果可用次数用完，则需要k次比较来重新得到最大值

时间复杂度算了半天也没算清楚，不知道怎么算这种两个变量的复杂度，头疼，欢迎大佬在评论里帮我算一下复杂度~

最后贴张图，纪念一下内存击败百分百用户，哈哈哈哈哈哈哈哈哈（容我嘚瑟一会~）

![截图.PNG](https://pic.leetcode-cn.com/31a2934d98352c89422ebb5affee69b66b5030524404749ddcf7748d14ac63ff-%E6%88%AA%E5%9B%BE.PNG)


### 代码

```cpp
class Solution {
public:
    int valueTime=0;  //最大值还能用几次
    int getMaxNum(int st, int end, vector<int>& nums){
        int maxNum=nums[st];
        for (int i=st+1; i <= end; i++){
            if (nums[i] > maxNum){
                maxNum = nums[i];
                valueTime=i-st-1;
            }
        }
        return maxNum;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //变量定义
        int vecSize=nums.size(), maxNum=nums[0];
        vector<int> ans;
        for (int i=k-1; i < vecSize; i++){
            //如果可用次数用完了，最大值已经到窗口最左边了，则重新计算最大值
            if (valueTime == 0){              
                maxNum=getMaxNum(i-k+1, i, nums);
            }
            //如果窗口右边的数小于窗口中的最大值，则可用次数减1，意思是最大值离窗口的左边又近了一丢丢
            else if (maxNum > nums[i]){
                valueTime--;
            }
            //如果窗口右边的数大于窗口中的最大值，则最大值和可用次数更新一下
            else if (maxNum <= nums[i]){
                maxNum=nums[i];
                valueTime=k-1;
            }
            ans.push_back(maxNum);
        }
        return ans;
    }
};
```