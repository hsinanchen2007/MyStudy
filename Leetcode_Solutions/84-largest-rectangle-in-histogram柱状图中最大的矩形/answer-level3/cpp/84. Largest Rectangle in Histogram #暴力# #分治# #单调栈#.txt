### 解题思路
暴力法


### 代码
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxRct = 0;
        for(int i = 0; i < heights.size(); i++){
            int left = i;
            int right = i;
            while(left >= 0 && heights[left] >= heights[i]) left--;
            while(right < heights.size() && heights[right] >= heights[i]) right++;
            maxRct = max(maxRct, (--right - ++left + 1)*heights[i]);
        }
        return maxRct;
    }
};
```

### 解题思路
分治法

### 代码

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        maxRect = 0;
        conquerDevide(heights, 0, heights.size() - 1);
        return maxRect;
    }
private:
    void conquerDevide(vector<int>& heights, int left, int right){
        cout << left << " " << right << endl;
        if( right < 0 ||  left >= heights.size() || left > right){
            return;
        }
        int minHeightIndex = 0;
        long minHeight = LONG_MAX;
        for(int i = left; i <= right; i++){
            if(heights[i] < minHeight){
                minHeightIndex = i;
                minHeight = heights[i];
            }
        }
        if(maxRect < (right - left + 1)*minHeight)
        maxRect = (right - left + 1)*minHeight;
        conquerDevide(heights, left, minHeightIndex - 1);
        conquerDevide(heights, minHeightIndex + 1, right);
    }
    long maxRect;
};
```

### 解题思路
单调栈
![a471b9acbfb61ebb7b29b40a9f7109f.jpg](https://pic.leetcode-cn.com/3c8fac3119b3d18f55db883305d49978a893d7109cf5ad3f20cd4d7908ea35de-a471b9acbfb61ebb7b29b40a9f7109f.jpg)

### 代码

```cpp
class Solution {
public:
//弹出需要计算的bar后栈为空：
//maxRect = topHight * i 
//弹出需要计算的bar后栈非空时：
//maxRrct = topHight * (i - preTopIndex - 1) 
    int largestRectangleArea(vector<int>& heights) {
        stack<int> myStack;
        int maxRect = 0;
        int height = 0;
        myStack.push(0);
        heights.push_back(0);
        for (int i = 1; i < heights.size(); i++) {
            while (!myStack.empty() && heights[i] < heights[myStack.top()]) {
                height = heights[myStack.top()];
                myStack.pop();
                maxRect = max(maxRect, height * (myStack.empty() ? i : i - myStack.top() - 1)); 
            }
            myStack.push(i);
        }
        return maxRect;
    }
};
```