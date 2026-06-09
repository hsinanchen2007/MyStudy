### 解题思路
此处撰写解题思路
双指针，指针的运动取决于两个指针的大小关系。
例如：height[i] < hetght[j],根据面积的计算公式area = min(height[i], height[j]) * (j-i)，是由它们当中较小的一个作为高，(j-i)作为宽，进行计算。
这个计算结果意味着，在i不变的情况下，所有的i和j的组合所计算出的面积，都只能小于等于area。为什么？因为无论j等于几，高都等于小于等于height[i], 宽度都小于(j-i)。
因此，此后无需再考虑存在i的情况，i指针向尾部移动。
对于j也是一样的道理。

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxa = 0, tmpa = 0;
        int i(0), j(height.size()-1);
        while(i < j){
            tmpa = area(height, i, j);
            if(tmpa > maxa){
                maxa = tmpa;
            } 
            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
        }
        return maxa;
    }
    //用来计算给定的i和j对应的面积
    int area(vector<int>& height, int start, int end){
        return min(height[start], height[end]) * (end - start);
    }
};
```