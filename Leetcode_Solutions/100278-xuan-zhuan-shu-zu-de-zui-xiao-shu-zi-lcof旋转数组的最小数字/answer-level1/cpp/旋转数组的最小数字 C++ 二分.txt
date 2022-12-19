### 解题思路
参考《剑指offer》

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        /* return func(nums, 0, nums.size() -1); */
        int left = 0;
        int right = numbers.size() - 1;
        
        while(left < right){
            int mid = left + (right - left) / 2;
            if(numbers[right] == numbers[mid] && numbers[left] == numbers[right]){
                // 当前中后的元素都相等时，无法判断最小值处在哪个序列，这时通过直接遍历寻找最小值
                return minArray(numbers, left, right);
            }
            else if(numbers[right] < numbers[mid]){
                // 如果右侧升序子序列的最大值比中间值小，说明中间值在左侧升序子序列（如果mid在右序子序列的话一定比右侧最大值小）
                // 那么最小值出现在mid右侧，并且不包含mid
                left = mid + 1;
            }
            else{
                // 否则最小值在左侧子序列，最小值可能包含mid
                right = mid;
            }
        }
        return numbers[left];
    }

    int minArray(vector<int>& numbers, int left, int right){
        int min = INT_MAX;
        for(int i = left; i <= right; ++i){
            if(min > numbers[i]){
                min = numbers[i];
            }
        }
        return min;
    }
};
```