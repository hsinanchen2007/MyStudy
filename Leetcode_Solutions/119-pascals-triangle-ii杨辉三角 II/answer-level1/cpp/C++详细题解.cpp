杨辉三角每个位置的值就是该位置左上角与右上角的值。与杨辉三角Ⅰ的差别就是  只需要返回一层的数据。代码注释相对清晰，这里就不多说。

```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> vec(rowIndex+1); //想要第rowIndex行，由于从零开始，需要初始化rowIndex + 1行
        if(rowIndex == 0)   return {1}; //若需要第0行，返回1；
        for(int i = 0; i <= rowIndex; ++ i) //一行一行生成
        {
            for(int j = 0; j <= i; ++ j)
            {
                if(j == 0 || j == i) //若位置在左右边界，直接填1
                    vec[i].push_back(1);
                else
                    vec[i].push_back(vec[i-1][j-1] + vec[i-1][j]); //其它位置的值就是左上角与右上角的和
            }
        }
        return vec[rowIndex]; //返回杨辉三角第rowIndex行
    }
};
```