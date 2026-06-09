### 解题思路
![image.png](https://pic.leetcode-cn.com/4fcdec83950166d859f46919d63144ba3188c5a4402dff95707593c786c8f345-image.png)
此题是我的伤心题。
如果不知道顺时针旋转相当于转置加左右列交换这个小技巧的话，完全没有问题，按照直接的思路交换元素即可，从外框到内框逐次旋转。
值得注意的是，为了方便书写，不是按照整行整列的交换，而是按照单个元素在顺时针旋转过程中能经过的四个位置做一轮交换，总轮数等于当前处理的边框长度。
### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        if(n<2) return;
        
        int layer=0;//当前处理的框
        while(layer<n/2)
        {
            int len = n - layer*2;//每层的框长
            for(int i=0;i<len-1;i++)
            {
                int tmp = matrix[layer][layer+i];
                matrix[layer][layer+i] = matrix[layer+len-i-1][layer];
                matrix[layer+len-i-1][layer] = matrix[layer+len-1][layer+len-i-1];
                matrix[layer+len-1][layer+len-i-1] = matrix[layer+i][layer+len-1];
                matrix[layer+i][layer+len-1] = tmp;
            }
            layer++;
        }

    }
};
```