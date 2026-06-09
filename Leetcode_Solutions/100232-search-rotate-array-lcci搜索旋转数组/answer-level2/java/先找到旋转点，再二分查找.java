# 思路
先二分法找到旋转点。找旋转点可参考[旋转数组的最小数字](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)
找到旋转点后原数组就可看为2段有序数组拼接在一起。
利用数组的有序区间进行二分查找即可。

# 代码
```java
class Solution {
    public int search(int[] arr, int target) {
        int len = arr.length, low = 0, high = len - 1;
        while (low < high) {
            int mid = (low + high) >> 1;
            if (arr[mid] == arr[low] && arr[mid] == arr[high]) {
                ++low;
                --high;
            } else if (arr[mid] == arr[high]) --high;
            else if (arr[mid] < arr[high]) high = mid;
            else low = mid + 1;
        }
        int idx = Arrays.binarySearch(arr, 0, low, target);
        if (idx >= 0) {
            while (idx > 0 && arr[idx - 1] == target)
                --idx;
            return idx;
        }
        idx = Arrays.binarySearch(arr, low, len, target);
        if (idx >= 0) {
            while (idx > 0 && arr[idx - 1] == target)
                --idx;
            return idx;
        }
        return -1;
    }
}
```
