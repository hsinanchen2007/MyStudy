### 解题思路
1. 左右侧扫描, 时间复杂度$O(N)$, 空间复杂度$O(N)$
2. 中间向两侧扫描, 时间复杂度$O(N)$, 空间复杂度$O(1)$
3. 栈辅助求解

### 代码
**解法1**
```c++ []
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        // 开辟动态数组
        int *max_left = new int[n]();
        int *max_right = new int[n]();
        // 从左向右扫描, 计算每个柱子的左侧最大值
        // 从右向左扫描, 计算每个柱子的右侧最大值
        for(int i=1; i<n; ++i){
            max_left[i] = max(max_left[i-1], height[i-1]);
            max_right[n-i-1] = max(max_right[n-i], height[n-i]);
        }

        int sum =0;
        for(int i=0; i<n; ++i){
            int hi = min(max_left[i], max_right[i]);
            if(hi > height[i])
                sum += (hi-height[i]);
        }

        delete []max_left;
        delete []max_right;

        return sum;
    }
};
```
**解法2**
```java []
class Solution {
    public int trap(int[] height) {
        if(height == null || height.length==0)
            return 0;
        
        // 中心扩散法
        int N = height.length;
        int maxIndex = 0;
        for(int i=0; i<N; ++i){
            if(height[i] > height[maxIndex])
                maxIndex = i;
        }
        
        int sum = 0;
        int peak = 0;

        // left -> maxIndex
        for(int i=0; i<maxIndex; ++i){
            if(peak < height[i])
                peak = height[i];
            else
                sum += (peak-height[i]);
        }

        // right -> maxIndex
        peak = 0;
        for(int i=N-1; i>maxIndex; --i){
            if(peak < height[i])
                peak = height[i];
            else
                sum += (peak-height[i]);
        }

        return sum;
    }
}
```
```python []
class Solution:
    def trap(self, height: List[int]) -> int:
        if height == None or len(height) == 0:
            return 0

        maxIndex, Sum, peak, N = 0, 0, 0, len(height)
        for i in range(0, N):
            if height[i] > height[maxIndex]:
                maxIndex = i

        for i in range(0, maxIndex):
            if height[i] > peak:
                peak = height[i]
            else:
                Sum += (peak-height[i])
        peak = 0
        for i in range(N-1, maxIndex, -1):
            if height[i] > peak:
                peak = height[i]
            else:
                Sum += (peak-height[i])

        return Sum
```
```c++ []
class Solution {
public:
    int trap(vector<int>& height) {
        const int N = height.size();
        // 记录最高位置
        int maxIndex = 0;
        for(int i=0; i<N; ++i){
            if(height[i] > height[maxIndex])
                maxIndex = i;
        }

        int sum = 0;
        // 从最高位置向两侧扫描
        int hi = 0;
        for(int i=0; i<maxIndex; ++i){
            if(height[i] > hi)
                hi = height[i];
            else
                sum += (hi-height[i]);
        }
        hi = 0;
        for(int i=N-1; i>maxIndex; --i){
            if(height[i] > hi)
                hi = height[i];
            else
                sum += (hi-height[i]);
        }
        return sum;
    }
};
```
**解法3**
```c++ []
class Solution {
public:
    int trap(vector<int>& height) {
        // 栈辅助
        const int N = height.size();
        // 存储柱子的高度和位置(height, pos)
        stack<pair<int, int>> st;
        int sum = 0;
        for(int i=0; i<N; ++i){
            int hi = 0;
            while(!st.empty()){
                int bar = st.top().first;
                int pos = st.top().second;
                // bar, height[i], hi可以容下雨水
                sum += (min(bar, height[i])-hi)*(i-pos-1);
                hi = bar;
                if(height[i] < bar)
                    break;
                else
                    st.pop();
            }
            st.push(make_pair(height[i], i));
        }
        return sum;
    }
};
```