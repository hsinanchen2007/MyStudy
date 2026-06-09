### 解题思路
![微信图片_20200318111240.png](https://pic.leetcode-cn.com/24f2927d48963ad055b3315fa7dc568f47c24a574af2ef329285c41d01a2bef8-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200318111240.png)
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec2[0]>=rec1[2]||rec2[1]>=rec1[3])
            return false;
        else if(rec2[2]<=rec1[0]||rec2[3]<=rec1[1])
            return false;
        else
            return true;
    }
};
```