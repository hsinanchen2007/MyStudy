### 解题思路
循环数组，如何构造出满足条件的数组是一个问题，一般的处理办法都是在后面再添加一长串数组，模拟循环的场景。
然后就是一般的处理和位置相关&&大小，求取最近的大或者小的问题，利用一个最大栈或者最小栈进行处理即可。

### 代码

```cpp
class Solution {
public:
vector<int> nextGreaterElements(vector<int>& nums) {
        int numsLength = nums.size();
        for (int i = 0; i < numsLength; i++) {
            nums.push_back(nums[i]);
        }
        stack<int> results_temp;
        vector<int> results;
        stack<int> bigStack;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (! bigStack.empty() && nums[i] >= bigStack.top()) {
                bigStack.pop();
            }
            int currentNode = bigStack.empty() ? -1 : bigStack.top();
            bigStack.push(nums[i]);
            results_temp.push(currentNode);
        }
        int index = 1;
        while(index <= numsLength && !results_temp.empty()) {
                index++;
                results.push_back(results_temp.top());
                results_temp.pop();
        }
        return results;
    }
};
```