// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
    // 二分查找
    int search(const ArrayReader& reader, int target, int begin, int end) {
        if (begin >= end)
            return -1;
        int mid = (begin + end) / 2;
        if (reader.get(mid) == target)
            return mid;
        if (target < reader.get(mid))
            return search(reader, target, begin, mid);
        return search(reader, target, mid + 1, end);
    }
    
    // 二分法确定数组长度
    int declare_length(const ArrayReader& reader) {
        int minlen = 0;
        int maxlen = 20000;
        while (maxlen - minlen > 1) {
            int index = (minlen + maxlen) / 2;
            if (reader.get(index) > 10000 || reader.get(index) < -10000)  // 越界
                maxlen = index;
            else
                minlen = index;
        }
        return minlen + 1;  // 长度是最后一个元素下标 + 1
    }
    
public:
    int search(const ArrayReader& reader, int target) {
        return search(reader, target, 0, declare_length(reader));
    }
};