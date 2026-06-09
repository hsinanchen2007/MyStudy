### 解题思路
边界遍历，参考54题某参考答案

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int top=0,bottom=n-1;
        int left=0,right=n-1;
        int k=1;
        while(true){
            for(int i=left;i<=right;i++) res[top][i]=k++;//向右移动直到最右
            if(++top>bottom) break;//重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            for(int i=top;i<=bottom;i++) res[i][right]=k++;//向下
            if(--right<left) break;//重新设定右边界
            for(int i=right;i>=left;i--) res[bottom][i]=k++;//向左
            if(--bottom<top) break;//重新设定下边界
            for(int i=bottom;i>=top;i--) res[i][left]=k++;//向上
            if(++left>right) break;//重新设定左边界
        }
        return res;
    }
};
```