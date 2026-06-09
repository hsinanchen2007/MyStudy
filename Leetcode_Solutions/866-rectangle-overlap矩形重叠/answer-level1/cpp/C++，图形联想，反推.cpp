### 解题思路
第二个矩形右上角在第一个矩形的左下角的左下
或者
第二个矩形的左下角在右上角的右上。
在题目假定一定0,1是左下角2,3是右上角的情况下，
一定就不重复了。
这里的左下与右上可分离，即左与下，右与上。
全或, 可得if (func()) return false; return true;
合并 return !func();
### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec2[2] <= rec1[0] || rec2[3] <= rec1[1] || rec2[0] >= rec1[2] || rec2[1] >= rec1[3]);
    }
};
```