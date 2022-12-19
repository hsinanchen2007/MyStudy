![数组递增.PNG](https://pic.leetcode-cn.com/83905af4a4f6b1b72e8a707d914f096c049231f6d8a64e3d7426c8c4dee94e07-%E6%95%B0%E7%BB%84%E9%80%92%E5%A2%9E.PNG)

查找递增数组实际就是以每个元素为起点，以后面每个比他大的元素都可以发散出一条路径，所以可以用dfs。数组中重复的元素只需要以前面的元素为起点进行dfs，因为后面元素的所有情况在前面都可以考虑到。所以对需要dfs的nums元素哈希去重，用unordered_map<int,int>,键为元素值，值为元素下标，在以i为起点dfs时，还要对后面的元素相互去重，道理一样
```
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int,int> s;//重复数字筛选，后面的数字有的情况前面数字都已经囊括不需要dfs
	    for (int j = 0; j < nums.size(); j++){
		    if (s.find(nums[j]) == s.end())
			    s.insert(make_pair(nums[j], j));
	    } 
        for(auto &i:s){
            vector<int> sum;
            dfs(nums,i.second,sum,res);
        }
        return res;
    }
    void dfs(vector<int>& nums,int& i,vector<int>&sum,vector<vector<int>>& res){
        int n=sum.size();
        if(i>nums.size()) return;//已经遍历完，终止
        if(n>0 && nums[i]<sum[n-1])return;//数不递增路径终止
        sum.push_back(nums[i]);
        if(n>0) res.push_back(sum);
        unordered_map<int,int> m;//i后面的数字有重复的筛选出来，只要重复数字中最前面位的数字作为下一个路径
	    for (int j = i + 1; j < nums.size(); j++){
		    if (m.find(nums[j]) == m.end())
			    m.insert(make_pair(nums[j], j));
	    }
        for(auto num:m)
            dfs(nums,num.second,sum,res);
        sum.pop_back();//数字还原
    }
};
```
