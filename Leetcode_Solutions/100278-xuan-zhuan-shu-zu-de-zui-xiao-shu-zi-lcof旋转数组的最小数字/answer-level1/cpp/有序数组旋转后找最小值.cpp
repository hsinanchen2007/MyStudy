### 解题思路
此处撰写解题思路
从开头遍历数组一直找到第一个比[0]元素小的元素就是最小值时间复杂度为O(n) 一般不会到n 空间复杂度为O(1)

### 代码

```cpp
#include <climits>

class Solution {
public:
    int minArray(vector<int>& numbers) {
        // 这里numbers 必须有两个以上的元素 否则长度为0 不是递增数组 长度为1 无法旋转 
        int MinNum = numbers[0];
        for(int i=1;i<numbers.size();i++)
        {
            if(numbers[i]< MinNum)
            {
                MinNum = numbers[i];
                break;
            }
        }
        return MinNum;
    }
};
```