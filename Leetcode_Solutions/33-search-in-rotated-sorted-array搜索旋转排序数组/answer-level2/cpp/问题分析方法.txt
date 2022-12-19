## 简介
对于这个题目， logN就想到了二分法，对于二分法就是两个左右分支（**大问题**）+ 边界情况（**小问题**）
### 大问题求解
![image.png](https://pic.leetcode-cn.com/eee25522e926fdff585238d8424c08910e630551aabbcde4f7d740bab9e504df-image.png)

![image.png](https://pic.leetcode-cn.com/5055a165ea44482185e234608f573d1e8b737c6e8f2e9335771352df6dfa450e-image.png)

![image.png](https://pic.leetcode-cn.com/109f8d3c972d061e3ce073f2ddc924cf089e76956170dd8c7b35e869a8091752-image.png)

### 边界情况
`nums[mid] == nums[0]` 这种情况下，只有两个元素, 如果 `nums[0] != target` 走右侧。

## 源码
```cpp

class Solution {
public:
  int search(vector<int> &nums, int target) {

    int left_ptr = 0, right_ptr = nums.size() - 1;
    cout << left_ptr << ", " << right_ptr << endl;

    while (left_ptr < right_ptr) {
      int mid_ptr = (left_ptr + right_ptr) / 2;

      // [mid] > [0]
      //   cout << "tar:" << target << ",mid:" << nums[mid_ptr]
      //        << ",l:" << nums[left_ptr] << ",r:" << nums[right_ptr] << endl;
      if (nums[mid_ptr] >= nums[0] &&
          (target > nums[mid_ptr] || target < nums[0])) {
        left_ptr = mid_ptr + 1;
        // cout << "right" << endl;
      } else if (nums[0] > target && target > nums[mid_ptr]) {
        left_ptr = mid_ptr + 1;
        // cout << "right" << endl;
      } else {
        right_ptr = mid_ptr;
        // cout << "left" << endl;
      }
    }
    // cout << left_ptr << ", " << right_ptr << endl;

    if (left_ptr == right_ptr && nums[left_ptr] == target) {
      return left_ptr;
    }
    return -1;
  }
};
```


