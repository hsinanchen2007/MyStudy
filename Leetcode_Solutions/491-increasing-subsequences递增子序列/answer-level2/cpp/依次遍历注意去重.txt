### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    friend bool operator<(const vector<int> &v1,const vector<int> &v2){
        int i,n1=v1.size(),n2=v2.size();
        if(n1!=n2)return n1<n2;
        for(i=0;i<n1;i++){
            if(v1[i]!=v2[i])return v1[i]<v2[i];
        }
        return true;
    }//对数组排序
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int i,j,k,m,n=nums.size();
        vector<vector<int>>ans,t;//已经求得的所有递增的数组(含一个元素)
        vector<int>a;//已经求得的所有数组中的一个
        set<vector<int>>s;//存数组用来去重
        for(i=0;i<n;i++){
            t=ans;//为了防止加入答案数组时在这轮循环又被遍历
            for(k=0;k<t.size();k++){
                a=t[k];
                m=t[k].size();
                if(nums[i]>=t[k][m-1]){
                    a.push_back(nums[i]);
                    if(!s.count(a)){
                        s.insert(a);
                        ans.push_back(a);
                    }//没重复加入答案数组
                }
            }
            ans.push_back({nums[i]});//把当前的数加入答案数组
        }
        t.clear();
        for(i=0;i<ans.size();i++){
            if(ans[i].size()>1)t.push_back(ans[i]);//去除长度为1的数组
        }
        return t;
    }
};
```