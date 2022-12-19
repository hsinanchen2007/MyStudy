### 解题思路
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
6.7 MB
, 在所有 C++ 提交中击败了
100.00%
的用户

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> v;
    vector<int> a;
    vector<int> hashtable;
    void dfs(int n,int k,int index,int index1){
        if(n<0)
           return;
        if(n==0&&index==k){
            v.push_back(a);
            return;
        }
        if(index==k||index1>9)
            return;
        for(int i=index1;i<=9;++i){
                a.push_back(i);
                dfs(n-i,k,index+1,i+1);
                a.pop_back();
        }
          
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k>9)
          return v;
        hashtable.resize(10);
        dfs(n,k,0,1);
        return v;
    }
};
```