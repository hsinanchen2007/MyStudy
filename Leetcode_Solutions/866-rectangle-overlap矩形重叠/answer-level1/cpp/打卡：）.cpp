### 解题思路
1. 写得有点丑陋，哈哈
2. 主要分享一下思路：
3. 如果rec1的四个点在rec2的范围里，必重叠
4. 除此之外，还存在十字型的重叠
![image.png](https://pic.leetcode-cn.com/f28da7ef6359fdf984bce92802bbad8444fb73feb00dc0f29e7c0495065d7cbe-image.png)

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[2]<=rec2[2]&&rec1[3]<=rec2[3])
        {
            if(rec1[2]>rec2[0]&&rec1[3]>rec2[1]) return true;
        }
         if(rec1[0]>=rec2[0]&&rec1[1]>=rec2[1])
        {
            if(rec1[0]<rec2[2]&&rec1[1]<rec2[3]) return true;
        }
         if(rec1[2]>rec2[0]&&rec1[1]>=rec2[1])
        {
            if(rec1[2]<=rec2[2]&&rec1[1]<rec2[3]) return true;
        }
         if(rec1[0]>=rec2[0]&&rec1[3]>rec2[1])
        {
            if(rec1[0]<=rec2[2]&&rec1[3]<rec2[3]) return true;
        }

//        //
        if(rec2[2]<=rec1[2]&&rec2[3]<=rec1[3])
        {
            if(rec2[2]>rec1[0]&&rec2[3]>rec1[1]) return true;
        }
         if(rec2[0]>=rec1[0]&&rec2[1]>=rec1[1])
        {
            if(rec2[0]<rec1[2]&&rec2[1]<rec1[3]) return true;
        }
         if(rec2[2]>rec1[0]&&rec2[1]>=rec1[1])
        {
            if(rec2[2]<=rec1[2]&&rec2[1]<rec1[3]) return true;
        }
         if(rec2[0]>=rec1[0]&&rec2[3]>rec1[1])
        {
            if(rec2[0]<=rec1[2]&&rec2[3]<rec1[3]) return true;
        }

        if(rec1[0]>=rec2[0]&&rec1[2]<=rec2[2])
        {
            if(rec1[1]<=rec2[1]&&rec1[3]>=rec2[3]) return true;
        }
        if(rec2[0]>=rec1[0]&&rec2[2]<=rec1[2])
        {
            if(rec2[1]<=rec1[1]&&rec2[3]>=rec1[3]) return true;
        }
         return false;
        
        
    }
};
```