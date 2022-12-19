### 解题思路
每次以第一个数为开头的排列
每次到一个开头的序列的最底部时开始回溯到最原始的状态，再以第二个数开头
就这样一直到原始序列的最后一个数
此处撰写解题思路

### 代码

```cpp
#pragma GCCoptimize(3)
class Solution {
public:
    vector<vector<int>> v;
    inline void swap(vector<int> &v,int i,int k){
        int t=v[i];
        v[i]=v[k];
        v[k]=t;
    }
    void f(vector<int> &a,int k,int n){
        if(k==n-1){
            v.push_back(a);
        }
        else{
            for(int i=k;i<n;i++){
                swap(a,i,k);
                f(a,k+1,a.size());
                swap(a,i,k);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0){
            return v;
        }
      f(nums,0,nums.size());
      return v;
    }
};
```