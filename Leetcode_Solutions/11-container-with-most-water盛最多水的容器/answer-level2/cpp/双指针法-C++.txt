### 解题思路
双指针法，定义一个头指针指向vector首元素，在定义一个尾指针指向vector尾元素，从前向后遍历数组，每次取俩个指针中vector数组元素最小的那个数与俩个指针之间的距离即为面积，每次取面积的最大值，遍历完后，取出最大面积值

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int *start=&height[0];//获取vector首地址
        int *end=&height.back();//获取vector尾地址
        int max_area=0;//初始化面积
        for(int i=0;i<height.size();i++)//遍历vector数组
        {
            int high=min(*start,*end);//取最小的高度值
            int area=high*(int)(end-start);//计算面积
            if(*start<*end)
            {
                start++;
            }
            else
            {
                end--;
            }//每次向后遍历取最小高度的元素对应的指针地址向后（前）加一
            if(area>max_area)
            {
                max_area=area;//获取最大面积
            }
        }
        return max_area;
    }
    
};
```