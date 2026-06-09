### 解题思路
#### 1. 回溯递归思路很简单，前面有其他的详解，不介绍了。
#### 2. 子集问题和全排列问题几乎一模一样，只是在每次递归的时候，先push一个还没有添加num的子集。
#### 3. 查重 和 全排列II 的查重是一样的：
##### 3.1 为什么会产生重复子集呢，因为有重复数字。

比如你在第i层，在i+1~length-1之间寻找下一个要添加的num，假如nums[i+m]=k, 而且nums[i+m+x]=k，那么添加nums[i+m+x]往下的递归，其实都完全包含在nums[i+m]往下的递归里面。

因为i+m+x往下递归无非就是把i+m+x+1~length-1遍历一遍，而这个区间是包括在i+m的递归区间i+m+1~length-1里的。所以产生重复。

##### 3.2 既然是因为i+1~i+m+x-1中间，有个数和nums[i+m+1]一样，所以导致重复，那么查重也就是往前找，假如出现了重复，则当前数就不进行递归，放弃。

##### 3.3 小细节问题，这种查重实质上是在同一层递归的前提下，对要添加的num进行查重扫描，但假如是上上层和当前层重复呢，这种方法是不能查出来的。但是因为这个问题是因为 相同的数 中间隔了不相同的数导致的，因此可以添加一个排序整理，解决问题。


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        
        vector<int> temp;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());//不排序的话，如[4,4,4,1,4]会产生,[4,4,4,1]和[4,4,1,4]顺序不同但重复的子集，因此排序避免这个问题
        int cur=0;
        result.push_back(temp);

        int j;
        for(int i=0;i<nums.size();i++)
        {   
            
            for(j=i-1;j>=0;j--)//往前查重扫描
                if(nums[j]==nums[i])
                    break;
            if(j==-1)//查重通过
            {
                backtrace(i,nums,result,temp);
                temp.pop_back();
            }
        }

        return result;
    }

    void backtrace(int cur,vector<int>& nums,vector<vector<int>>& result,vector<int>& temp)
    {
        //填入当前数
        //push没有后续数的状态
        //遍历填入后续数
        
        temp.push_back(nums[cur]);
        result.push_back(temp);
        int j;
        for(int i=cur+1;i<nums.size();i++)
        {   
            
            for(j=i-1;j>=cur+1;j--)//往前查重扫描
                if(nums[j]==nums[i])
                    break;
            if(j==cur)//查重通过
            {
                backtrace(i,nums,result,temp);
                temp.pop_back();
            }
        }

    }
};
```