# 132模式
给定一个整数序列：a1, a2, ..., an，一个132模式的子序列 ai, aj, ak 被定义为：当 i < j < k 时，ai < ak < aj。设计一个算法，当给定有 n 个数字的序列时，验证这个序列中是否含有132模式的子序列。
注意：n 的值小于15000。

示例1:

```
输入: [1, 2, 3, 4]
输出: False
解释: 序列中不存在132模式的子序列。
```

示例 2:

```
输入: [3, 1, 4, 2]
输出: True
解释: 序列中有 1 个132模式的子序列： [1, 4, 2].
```
示例 3:

```
输入: [-1, 3, 2, 0]
输出: True
解释: 序列中有 3 个132模式的的子序列: [-1, 3, 2], [-1, 3, 0] 和 [-1, 2, 0].
```
 <html> <hr>

##  解法1：
注：题目只让我们找出序列中是否**存在**，那么我们可以在合理的i<j<k情况下，找较大的nums[j],和较小的nums[i]作为比较的根据，再存在大小在两者之间的nums[k]，说明该序列存在132模式。否则不存在。
###  实现代码：

```
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<3) return false;
        int i=0;//1模式
        int j=0;//3模式
        int k=0;//2模式
        int n=nums.size();
        while(i<n)
        {
            while(i<n-2 && nums[i]>=nums[i+1]) i++;
            j=i+1;
            while(j<n-1 && nums[j]<=nums[j+1]) j++;
            k=j+1;
            while(k<n)
            {
                if(nums[k]<nums[j] && nums[k]>nums[i])
                    return true;
                else k++;
            }
            i=j+1;
        }
        return false;
    }
};
```
<html><hr>

## 解法2：
用栈存放最大的元素，次大的元素用third存放，遍历方式从后往前。若找到比third小的元素则说明存在132模式。

##  实现代码：

```
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<3) return false;
        stack<int> max;
        int n=nums.size();
        int third=INT_MIN;//初始化不能为0，因为要进行比较，初始化为0会出错。
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<third) return true;
            while(!max.empty() && nums[i]>max.top())//若找到比栈中还大的元素，则更新
            {
                third=max.top();
                max.pop();
            }
            max.push(nums[i]);
        }
        return false;
    }
};
```

  
