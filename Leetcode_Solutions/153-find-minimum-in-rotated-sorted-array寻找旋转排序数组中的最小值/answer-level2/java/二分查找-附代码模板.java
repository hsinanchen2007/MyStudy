### 二分查找
时间复杂度 O(lgN)

### 代码模板
1. 求左右边界，即：left 和 right
```
int left = 0;
int right = nums.lenght - 1;
```
2. 循环
```
while (left < right) {
}
```
3. 求中间坐标，即：mid
```
int mid = left + (right - left) / 2;

PS：注意此处mid计算方式，目的是为了防止在强类型语言中出现溢出的bug
```
4. 条件判断
```
if (nums[mid] == target) { // 找到结果，循环结束
    break;
} else if (nums[mid] < target) {
    left = mid + 1;
} else {
    right = mid - 1;
}

PS：此处逻辑根据题目需求灵活变通即可
```

### 参考代码模板，代码如下：
```
public int findMin(int[] nums) {
    // 边界条件判断
    if (nums == null || nums.length == 0) {
        return Integer.MIN_VALUE;
    }

    int result = nums[0];
    int left = 0, right = nums.length - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[left] > nums[right]) {
            result = nums[right];

            if (nums[mid] < nums[right]) {
                right = mid - 1;
                result = nums[mid];
            } else {
                left = mid + 1;
            }
        } else {
            right = mid - 1;
            result = nums[left];
        }
    }

    return result;
}

```
