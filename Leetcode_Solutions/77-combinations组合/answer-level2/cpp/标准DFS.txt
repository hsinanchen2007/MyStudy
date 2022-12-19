### 解题思路
这道题就是标准的DFS的问题，里面涉及到的剪枝就是越大的元素越晚访问，并且每次访问的元素一定比访问过的元素大
f(n) > f(n-1)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> valid_res;
        count(res, valid_res, n, k, 1);
        return res;
    }

    void count(vector<vector<int>> &res, vector<int> &valid_res, int &n, int &k, int idx){
        if(valid_res.size() >= k){
            res.push_back(valid_res);
            return;
        }else{
            for(int i = idx; i <= n; ++i){
                //cout << i  << " " << valid_res.size() << endl;
                valid_res.push_back(i);
                count(res, valid_res, n, k, i+1);
                valid_res.pop_back();
            }
        }
    }
};
```

### 结果
执行用时 : 48 ms , 在所有 C++ 提交中击败了 55.22% 的用户 
内存消耗 : 9.1 MB , 在所有 C++ 提交中击败了 100.00% 的用户