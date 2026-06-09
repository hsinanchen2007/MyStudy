### 解题思路
据题意总共有0-length个长度的元素
n限定元素，s决定下一层开始的元素下标，不会重复

### 代码

```cpp
class Solution {
private:
    vector<int> path,raw;
    vector<vector<int>> res;
public:
    void cal(int n,int s){
        if(path.size()==n){
            res.push_back(path);
            return;
        }
        for(int i=s;i<raw.size();i++){
            path.push_back(raw[i]);
            cal(n,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        raw=nums;
        for(int i=0;i<=nums.size();i++){
            cal(i,0);
        }
        return res;
    }
};
```