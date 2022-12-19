### 解题思路
双指针法

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int *p=&height[0];//取首地址
        int *q=&height[height.size()-1];//取尾地址
        int interval_max=height.size()-1;//最大的间隔
        int maxarea=0;
        while(interval_max>=1)//间隔大于等于1作为循环条件
        {
            maxarea=min(*p,*q)*interval_max>maxarea?min(*p,*q)*interval_max:maxarea;
            if(*p<=*q) p++;
            else q--;
            interval_max--;
        }
        return maxarea;
    }
};
```