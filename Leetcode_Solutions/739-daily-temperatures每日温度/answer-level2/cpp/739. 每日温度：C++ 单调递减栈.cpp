### 解题思路
单调递减栈：
1）当前元素大于栈顶元素时，弹出栈顶元素，记录差值
2）实际压栈的不是数值，而是索引


当遍历的数字大于栈顶时，栈顶出栈，直到栈内元素大于遍历元素 举例说明
例子：[73, 74, 75, 71, 69, 72, 76, 73]
1）73压栈 栈内容：73
2）74>73,73出栈，74压栈  栈内容：74
3）75>74 74出栈，75压栈  栈内容：75
4）71<75 71压栈          栈内容：71 75
5）69<71 69压栈         栈内容：69 71 75
6）72>69 71             栈内容：72 75
7) 76>72 75             栈内容：76
8) 73<76                栈内容：73 76




### 代码

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        vector<int> result = vector<int>(T.size(), 0);
        deque<int> buff;

        for (int i = 0; i < T.size(); i++) {
            while (!buff.empty() && T[i] > T[buff.front()]) {
                result[buff.front()] = i-buff.front();
                buff.pop_front();
            }

            buff.push_front(i);
        }

        return result;
    }
};
```