### 解题思路
建立单调栈并设置辅助节点$-1$(考虑所有柱子的公共面积)

### 代码

```c++ []
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
            return 0;

        // 单调栈
        int N = heights.size();
        stack<int> st;
        int maxA = 0;
        for(int i=0; i<=N; ++i){
            int pivot = (i==N) ? -1: heights[i];
            while(!st.empty() && pivot <= heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                int w = st.empty()? i: i-st.top()-1;
                maxA = max(maxA, w*h);
            }
            st.push(i);
        }

        return maxA;
    }
};
```
```java []
class Solution {
    public int largestRectangleArea(int[] heights) {
        // 单调栈
        if(heights == null || heights.length==0)
            return 0;
        int N = heights.length;
        st = new Stack<>();
        int maxA = 0;
        for(int i=0; i<=N; ++i){
            // 放置哨兵点, 为了使全部元素都出栈
            int pivot = (i==N) ? -1: heights[i];
            while(!st.isEmpty() && pivot <= heights[st.peek()]){
                int h = heights[st.pop()];
                int w = st.isEmpty()? i:i-st.peek()-1;
                maxA = Math.max(maxA, h*w);
            }
            st.push(i); // 将坐标放入栈中
        }        

        return maxA;
    }
    private Stack<Integer> st;
```
```python []
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        N = len(heights)
        if N == 0: return 0
        st = []
        S = 0
        for i in range(N+1):
            pivot = heights[i] if i<N else -1
            # 当pivot小于等于栈顶元素时计算面积
            while len(st) > 0 and pivot <= heights[st[-1]]:
                h = heights[st.pop(-1)]
                w = i-st[-1]-1 if len(st)>0 else i
                S = max(w*h, S)
            st.append(i)

        return S
```