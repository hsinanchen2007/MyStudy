位置i到j处的盛水面积为area=(j-i)*min(height[i],height[j])，此时再计算i与j之内的面积，那下一刻的(j-i)势必减小，如果要面积继续增大，那只能让height[j-1]>height[j]或者height[i-1]>height[i]。故代码如下：
```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int right=height.size()-1,left=0;
        int max_area=0;
        while(left<right){
            int area=(right-left)*min(height[left],height[right]);
            max_area=max(area,max_area);
            if(height[left]<height[right]) left++;
            else if(height[left]>height[right]) right--;
            else {left++;right--;}
        }
        return max_area;
    }
};
```


