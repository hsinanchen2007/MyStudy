1.暴力法：
从每个点开始，遍历所有点，看能够构成的所有矩阵；存在大量重复计算。
举例说明：
[2,1,5,6,2,3]
1.从2开始：2 2-1 2-1-5 2-1-5-6 2-1-5-6-2 2-1-5-6-2-3 取所有组合的最小值
2.从1开始：1 1-5 1-5-6 1-5-6-2 1-5-6-2-3 取所有组合的最小值
依次遍历所有的矩阵图形组合
单次最大面积为minheight*(j-i);然后取最大值；


```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0;
        for (int i = 0; i < heights.size();i++){
            int minheight = heights[i];
            int sum = 0;
            for (int j = i; j < heights.size();j++){
                minheight = min(minheight, heights[j]);
                sum = minheight *(j - i + 1);
                maxarea = max(maxarea, sum);
            }
        }

        return maxarea;
    }
};
```




2.枚举所有矩形：单调栈
1）**以height[i]为高度的矩形集合的最大面积是由低于height[i]的左右两个边界left和right决定的**。
2）在边界之内的矩形面积一定小于height[i]x(right-left)，因此该公式计算面积最大。 height[i]>height[right] && height[i]>height[left],因此问题转化为求left和right边界；
3）使用单调递增栈，查找每个元素的left和right；
当height[i]>=栈顶元素height[j]时，则入栈i；如果height[i]<栈顶元素时，则出栈；
此时，我们得到了栈顶元素j的left和right，left是栈顶-1的元素；right则是i。
因此对于height[j]的最大面积就是height[j]*(right-left)，其中right是i，left是栈顶减1的元素；

**4）为了避免栈为空，我们需要在栈底加入哨兵 -1；
5）为了避免遍历到最后单调栈中元素无法弹出，我们在height的末尾添加0，强制所有元素弹出。**
举例说明：
当i为2时；
栈中是1,5,6的坐标。
height[i]<6，6的left是5，right是2，因此可以计算得到6的面积，同时弹出6
height[i]<5,5的left是1，right是2，因此可以计算得到5的面积 = 2*5

![image.png](https://pic.leetcode-cn.com/84c4ee79017e3f16ca18743273f5e651bdefd83edce1ca8c5d3fff6c8fecf176-image.png)



```cpp
class Solution {
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxarea = 0;

        deque<int> buff;
        buff.push_front(-1);

        heights.push_back(-1);

        for (int i = 0; i < heights.size(); i++) {
            while (buff.front() != -1 && heights[i] < heights[buff.front()]) {
                int length = heights[buff.front()];
                buff.pop_front();

                int area = length * (i - buff.front() - 1);
                maxarea = max(maxarea, area);
            }

            buff.push_front(i);
        }

        return maxarea;
    }
};
```
