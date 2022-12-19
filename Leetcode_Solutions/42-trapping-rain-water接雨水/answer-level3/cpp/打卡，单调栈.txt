### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int num = height.size();
        if(num == 0){
            return 0;
        }
        stack<int> stack;
        int ans = 0;
        for(int i = 0; i < num; i++){
            while(!stack.empty() && height[stack.top()] < height[i]){
                int idx = stack.top();
                stack.pop();
                while(!stack.empty() && height[stack.top()] == height[idx]){
                    stack.pop();
                }
                if(!stack.empty()){
                    int stackTop = stack.top();
                    ans += (min(height[stackTop],height[i]) - height[idx]) * (i - stackTop -1);
                }
            }
            stack.push(i);
        }
        return ans;
    }
};



```