### 解题思路
执行用时 :
2620 ms, 在所有 C++ 提交中击败了5.43%的用户
内存消耗 :14.8 MB, 在所有 C++ 提交中击败了7.48%的用户
### 代码

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size=heights.size();
        int max_=0;
        for(int i=0;i<size;i++){
            int width=0,height=heights[i];
            for(int j=i;j<size;j++){
                if(heights[j]>=height){
                    width++;
                }else{
                    break;
                }
            }
            for(int j=i-1;j>=0;j--){
                if(heights[j]>=height){
                    width++;
                }else{
                    break;
                }
            }
            if(width*height>max_){
                max_=width*height;
            }
        }
        return max_;
    }
};
```