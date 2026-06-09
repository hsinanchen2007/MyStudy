### 解题思路
此处撰写解题思路
二分查找法 之前也想到了但是 2,2,2,2,2,1,2 和 2,1,2,2,2,2,2 这种刚开始没想到怎么处理 后来参看了别人的方法 发现直接RIndex-- 即可。
时间复杂度为O(logn) 空间复杂度为O(1)

### 代码

```cpp
#include <climits>

class Solution {
public:
    int minArray(vector<int>& numbers) {
       int MinNum = INT_MAX;
       int LIndex = 0, RIndex = numbers.size()-1 , MIndex = 0;
       while(LIndex < RIndex)
       {
           MIndex = (LIndex + RIndex) / 2;
           if( numbers[MIndex] < numbers[RIndex])
           {
               RIndex = MIndex;
           }else if(numbers[MIndex] > numbers[RIndex])
           {
               LIndex = MIndex + 1;
           }else
           {
               RIndex --;
           }
       }

       return numbers[LIndex];
    }
};
```