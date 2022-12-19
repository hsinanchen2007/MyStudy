### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
    vector<vector<int>>res;
    vector<int>path;
public:
    vector<vector<int>> combine(int n, int k) {
        if(n==0) return {};
        backtrace(n,k,0,1);
        return res;
    }
    void backtrace(int n,int k,int pos,int start){ //start记录上一个i的位置，在加一
        if(pos==k){
            res.push_back(path);
            return ;
        }
        for(int i=start;i<n+1;i++){
            path.push_back(i);
            backtrace(n,k,pos+1,i+1);  //i是上一个函数里i的后一位。
            path.pop_back();
        }
    }
};
```