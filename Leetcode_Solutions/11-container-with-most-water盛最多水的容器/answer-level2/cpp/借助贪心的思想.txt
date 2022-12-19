### 解题思路
不确定算不算贪心算法，不过确实有用到一些思想。思路如下：
因为最终的容量是由短板决定的，因此我们最开始可以算上所有的坐标，得到一个容量，以此作为基点，那么在这样的情况下，决定最终容量的是两个端点的高度，且此时的宽度为最大，要想得到更大的容量，宽度必定减少，因此高度必须增加，因此我们舍弃掉左右端点中较小的值，直到左右端点相等，过程中记录所得最大容量，则达到目标

### 代码

```cpp
class Solution {
public:
    int min(int a,int b){
        return a > b?b:a;
    }
    int maxArea(vector<int>& height) {
        int i = 0,j=height.size()-1;
        int max=0;
        while(i<j){
            int sum=(j-i)*min(height[i],height[j]);
            if(sum > max)
                max = sum;
            if(height[i]>height[j])
                j--;
            else
                i++;
        }
        return max;
    }
};
```