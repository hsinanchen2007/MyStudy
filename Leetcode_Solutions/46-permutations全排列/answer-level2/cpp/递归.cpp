### 解题思路
此处撰写解题思路
对于当前数nums[k],它前面的所有数顺序固定，它后面的数已排好（perm(k+1)）,只需要让它与后面的数逐个交换就可以得到perm（k），即k和k后面的数的全排列；
例如：
1234；打头的每个数与其后的每一可能的数交换就可得到打头位置的全排列
2134；
3214；
4231；
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      int k=0,m=nums.size()-1;
      perm(nums,k,m,res);
      return res;
    }
    void swap(int& a,int& b){
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
}

void perm(vector<int>& nums,int k,int m,vector<vector<int>>& res){
    if(k==m) res.push_back(nums);
    for(int i=k;i<=m;++i){
        swap(nums[i],nums[k]);
        perm(nums,k+1,m,res);
        swap(nums[i],nums[k]);
    }
}
};

```