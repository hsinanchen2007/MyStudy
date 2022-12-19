### 解题思路
采用快、慢指针，计算出所有的组合值，并选出最大的值。这种方法比较笨，但是比较好理解。

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i=0;
        int j=1;
        int maxval=0;
        int val;
        for (i=0;i<len;i++){
            for (j=i+1;j<len;j++){
                val=min(height[i],height[j])*(j-i);
                if (maxval<=val){
                    maxval =val;
                }
            }        
        } 
        return maxval; 
    }
};
```