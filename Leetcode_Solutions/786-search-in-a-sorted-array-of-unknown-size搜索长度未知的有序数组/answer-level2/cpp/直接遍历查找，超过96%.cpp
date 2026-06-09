

不要跟我说什么二分查找，什么O(log(N))，直接线性遍历一把梭！

线性遍历，如果ArrayReader不结束，那么一直向后查找，忽略掉题目给出的数组是有序的特征。

这样时间复杂度是O(N)，事实证明题目给出的ArrayReader长度不长，下面的做法超过了96%的提交。

C++代码如下：

```cpp
// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int index = 0;
        while (reader.get(index) != 2147483647) {
            if (reader.get(index) == target)
                return index;
            index ++;
        }
        return -1;
    }
};
```