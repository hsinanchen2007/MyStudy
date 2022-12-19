### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> mark(nums.size(),0);
        vector<int> list;
        vector<vector<int>> result;
        map<int,int> a;
        for(int i=0;i<nums.size();i++) a[nums[i]]=-1;  #使用标记字典进行剪枝
        sort(nums.begin(),nums.end());        #对原来的数组从小到大进行排序
        dfs(result,nums,list,mark,a);
        return result;
    }
    void dfs(vector<vector<int>>&result,vector<int>& nums,vector<int>&list,
             vector<int>& mark, map<int,int>& a )
    { if(list.size()==nums.size())  {result.push_back(list);return ;}
      for(int i=0;i<nums.size();i++)
      { 
        if(!mark[i])               #对数组每一位的数据使用全排列的方式
        {if(i<a[nums[i]]) return;  #如果当前标号大于数字对应的标号，说明进入了重复排序
         int j=a[nums[i]];         #记下搜索前的编号
         list.push_back(nums[i]);
         mark[i]=1;
         a[nums[i]]=i;         
         dfs(result,nums,list,mark,a);
         mark[i]=0;
         a[nums[i]]=j;         #还原原来的标号
         list.pop_back();
        }
      }
     return ;
    }
};
```