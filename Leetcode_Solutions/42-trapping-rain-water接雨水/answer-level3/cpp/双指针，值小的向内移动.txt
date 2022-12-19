### 解题思路
        从两边向中间夹，小的指针向内移并加上差值；
![image.png](https://pic.leetcode-cn.com/0ff3362faf00bd0acdce2014fee9ce240da7e31baaeb03789b901b7b034c02d5-image.png)


### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,j=height.size()-1;  //声明左右指针
        int compare=0,count=0;     //当前比较值和计数
        
        while(i<j){         //i小于j循环继续
            while(i<j&&height[i]<=compare)  //左值小于比较值
                count+=compare-height[i++]; //加上差值
            while(i<j&&height[j]<=compare) //右值小于比较值
                count+=compare-height[j--]; //加上差值
            compare=min(height[i],height[j]); //重新判断较小值
        }
        return count;
    }
};
```