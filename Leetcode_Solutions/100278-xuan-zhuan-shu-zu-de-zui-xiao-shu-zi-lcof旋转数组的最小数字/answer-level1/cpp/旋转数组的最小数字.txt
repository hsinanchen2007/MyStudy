### 解题思路
考虑二分法，遍历没灵魂；
最主要思想就是根据有序性找左右分治，另外相等的时候需要考虑右边逐个去重收缩。

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int num_size = numbers.size();
        int left = 0, right = num_size - 1;
        if (numbers[left] < numbers[right]) {
            return numbers[left];
        }
        while (left < right) {
            int mid_index = (left + right) / 2;
            if (numbers[mid_index] > numbers[right]) {
                left = mid_index + 1;
            } else if (numbers[mid_index] < numbers[right]) {
                right = mid_index;
            } else {
                right--;
            }
        }
        return numbers[left];
    }
};
```