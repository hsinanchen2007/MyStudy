### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int result = (j-i)*min(height[i],height[j]);
        while(i<j){
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
            int newResult = (j-i)*min(height[i],height[j]);
            if(newResult>result)result = newResult;
        }
        return result;
    }
};
```