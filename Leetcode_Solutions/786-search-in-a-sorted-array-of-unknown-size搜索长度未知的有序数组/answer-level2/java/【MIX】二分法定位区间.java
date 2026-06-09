### 解题思路
需要添加头文件`#include <unistd.h>`, 二分查找

### 代码

```java []
class Solution {
    public int search(ArrayReader R, int T) {
        int preIndex = 0;
        int index = 1;
        if(R.get(preIndex) == T)
            return preIndex;
        // 先4倍扩张
        while(R.get(index) != P && R.get(index)<=T){
            preIndex = index;
            index *= 4;
        }
        
        return binarySearch(R, T, preIndex, index);
    }

    private int binarySearch(ArrayReader R, int T, int start, int end){
        while(start<end){
            int mid = start + ((end-start)>>1);
            if(R.get(mid) == T)
                return mid;
            else if(R.get(mid) < T)
                start = mid+1;
            else
                end = mid;
        }

        return -1;
    }

    private static int P = Integer.MAX_VALUE;
}
```
```python []
class Solution:
    def search(self, reader, target):
        """
        :type reader: ArrayReader
        :type target: int
        :rtype: int
        """
        preindex, index = 0, 1
        if reader.get(preindex) == target:
            return preindex

        P = 2**31-1
        while reader.get(index) != P and reader.get(index) <= target:
            if reader.get(index) == target:
                return index
            preindex = index
            index *= 4

        start, end = preindex, index
        while start < end:
            mid = start + ((end-start)>>1)
            if reader.get(mid) == target:
                return mid
            elif reader.get(mid) < target:
                start = mid+1
            else:
                end = mid

        return -1
```
```c++ []
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

#include <unistd.h>

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        // 使用二分查找法, 时间复杂度为O(lg K)
        int index = 1;
        int preIndex = 0;
        const int P = INT32_MAX;
        while(reader.get(index) != P && reader.get(index) <= target){
            if(reader.get(index) == target)
                return index;
            else{
                preIndex = index;
                index *=2;
            }
        }

        // 是否为起始元素
        if(index == 1){
            if(reader.get(preIndex)==target)
                return preIndex;
            else
                return -1;
        }

        // 在区间preIndex ~ index之间, 进行二分搜索
        return binarySearch(reader, target, preIndex, index);
    }

private:
    int binarySearch(const ArrayReader& R, const int &T, int start, int end){
        while(start < end){
            int mid = start+((end-start)>>1);
            if(R.get(mid) == T){
                return mid;
            }
            else if(R.get(mid) < T){
                start = mid+1;
            }
            else{
                end = mid;
            }
        }
        return -1;
    }
};
```