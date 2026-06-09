这道题挺新颖的，分别从两种角度考虑求解，如下:

1、考虑层序遍历求解，每次加入一个元素就扩充res的长度，直到所有元素添加完毕。

![解析.png](https://pic.leetcode-cn.com/03408dfe78564b721a065bf3bb34bc4e933f321a6e5e5883f0a5096a88dadb0b-%E8%A7%A3%E6%9E%90.png)
```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res(1);
        for(int i=0;i<nums.size();i++){
            int cnt=res.size();
            for(int j=0;j<cnt;j++){
                vector<int> tmp=res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
```

2、回溯求解。
```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        helper(res,tmp,nums,0);
        return res;
    }
    void helper(vector<vector<int> >& res,vector<int> tmp,vector<int>& nums,int level){
        if(tmp.size()<=nums.size()){
            res.push_back(tmp);
        }
        for(int i=level;i<nums.size();i++){
            tmp.push_back(nums[i]);
            helper(res,tmp,nums,i+1);
            tmp.pop_back();
        }
    }
};
```
3、深度优先遍历求解
```
void helper(vector<vector<int> >& res, vector<int> tmp, vector<int>& nums, int level) {
	if (level >= nums.size()) {
		res.push_back(tmp);
		return;
	}
	tmp.push_back(nums[level]);
	helper(res, tmp, nums, level + 1);
	tmp.pop_back();
	helper(res, tmp, nums, level + 1);
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int> > res;
	vector<int> tmp;
	helper(res, tmp, nums, 0);
	return res;
}
```