
![搜索长度未知的有序数组.JPG](https://pic.leetcode-cn.com/875964463596ba181761caaeeb261f8f9efae3235acf250b9fb1fe13ed3943f4-%E6%90%9C%E7%B4%A2%E9%95%BF%E5%BA%A6%E6%9C%AA%E7%9F%A5%E7%9A%84%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84.JPG)
题目的小难点是没有数组右边界，但注意到即使访问越界也不会崩溃，只会返回一个固定的数，所以我们找到一个超出右边界的数，作为右边界即可。
right初始值设置为1，每次倍增，直到访问越界，如果数组实际长度为N，则这个过程的时间复杂度为O(logN).
之后再使用普通的二分查找，查找target，时间复杂度为O(logN).
```
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int OUT = 2147483647;
        if(reader.get(0) == OUT)
            return -1;
        int left = 0;
        long right = 1;
        //每次right倍增，找到第一个超出数组边界的数，复杂度O(logN)
        while(reader.get(right) != OUT)
            right *= 2;

        //普通二分查找，复杂度O(logN)
        while(left <= right)
        {
            int mid = left + (right - left >> 1);
            if(reader.get(mid) == target)
                return mid;
            else if(reader.get(mid) > target)
                right = mid - 1;
            else if(reader.get(mid) < target)
                left = mid + 1;
        }
        return -1;
    }
};
```
时间复杂度：O(logN)。 查找右边界O(logN), 加上二分查找O(logN)
空间复杂度：O(1)。仅使用常数的额外空间