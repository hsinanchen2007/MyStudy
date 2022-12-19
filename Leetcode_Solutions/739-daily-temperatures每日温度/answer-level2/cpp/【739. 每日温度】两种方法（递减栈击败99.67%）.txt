## 思路一：暴力
### 代码
时间复杂度：O(n^2)
```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int size = T.size();
        vector<int> res(size, 0);
        for (int i = 0; i < size; ++i) {
            for (int j = i+1; j < size; ++j) {
                if (T[j] > T[i]) {
                    res[i] = j - i;
                    break;
                }
            }
        }
        return res;
    }
};
```

## 思路二：递减栈（最优）
栈中只有递减元素，如果当前元素大于栈顶元素，则为第一个大于栈顶元素的数字，然后弹出栈顶元素，算出二者差即为距离（注意，栈中元素为下标值），然后继续看栈顶元素，直到当前元素小于栈顶元素停止，然后把当前元素放入栈中。
### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int size = T.size();
        vector<int> res(size, 0);
        stack<int> st;//递减栈
        for (int i = 0; i < size; ++i) {
            while (!st.empty() && T[i] > T[st.top()]) {
                int t = st.top();
                st.pop();
                res[t] = i - t;
            }
            st.push(i);
        }
        return res;
    }
};
```
### 另一种写法
用两个栈分别保存元素值和下标。
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st1, st2;                
        vector<int> res(T.size(), 0);
        for (int i = 0; i < T.size(); ++i) {
            while (!st1.empty() && st1.top() < T[i]) {
                res[st2.top()] = i - st2.top();
                st1.pop(),st2.pop();
            }
            st1.push(T[i]);
            st2.push(i);
        }
        return res;
    }
};
```

