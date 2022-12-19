主要是参考官方的分治法，但是在出现在连续N个1的时候会超时。
所以这里优化一下，就是在找左边或右边处理的时候，输入的边界比当前值要大。
这里上代码，大家看下。
```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return caculateArea(heights, 0, heights.size() - 1);
    }
private:
    int caculateArea(vector<int>& heights, int start, int end){
        if(start > end){
            return 0;
        }
        int minIndex = start;
        int minStartIndex = start; 
        for(int i = start + 1; i <= end; i++){
            if( heights[minIndex] > heights[i]){
                minIndex = i;
            }
        }
        // 分别往左边和右边找到下一个比分界线大的值
        int leftBiggerIndex = minIndex - 1;
        int rightBiggerIndex = minIndex + 1;
        while(leftBiggerIndex > 0 && heights[leftBiggerIndex] <= heights[minIndex]){
            leftBiggerIndex--;
        }
        while(rightBiggerIndex < heights.size() && heights[rightBiggerIndex] <= heights[minIndex]){
            rightBiggerIndex++;
        }
        // 分别计算当前，左边，右边的面积，取最大值
        int curArea = (end - start + 1) * heights[minIndex];
        int leftArea = caculateArea(heights, start, leftBiggerIndex);
        int rightArea = caculateArea(heights, rightBiggerIndex, end);
        return max(curArea, max(leftArea, rightArea));
    }
};
```
