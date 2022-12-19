### 解题思路
此处撰写解题思路
![1247.jpg](https://pic.leetcode-cn.com/8a4f897d2ae91a1ae6c0f63a8d1be042c718456a43b6152afa4b579fb9a83022-1247.jpg)

### 代码

```cpp
//x->y ++
//y->x ++
//两者数量相比较
//相等的部分除以2
//多的部分2的倍数皆可消
//其他的-1

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x_y = 0;
        int y_x = 0;
        for(int i = 0; i < s1.size(); ++i)
        {
            if(s1[i] == s2[i]) continue;
            if(s1[i] == 'x') x_y++;
            else y_x++;
        }

        if(x_y%2 == 0 && y_x%2 == 0) return (x_y+y_x)/2;
        if(x_y%2 == 1 && y_x%2 == 1) return (x_y-1+y_x-1)/2+2;
        else return -1;
    }
};









```