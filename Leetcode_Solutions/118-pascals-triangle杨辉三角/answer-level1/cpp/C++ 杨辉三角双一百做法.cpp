```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        //数组初始化全为1
        for(int i = 1; i <= numRows; i ++){
            vector<int> temp(i , 1);
            res.push_back(temp);
        } 
        //从第三行开始，对除第一个元素和最后一个元素进行赋值。
        for(int i = 2; i < numRows; i ++)
            for(int j = 1; j < i; j ++)
                res[i][j] = res[i - 1][j -1] + res[i - 1][j];

        return res ;
    }
};
```
新人入坑，有更优的解法欢迎分享一下。
