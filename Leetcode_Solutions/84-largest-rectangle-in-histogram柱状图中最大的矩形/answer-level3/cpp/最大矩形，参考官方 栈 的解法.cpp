### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 1) {
            return heights[0];
        }
        stack<int> m_iStack;
        int max_area = 0;
        m_iStack.push(-1);
        for(int i = 0; i < heights.size(); ++i) {
            //cout<<i<<endl;
            if (m_iStack.top() == -1) {
                m_iStack.push(i);
            } else {
                //cout<<m_iStack.top()<<endl;
                if (heights[m_iStack.top()] < heights[i]) {
                   // cout<<"test"<<endl;
                    m_iStack.push(i);
                } else {
                    //cout<<i<<endl;
                    int index = m_iStack.top();
                    m_iStack.pop();
                    max_area = max(max_area, heights[index] * (i - 1 - m_iStack.top()));
                    //cout<<i<<" "<<max_area<<endl;
                    --i;
                }
            }
        }

        while(!m_iStack.empty() && m_iStack.top() != -1) {
            int index = m_iStack.top();
            m_iStack.pop();
            int width = heights.size() - m_iStack.top() - 1;
            max_area = max(max_area, width * heights[index]);
        }
        return max_area;
    }
};
```