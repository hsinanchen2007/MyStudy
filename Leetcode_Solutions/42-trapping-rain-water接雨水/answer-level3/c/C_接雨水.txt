### 解题思路
参考官方题解：双指针法

### 代码

```c
int trap(int* height, int heightSize){
    int left=0,right=heightSize-1,maxLeft=-1,maxRight=-1,result=0;
    while(left<right)
        if(height[left]<height[right])
        {
            if(height[left]>=maxLeft)
                maxLeft=height[left];
            else
                result+=(maxLeft-height[left]);
            ++left;
        }
        else
        {
            if(height[right]>=maxRight)
                maxRight=height[right];
            else
                result+=(maxRight-height[right]);
            --right;
        }
    return result;
}
```