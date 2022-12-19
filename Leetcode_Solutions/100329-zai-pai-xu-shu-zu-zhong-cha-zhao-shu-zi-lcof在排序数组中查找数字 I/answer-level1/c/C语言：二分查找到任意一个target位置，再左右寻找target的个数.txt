二分查找到任意一个target位置，再左右寻找target的个数
忽略写得比较丑的C语言代码，主要关注算法。

```
int search(int* nums, int numsSize, int target){

    int left = 0;
    int right = numsSize - 1;
    int middle, res;

    if (numsSize <= 0) {
        return 0;
    }

    while (left < right) {
        middle = left + (right - left) / 2;
        if (nums[middle] == target) {
            break;
        } else if (nums[middle] < target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }

    middle = left + (right - left) / 2;
    if (nums[middle] != target) {
        return 0;
    }

    res = 1;
    left = middle - 1;
    while (left >= 0) {
        if (nums[left--] != target) {
            break;
        }
        res++;
    }

    right = middle + 1;
    while (right < numsSize) {
        if (nums[right++] != target) {
            break;
        }
        res++;
    }

    return res;
}
```
![image.png](https://pic.leetcode-cn.com/1f52b8e168d5a43ab6bb05d61f048ff8f477ddf0f8a18ad4a96c8814c4cca77c-image.png)
