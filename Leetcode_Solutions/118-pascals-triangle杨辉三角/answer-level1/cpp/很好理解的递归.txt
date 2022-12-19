想法就是，每一次递归填写一行，直到行数达到要求
```
class Solution {
public:
    void call(vector<vector<int>>& v, int count, int numRows) {
        if (count > numRows)
            return;
        if (count == 1) {
            v[count-1].assign(count,0);
            v[0][0] = 1;
        }else{
            v[count-1].assign(count,0);
            for (int i = 0; i < count; i++) {
                if (i == 0 || i == count - 1)
                    v[count - 1][i] = 1;
                else
                    v[count - 1][i] = v[count - 2][i-1] + v[count - 2][i];
            }            
        }
        count++;
        call(v, count, numRows);
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        ret.assign(numRows,vector<int>());
        int count = 1;
        call(ret, count, numRows);
        return ret;
    }
};
```
