### 解题思路
此处撰写解题思路
![捕获1.PNG](https://pic.leetcode-cn.com/31917b2bac0e9ef1bfeb8f60ef4f3cab645984e04bb9b428a3f5e5475d93bb20-%E6%8D%95%E8%8E%B71.PNG)

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        if(height.empty())
        return res;
        int r = height.size()-1;
        int l = 0;
        int max_i = height[0];
        int max_cnt = 0;
        for(int i=1; i<=r; i++){
            if(height[i] > max_i){
                max_i = height[i];
                max_cnt = i;
            }
        }
        int max_left = height[0];
        int max_right = height[r];
        for(int i = 1; i<max_cnt; i++){
            if(height[i] > max_left){
                max_left = height[i];
            }
            else{
                res+=max_left - height[i];
            }
        }
        for(int i = r-1; i >max_cnt ; i--){
            if(height[i] > max_right){
                max_right = height[i];
            }
            else{
                res+=max_right - height[i];
            }
        }
        return res;
    }
};
```