### 解题思路
此处撰写解题思路
单调栈的性质，栈里元素递减
### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        stack<int> s;
        s.push(0);
        int sum = 0;
        for(int i=1; i<height.size(); ++i){
            while(!s.empty() && height[i] > height[s.top()]){
                int base = s.top();
                s.pop();
                if(s.empty()) break;
                int neigh = s.top();
                int h = std::min(height[neigh], height[i]) - height[base];
                // 是 i-neigh-1，不是i-base
                sum += (h*(i-neigh-1));
            }
            s.push(i);
        }
        return sum;
    }
};
```