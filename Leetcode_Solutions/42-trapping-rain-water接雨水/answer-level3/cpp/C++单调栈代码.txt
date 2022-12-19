### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stack_height;        //单调栈
        int nums=0;

        for(int i=0;i<height.size();i++)
        {
            while(!stack_height.empty()&&height[i]>height[stack_height.top()])       //如果当前元素比栈顶元素大，能接住水,一直计算下去
            {
                int temp=stack_height.top();
                stack_height.pop();
                while(!stack_height.empty()&&height[temp]==height[stack_height.top()]) //如果前面的栈顶元素是相等的，无法形成高度差，均移除
                    stack_height.pop();

                if(!stack_height.empty())   //如果把栈的元素全部移除了，就无法进行计算
                {
                    //增加的数量是当前栈顶柱体高度和当前检查柱体高度中的较小值，乘上当前栈顶柱体到当前检查柱体的距离。
                    nums+=((std::min(height[stack_height.top()],height[i])-height[temp])*(i-stack_height.top()-1));
                }
            }
            //计算完毕后（无论是否接得住雨水）当前元素入栈
            stack_height.push(i);
        }
        return nums;
    }
};
```