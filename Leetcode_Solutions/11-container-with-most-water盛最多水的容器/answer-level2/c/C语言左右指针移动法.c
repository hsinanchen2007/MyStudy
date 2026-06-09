### 解题思路

遇事不绝先暴力，发现暴力又喜闻乐见的超出时间限制了。于是学习了先进经验，采用左右指针的方法。

先将指针固定到两端，然后谁的高度小，谁先往里面动。因为小的往里移动可能会遇到高的，那么面积会大一点，但是大的往里移动遇到小的，那就不合算了。

### 代码

```c

//双指针，移动法
int maxArea(int* height, int heightSize){

    if ( heightSize < 2) return 0;

    int left = 0 ;
    int right = heightSize - 1;
    int minHeight = 0;
    int max_area = 0;

    while ( left < right) {
        minHeight = height[left] >  height[right] ? height[right] : height[left];
        if ((right - left ) * minHeight > max_area ) {
            max_area = (right - left ) * minHeight;
        }
        //谁小谁先动
        if (height[left] < height[right]){
            left++;
        } else{
            right--;
        }
        
    }
    return max_area;
}


```