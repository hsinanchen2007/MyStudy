### 解题思路
其实很简单：
两个矩阵的各个边比大小。 
左边的边取大的，右边的边取小的。
上边的边取小的， 下边的取大的。
按照上面的规则获取的数据如果能够构成一个矩阵，那就说明相交了。
--关键从一般情况中抽象出规律后验证下。

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = max(rec1[0],rec2[0]);
        int y1 = max(rec1[1],rec2[1]);
        int x2 = min(rec1[2],rec2[2]);
        int y2 = min(rec1[3],rec2[3]);
        // 判断是否是一个矩阵
        if ((x1 < x2) && (y1 < y2)){
            return true;
        }
        return false;
    }
};
```