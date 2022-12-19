1. 合法性校验，如果colsum的总和不等于upper+lower，必然返回空。
2. 先处理2和0：如果colsum的2的，肯定上下都是1，upper, lower都减1；如果是0的肯定上下都是0；upper和lower都不变。
3. 再处理1：剩下的没有分配的位，要么upper为1，要么lower为1；如果分配完成则返回，分配不完就返回空。

![捕获.PNG](https://pic.leetcode-cn.com/a0c194f1449492c66936f0d94736158efa8f630bf86657f2cc6acd6fc7876696-%E6%8D%95%E8%8E%B7.PNG)

```
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) 
    {
        vector<vector<int>> e;
        vector<vector<int>> v;
        int sum = 0;
        for (auto n : colsum) {
            sum += n;
        }
        if (sum != upper + lower) {
            return e;
        }
        int size = colsum.size();
        if (upper > size || lower > size) {
            return e;
        }

        vector<int> r(size, 0);
        v.push_back(r);
        v.push_back(r);
        queue<int> s;
        // 分2和0
        for(int n = 0; n < size; n++) {
            if (colsum[n] == 2) {
                v[0][n] = 1;
                v[1][n] = 1;
                upper--;
                lower--;
                if(upper < 0 || lower < 0) {
                    return e;
                }
            } else if (colsum[n] == 0){
                continue;
            } else {
                s.push(n);    
            }
        }

        // 分1
        while(!s.empty()){
            auto n = s.front();
            s.pop();
            if (colsum[n] == 1) {
                if (upper) {
                    v[0][n] = 1;
                    upper--;
                } else if (lower) {
                    v[1][n] = 1;
                    lower--;
                } else {
                    return e;
                }
            }
        }
        return v;        
    }
};

```
