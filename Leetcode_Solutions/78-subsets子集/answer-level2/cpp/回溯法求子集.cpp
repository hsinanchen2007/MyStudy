思路：
```
class Solution {
public:
    vector<vector<int> > res;
    void minSet(int n,int start, vector<int>&nums,vector<int>&subNums) {
        //这个函数用来求固定长度的集合的子集。n表示子集中元素的个数
		if (nums.size() == n) {
			res.push_back(nums);
			return;
		}
		for (int i = start; i < subNums.size(); i++) {
			nums.push_back(subNums[i]);
			minSet(n, i + 1, nums, subNums);//深度遍历
			nums.pop_back();

		}
	}
    vector<vector<int>> subsets(vector<int>& nums) { 
        vector<int>tmp;
        for(int i=0;i<=nums.size();i++){
            //求出子集长度从 0 到nums.size()的所有集合
            minSet(i,0,tmp,nums);
        }
        return res;   
    }
};
```
