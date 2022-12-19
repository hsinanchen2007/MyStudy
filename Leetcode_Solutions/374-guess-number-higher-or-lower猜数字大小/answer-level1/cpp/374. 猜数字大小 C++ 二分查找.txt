### 解题思路
简单二分查找

模板：https://leetcode-cn.com/explore/learn/card/binary-search/209/template-i/835/
```cpp
int binarySearch(vector<int>& nums, int target){
  if(nums.size() == 0)
    return -1;

  int left = 0, right = nums.size() - 1;
  while(left <= right){
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid - 1; }
  }

  // End Condition: left > right
  return -1;
}
```

### 代码

```cpp
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {

        int left = 1;
        int right = n;
        int mid = 0;
        while(left<=right){
            mid = left + (right - left) / 2;
            int guessres = guess(mid);
            if(guessres == 0){
                return mid;
            }else if (guessres <0){
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }

        return -1;
    }
};
```