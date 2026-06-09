### 解题思路
此处撰写解题思路
使用线性存储空间在遍历上有o(1)的时间复杂度，但是这里还是有o(n)的空间复杂度 如果vector的size足够小 其实很浪费空间
而unordered_set其实如果hashtable足够大最后也会退化成数组或者vector只是每次查找都会有一个计算hash的PC计数器跳转开销。
应该还可以找到更好的方法。

### 代码

```cpp
#include <unordered_set>

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return -1;
        }
        
        int arr[100000] = {0};
        for(int num : nums)
        {
            if(arr[num] == 1)
            {
                return num;
            }
            arr[num] = 1;
        }

        return -1;
    }
};
```