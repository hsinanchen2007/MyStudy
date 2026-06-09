### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_=INT_MIN;
        int i=0,j=height.size()-1;
        while(i<j){
            int area = (j-i)*min(height[i],height[j]);
            max_=max(max_,area);
            if(height[i]<=height[j])
                while(height[i]>height[i++] && i<j) ;
            else
                while(height[j]>height[j--] && j>i) ;
        }
        return max_;
    }
};
```