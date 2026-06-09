```
public int search(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        //要right这里不能等于，否则left等于right时候可能会死循环
        while (left < right) {
            int mid = (right + left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else {
                // 要right，right的元素就是大于或者等于target的（这里不需要+1，因为我们就要right）
                right = mid;
            }
        }
        return nums[right] == target ? right : -1;
    }
```

```
public int search(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        //要left这里要等于
        while (left <= right) {
            int mid = (right + left) / 2;
            if (nums[mid] <= target)
                // 要left，这里的left是小于或者等于target的最后一个的下一个！
                left = mid + 1;
            else {
                right = mid - 1;
            }
        }
        //left始终没动，且最后一次也没有动，就是第一个数字也不满足
        if (left == 0)
            return -1;
        return nums[left-1] == target ? left-1 : -1;
    }
```

