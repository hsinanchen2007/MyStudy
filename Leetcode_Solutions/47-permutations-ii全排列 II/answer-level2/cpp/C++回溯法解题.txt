这题的关键就是怎么剪枝，去重，实现快速的回溯。这里说下我的思路:
首先我们来看下例子[1,1,2]可能得到所有排列:
 0     1    2    3
1(1)-1(2)-2(3)  保留
1(1)-2(3)-1(2)  保留
**1(2)-1(1)-2(3)**  排除
**1(2)-2(3)-1(1)**  排除
2(3)-1(1)-1(2)  保留
2(3)-1(2)-1(1)  排除
最上面的数字代表递归的层数，每个数字括号后面的数字代表这个数字在数组中的位置。以加粗的两个排列为例，我们想要在1(2)这一步就剪掉这棵子树。**我们可以在每一层，设置一个标记来记录上一次回溯所取的值。如果后面要取的值等于这个值。直接跳过即可。**

```
bitset<50> flag;
    vector<int> tmpans;
    vector<vector<int>> ans;
    void dfs(vector<int>& nums,int t)
    {
        if(t==nums.size())
            ans.push_back(tmpans);
        int last=1<<10;
        for(int i=0;i<nums.size();i++)
        {
            if(flag[i]==1 || nums[i]==last)
                continue;
            flag[i]=1;
            tmpans.push_back(nums[i]);
            last=nums[i];
            dfs(nums,t+1);
            flag[i]=0;
            tmpans.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        flag.reset();
        dfs(nums,0);
        return ans; 
    }
```


