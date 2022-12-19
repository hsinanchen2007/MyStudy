### 解题思路
此处撰写解题思路
首先通过 每次将右边界*2，来找到右边界不为2147483647的位置，然后启动二分查找，找到目标值 

### 代码

```cpp
// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
      int lo = 0;
      int hi = 1;
      const int invalid = 2147483647;  
      while(reader.get(hi) != invalid){
          hi = hi << 1;
      }
      while(lo < hi)
      {
          int mid = lo + ((hi-lo)/2);
          int val  = reader.get(mid);
          if(val == target) return mid;
          if(val == invalid)
          {
               hi  = mid;
          }
          if(val < target)
          {
              lo = mid+1;
          }
          else
          {
              hi = mid;
          }

      }
      return -1;
    }
};
```