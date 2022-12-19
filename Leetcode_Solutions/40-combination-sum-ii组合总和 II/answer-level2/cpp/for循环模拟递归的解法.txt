### 解题思路
先排序，从最小寻找路径，要得到该路径下的值之和等于目标值。使用了for循环模拟递归的解法。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        int maxIndex = -1;
        for (int i = 0; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break;
            }
            maxIndex = i;
        }
        
        int startIndex = 0;
        stack<int> storeIndex;
        vector<int> myArray;
        vector<vector<int>> ret;
        int sum = 0;
        for (;;) {
            for (int i = startIndex; i <= maxIndex; i++) {
                if (target == sum + candidates[i]) {
                    myArray.push_back(candidates[i]);
                    ret.push_back(myArray);
                    myArray.pop_back();
                    break; //
                }else if (target > sum + candidates[i]) {
                    // 递归进去获得新元素
                    myArray.push_back(candidates[i]);
                    storeIndex.push(i);
                    sum += candidates[i];
                }else {
                    // 该路径下，后面的元素都大于目标和，跳出递归
                    break; //
                }
                
            }

            if (!storeIndex.empty()) {
                sum -= candidates[storeIndex.top()];
                startIndex = storeIndex.top();
                // 跳过同样的值
                while (candidates[storeIndex.top()] == candidates[startIndex]) {
                    startIndex++;
                    if (startIndex > maxIndex) {
                        break;
                    }
                }

                // 此路已经完毕，搜索新路径
                storeIndex.pop();
                myArray.pop_back();
            } else {
                break;
            }
        }

        return ret;
    }
};
```