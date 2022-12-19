### 解题思路
第一步：计算出数组A中的偶数和sum。
第二步：遍历数组query，获取第i次查询时A[index]和val的值。
1. 计算查询后偶数和。
    - 若A[index]是奇数且val是奇数，则查询后偶数和为sum+A[index]+val
    - 若A[index]是偶数且val是奇数，则查询后偶数和为sum-A[index]
    - 若A[index]是偶数且val是偶数，则查询后偶数和为sum+val
2. 更新A[index]的值。

**时间复杂度O(n)  空间复杂度O(n)**

### 代码

```cpp
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans;
        int val, index, sum = 0;

        for(int j = 0; j < A.size(); j++){
            if(A[j] % 2 == 0){
                sum += A[j];
            }
        }

        for(int i=0; i<queries.size(); i++){
            val = queries[i][0];
            index = queries[i][1];

            if((A[index] & 1) == 1) {   //A[index]是奇数
                if((val & 1) == 1){   // val是奇数
                    sum += (A[index] + val);
                }
            }
            else{   //A[index]是偶数
                if((val & 1) == 0){   // val是偶数
                    sum += val;
                }
                else{
                    sum -= A[index];
                }
            }

            A[index] += val;

            ans.push_back(sum);
        }

        return ans;
    }
};
```