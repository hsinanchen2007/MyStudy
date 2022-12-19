### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //以rec1为基准，判断rec2与rec1关系
        if(rec2[2]<=rec1[0]||rec2[0]>=rec1[2]||rec2[1]>=rec1[3]||rec2[3]<=rec1[1]){
            return false;
        }

        if(rec1[2]<=rec2[0]||rec1[0]>=rec2[2]||rec1[1]>=rec2[3]||rec1[3]<=rec2[1]){
            return false;
        }
        
        return true;
    }
};
```