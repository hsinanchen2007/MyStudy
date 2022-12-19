```cpp
class Solution {

private:
    vector< vector<int> > res;

    // Cnk 问题 
    // 从start开始搜索新的元素
    // p保存已经确定好的不多于k个的元素
    void findCombine(int n, int k, int start, vector<int> &p) {

        if (p.size() == k) {
            res.push_back(p);
            return;
        }
        // for (int i = start; i <= n; i++) {
        for (int i = start; i <= n-(k-p.size())+1; i++) {  // 剪枝优化
            p.push_back(i);
            findCombine(n, k, i+1, p);
            p.pop_back();
        }
    }

public:
    vector< vector<int> > combine(int n, int k) {  

        if (n <=0 || k < 0 || k > n)
            return res;
        
        vector<int> p;
        findCombine(n, k, 1, p);
        return res;
        
    }
};
```
