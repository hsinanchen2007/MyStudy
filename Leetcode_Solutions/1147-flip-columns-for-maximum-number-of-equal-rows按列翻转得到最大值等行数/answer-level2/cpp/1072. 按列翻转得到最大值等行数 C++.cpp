### 解题思路
参考大力王的思路
如果通过转换n列可以使行上每个数相等，则这些行
1）完全按位相等，
2）完全按位相反

如：
001
110
001

因此，我们可以把每行进行映射统计：
1）0开头的不变
2）1开头的全部取反
在map中统计个数，个数最大的则为结果

### 代码

```cpp
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<vector<int>,int> countmap;
        int result = 0;

        for(auto row:matrix){
            if(row[0] == 0){
                countmap[row]++;
            }else{
                vector<int> newrow;
                for(auto i:row){
                    newrow.push_back(!i);
                }
                countmap[newrow]++;
            }
        }

        for(auto count: countmap){
            result = max(result, count.second);
        }
        return result;
    }
};
```