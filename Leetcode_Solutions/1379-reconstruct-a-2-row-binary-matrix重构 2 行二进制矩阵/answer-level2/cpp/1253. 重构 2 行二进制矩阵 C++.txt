### 解题思路
核心思路：
1.先排除为无解的场景
1）行的和与列的和不相等：upper+lower 与colsum不相等
2）行的和大于列的个数：因为只有0,1两个值，因此行的最大和就是列的长度
3）行的和小于2的个数：2的个数一定是平分在上下两列，因此行的和必须大于等于2的个数

2.把列和为2的对upperrow进行赋值
3.如果upperrow未达到upper，且colsum[i] == 1 && upperrow[i] = 0，则对upperrow[i]继续赋值1
4.lowerrow = colsum - upperrow;



### 代码

```cpp
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {

        vector<int> upperrow = vector<int>(colsum.size(), 0);
        vector<int> lowerrow = vector<int>(colsum.size(), 0);
        vector<vector<int>> result;

        int sum = 0;
        int twocount = 0;
        for(auto num :colsum){
            sum += num;
            if(num ==2){
                twocount++;
            }
        }

        if(upper+ lower != sum || upper>colsum.size()|| lower>colsum.size()|| upper<twocount || lower<twocount){
            return vector<vector<int>>();
        }

        int count = 0;
        for (int i = 0; i < colsum.size();i++){
            if(colsum[i] == 2){
                upperrow[i] = 1;
                count++;
            }
        }

        for (int i = 0; i < colsum.size();i++){
            if(count<upper &&colsum[i] == 1 && upperrow[i] ==0){
                upperrow[i] = 1;
                count++;
            }
        }

        for (int i = 0; i < colsum.size();i++){
            lowerrow[i] = colsum[i] - upperrow[i];
        }
        result.push_back(upperrow);
        result.push_back(lowerrow);
        return result;
    }
};
```