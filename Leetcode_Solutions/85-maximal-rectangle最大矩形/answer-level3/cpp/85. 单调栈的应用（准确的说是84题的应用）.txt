![image.png](https://pic.leetcode-cn.com/db1007604d7c4018079e3ae79cc69b9d3017bf3283e43ff9ada883c4996355a9-image.png)

### 解题思路
[为什么用柱状图](https://leetcode-cn.com/problems/maximal-rectangle/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-1-8/)

[柱状图怎么解](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/84-dan-diao-zhan-you-xu-zhan-zhu-shi-xie-de-zai-ha/) 

### 代码

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        vector<int> heights(matrix[0].size(),0);
        int res = -1;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(i==0){
                    heights[j] = (matrix[i][j]=='1'?1:0);
                }else{
                    if(matrix[i][j] == '0'){
                        heights[j] = 0;
                    }else{
                        heights[j] = heights[j]+1;
                    }
                }
            }
            int area = maxArea(heights);
            res = max(res, area);
        }
        return res;
    }
    int maxArea(vector<int> heights){
        if(heights.size() == 0) return 0;
        stack<int> st;
        st.push(-1);
        heights.push_back(-1);
        int res = 0;
        for(int i=0; i<heights.size(); i++){
            int topIndex = st.top();
            while(topIndex!=-1 && heights[topIndex]>heights[i]){
                int h = heights[topIndex];
                st.pop();
                int area = h * (i - st.top() -1);
                res = max(res, area);
                topIndex = st.top();
            }
            st.push(i);
        }
        return res;
    }
};
```