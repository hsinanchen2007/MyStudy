数组 nums
左边界 left   a = nums[left]
右边界 right  b = nums[right]
当前面积 （right - left) * min(a, b)
假设a < b(a > b同理)，下一次不管移动left还是right，长度为(right - left - 1)，关键看高度
移动left，高度为min(c, b)，c与a比较三种关系都可能存在(<,>,=)
移动right，高度为min(a, c)，c与b比较三种关系都可能存在(<,>,=)，由于a < b，所以min(a, c) <= a，面积一定变小
也就是说，移动高边界，长度一定减小，高度受限于低边界，面积一定减小
```c
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int min(int a, int b) {
  if (a > b) {
    return b;
  }
  return a;
}

int maxArea(int *height, int heightSize) {
  int ans = 0;
  int l = 0;              //左边界
  int r = heightSize - 1; //右边界
  while (l < r) {
    ans = max(ans, (r - l) * min(height[l], height[r]));
    height[l] < height[r] ? l++ : r--;
  }
  return ans;
}
```
