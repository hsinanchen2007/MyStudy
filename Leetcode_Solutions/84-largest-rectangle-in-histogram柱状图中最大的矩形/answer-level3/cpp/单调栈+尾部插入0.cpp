### 解题思路
首先这道题要有单调栈的思想。
我们以[2,1,5,6,2,3]对应的下标为[0,1,2,3,4,5]
我们将2的下标0入栈，1的下标1入栈，我们发现1比2小，说明高度为2的矩阵到此为止了，2后面的高度为1，前面犹如没有高度入栈，我们暂时不讨论①。
将2出栈之后，将1，5，6的下标1，2，3入栈，入栈之后2的下标4入栈由于系统采用单调栈，所以栈顶元素为6，前一个元素的下标就是左边第一个小于6的位置，右边2的下标就是右边第一个小于6的位置，两个下标之间的宽度就是高度为6的矩阵的宽度，显然宽度为（4-2）-1，再乘上高度6就可以得到答案。
所以，回过头去看①，为了同意计算面积的公式，我们就把第一个入栈元素之前将-1加入栈底部，这样可以同意公式。
当所有的逆序的情况被计算之后，栈中会出现一个有序数列1，2，3对于下标为1，4，5.这时候我们还需要计算这个顺序序列的结果，如果重新构筑算法会是的代码很麻烦，所以我们在序列末尾加上一个数字0，这样是的1，2，3，0可以按照之前的计算法则进行计算机。
总结一句话就是，栈低加-1，序列尾部加0的方法。

### 代码

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0) return 0;
        heights.push_back(0);
        stack<int> sta;
        sta.push(-1);//将-1定位单调栈的哨兵
        sta.push(0);
        int maxs=0,cur,i=1,temp;
        for(i;i<heights.size();i++)  
        {
            if(heights[i]<heights[sta.top()])
            {
                while(sta.top()!=-1&&heights[sta.top()]>heights[i]){ 
              
              cur=heights[sta.top()];
              sta.pop();
              maxs=max(maxs,cur*(i-sta.top()-1));             
                }
            }
            sta.push(i);
        }
        return maxs;
    }
};
```