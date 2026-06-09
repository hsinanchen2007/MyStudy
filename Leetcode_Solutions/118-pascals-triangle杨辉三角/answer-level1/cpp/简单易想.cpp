每一行除了第一个和最后一个是1，其余的index为i的数字，均是其上一行index为i-1和index为i的数字相加所得。

```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> temp;
        for(int i=1;i<=numRows;i++){// 第几行
            for(int j=1;j<=i;j++){
                if(j==1 || j==i){
                    temp.push_back(1);
                }else{
                    temp.push_back(result[i-2][j-2]+result[i-2][j-1]);
                    // 之所以-2，是因为我们的i和j是从1开始计数，-1是上一层，再-1因为索引值
                }
            }
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }
};
```