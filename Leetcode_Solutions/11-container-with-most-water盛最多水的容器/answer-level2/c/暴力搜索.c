### 解题思路
暴力搜索
因为是容器盛水，高要取两个高度之间小的那个
面积求最大的
内存消耗不高，但是时间消耗很高

### 代码

```c
int maxArea(int* height, int heightSize){
    int max=0;
    int area=0;
    for(int i=0;i<heightSize-1;i++)
    {
        for(int j=i+1;j<heightSize;j++)
        {
            int min=height[i]<height[j]?height[i]:height[j];
            area=(j-i)*min;
            if(area>max)
                max=area;
        }
    }
    return max;
}
```