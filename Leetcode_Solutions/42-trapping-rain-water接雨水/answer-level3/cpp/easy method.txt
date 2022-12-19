### 解题思路

    小白QAQ轻喷蟹蟹

    由于题目是求 **盛水量**  可以找出 在数值 **左边** 和 **右边** 最大的值，以两者间的 **最小值** 作为 **上限** 再减去自身的高度 得到该位置对应的水量 ->其实就是第二行注释啦

### 代码

```cpp
// make clear that only itself is empty and its left and right is full 
// = min(leftMax,rightMax)-itself

int min(int fir, int sec){
    return (fir<sec)?fir:sec;
}


class Solution {
public:
    int trap(vector<int>& height) {
        // rightMax need to be initialized to avoid memory leak
        vector<int> leftMax,rightMax(height.size());

        int i=0,result=0,mid=0;
        for(i=0;i<height.size();i++){
            if( i==0 || leftMax[i-1]<height[i]){
                leftMax.push_back(height[i]);
            }
            else{
                leftMax.push_back(leftMax[i-1]);
            }
        }
        for(i=height.size()-1;i>-1;i--){
            if( i==height.size()-1 || rightMax[i+1]<height[i]){
                mid=height[i];                               
            }
            else{
                mid=rightMax[i+1];
            }
            rightMax[i]=mid;

            mid=min(rightMax[i],leftMax[i]);
            result+=((mid>height[i])? mid-height[i]:0);
        }
        return result;
    }
};
```