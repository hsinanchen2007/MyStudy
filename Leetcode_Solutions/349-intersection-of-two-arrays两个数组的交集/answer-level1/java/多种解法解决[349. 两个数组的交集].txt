#### 349. 两个数组的交集 Easy
> 最近在刷二分的题，找到这一题，做个总结，二分的复杂度并不低，不是最优解
#####  方法1：Set（题解中出现最多的）
```java []
 public int[] intersection(int[] nums1, int[] nums2) {
        if (nums1 == null || nums1.length == 0 || nums2 == null || nums2.length == 0) {
            return new int[0];
        }
        Set<Integer> parentSet = new HashSet<>();
        Set<Integer> childSet = new HashSet<>();
        for (int num : nums1) {
            parentSet.add(num);
        }
        for (int num : nums2) {
            if (parentSet.contains(num)) {
                childSet.add(num);
            }
        }
        int[] resArr = new int[childSet.size()];
        int index = 0;
        for (int value : childSet) {
            resArr[index++] = value;
        }
        return resArr;
    }
```
```python []
print('Hello world!')
```




##### 方法2：双指针
1. 先将`nums1` 与`nums2` 排序，然后游走两个指针，情况都写出来了，没有用`else`
2. 时间复杂度：`O(nlogn)`



```java []
public int[] intersection(int[] nums1, int[] nums2) {
    Set<Integer> set = new HashSet<>();
    Arrays.sort(nums1);
    Arrays.sort(nums2);
    int i = 0, j = 0;
    while (i < nums1.length && j < nums2.length) {
        if (nums1[i] == nums2[j]) {
            set.add(nums1[i]);
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        }
    }
    int[] res = new int[set.size()];
    int index = 0;
    for (int num : set) {
        res[index++] = num;
    }

    return res;
}
```
```python []
print('Hello world!')
```




##### 方法3：二分查找
1. 将`nums2`排序，然后查找`nums1`的元素，需要准备一个`binarySearch`的辅助方法，注意`left <= right`
```java []
public int[] intersection(int[] nums1, int[] nums2) {
    Set<Integer> set = new HashSet<>();
    Arrays.sort(nums2);
    for (int target : nums1) {
        if (binarySearch(nums2, target) && !set.contains(target)) {
            set.add(target);
        }
    }
    int index = 0;
    int[] res = new int[set.size()];
    for (int num : set) {
        res[index++] = num;
    }
    return res;
}


public boolean binarySearch(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return true;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
    }
    return false;
}
```
```python []
print('Hello world!')
```

---
---

#### **更多内容，欢迎订阅**
- **微信公众号:阿飞算法**
- **github(求个star):[geek-algorithm-leetcode](https://github.com/wat1r/geek-algorithm-leetcode)**
![qrcode_for_gh_76cb721bf802_258.jpg](https://pic.leetcode-cn.com/3a58c16558d9218298013dac7197caa816120e478f0f0ed1be2e2bd205395d56-qrcode_for_gh_76cb721bf802_258.jpg)