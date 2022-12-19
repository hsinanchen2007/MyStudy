### 解题思路
考虑每个柱子为最高柱子对答案的贡献,就是看这个柱子往左能domain多少个单位
往右能domain多少个单位。
遇到比它小的为止
遍历所有的柱子为最高柱子的情况.
就能够覆盖到所有的矩形了。

也即枚举一个位置然后如果比它高就一直扩展,往左往右各做一次就好。
这样的时间复杂度是O(N^2)的

我们可以维护一个单调递增的队列。
这个队列里面第i个元素和第i-1个元素
假设他们原来在数组里的位置是
ii和jj
显然min(ii+1,jj)..jj这一段里面的柱子都是比i元素也即在原来中的jj位置的柱子
来得高的。
同时单调队列栈顶的元素所在的位置设为kk
jj..kk这一段的柱子显然也是全都高于jj
所以贡献就能算出来了。
(sta[top]-sta[cur-1])*height[sta[cur]];
对于每一个算贡献的cur,显然没必要再往右扩展了。
因为算这个答案的时候,实际上。就是因为遇到了一个比栈顶的元素矮的柱子。
那每个比它高的柱子,刚好就不能再继续往右扩展了。
因此算法是正确的。

这题的关键就在于,想到枚举每个柱子是最高元素,然后往左往右扩展这一步。
从而联想到利用单调队列的性质。加速这个找最左最右的过程。

### 代码

```cpp
class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int sta[100000+10];
        int top = 0;
        int ans = 0;
        sta[0] = -1;
        for (int i = 0;i < (int)heights.size();i++){
            if (top==0 || heights[i]>=heights[sta[top]]){
                sta[++top] = i;
            }else{
                while (top>0 && heights[i]<heights[sta[top]]){
                    ans = max(ans,((i-1)-sta[top-1])*heights[sta[top]]);
                    top--;
                }
                sta[++top] = i;
            }
            //             for (int j = 1;j<=top;j++){
            //     cout<<sta[j]<<" ";
            // }
            // cout<<endl;
        }
        while (top>0){
            ans = max(ans,((int)heights.size()-1-sta[top-1])*heights[sta[top]]);
            top--;
        }
        return ans;
    }
};
```