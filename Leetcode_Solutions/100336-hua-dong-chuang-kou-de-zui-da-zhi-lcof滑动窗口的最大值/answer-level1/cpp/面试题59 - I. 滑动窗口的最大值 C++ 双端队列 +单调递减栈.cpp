### 解题思路
双端队列 + 单调递减栈
1.维持1个单调递减栈：栈底是最大值索引
2.当栈顶元素与栈底元素的差值>=k时，说明超出了划窗，需要将栈底弹出。
由于是单调递减栈，弹出元素后，栈底依然是最大的元素。


### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> buff;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            while (!buff.empty() && nums[i] >= nums[buff.front()]) {
                buff.pop_front();
            }

            buff.push_front(i);

            while (!buff.empty() && i - buff.back() >= k) {
                buff.pop_back();
            }

            if (i >= k - 1) {
                result.push_back(nums[buff.back()]);
            }
        }

        return result;
    }
};
```