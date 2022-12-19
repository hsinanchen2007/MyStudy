### 解题思路
执行用时:87.33%
内存消耗:100%
用两个指针从两边向中间逼近，直到两个指针相交，每次取两者指向元素小的那一个作为桶高，
如果左边小，那么左边往右移动看是否有更大的，否则相反

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;//数组开始位置
        int j = height.size() - 1;//数组末尾
        int max = 0;//最大值
        int count = 0;//两者的距离
        while (i<j)
        {
###            if(height[i]<height[j]){
                count = (j - i)*height[i];//距离乘桶高
                i++;//如果左边小左边右移，寻找更大的情况
            }else{
                count = (j - i)*height[j];//同上
                j--;
            }
            max = max>count?max:count;
        }
        return max;
    }
};
```
