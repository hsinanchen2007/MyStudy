![image.png](https://pic.leetcode-cn.com/7a881a26db42ee11cdab3a7c9618d9564efe8a8f5e419f8e62a3f83bbe1ef906-image.png)
![image.png](https://pic.leetcode-cn.com/888b3b31a7ada3578cb7cb914230356be4b63515d6933a1d08765c89356a1c32-image.png)
参数中的数据是一个旋转排序数组，所以数据的分布如图所示，分成了两段的有序数组，那么我们对这两段的数据分开执行二分查找，就可以得到答案。
（代码有点繁琐，望包涵）
```
if (target > nums[nums.length - 1] && target < nums[0]) return -1;//如果target的值在坐标图中的红色区域，那么直接返回-1
        if (target >= nums[0]) {//target的值在前半段有序数组（即a点开头的那段）
            int low = 0, high = nums.length - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (nums[mid] < nums[0]) {//如果mid下标对应的值在后半段，就把high的值改为mid减1，继续查找
                    high = mid - 1;
                    continue;
                }
                if (nums[mid] < target) {
                    low = mid + 1;
                    continue;
                }
                if (nums[mid] > target) {
                    high = mid - 1;
                    continue;
                }
                if (nums[mid] == target) {
                    return mid;
                }
            }
            return -1;
        } else {//target的值在后半段有序数组（即b点结尾的那段）
            int low = 0, high = nums.length - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (nums[mid] > nums[nums.length - 1]) {//如果mid下标对应的值在前半段，就把low的值改为mid加1，继续查找
                    low = mid + 1;
                    continue;
                }
                if (nums[mid] < target) {
                    low = mid + 1;
                    continue;
                }
                if (nums[mid] > target) {
                    high = mid - 1;
                    continue;
                }
                if (nums[mid] == target) {
                    return mid;
                }
            }
            return -1;
        }
```

