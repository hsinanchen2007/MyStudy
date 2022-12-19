山脉数组的特点就是只有一个峰值，所以思路就是先找出这个峰值；
找出峰值的索引后，剩下的就是一个升序的数组以及一个降序的数组；
完全符合二分法的结题思路。

1. 利用二分法找出这个峰值的索引（当时不知道这种不是完全有序的数组怎么利用二分法进行查找，后面查看了一下作者 @liweiwei1419 的解答，是用 `mountainArr.get(mid)` 与 `mountainArr.get(mid+1)` 相比较，太绝了，佩服佩服！）；
2. 找到峰值后，就可以对左边的升序数组进行二分查找了；
3. 如果升序的数组中没有 target，再对另一个降序的数组进行二分查找。这里要注意一点就是，数组是降序的，在对 `if ()` 语句进行判断的时候跟升序的是相反的！

代码如下：

```
/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int len = mountainArr.length();
        int left = 0;
        int right = len - 1;
        
        // 找出最大值的索引
        int maxIndex = findMaxIndex(left, right, target, mountainArr);
        
        // 找出左边升序数组的target，若没有则进行下面的
        int leftIndex = findLeftArr(left, maxIndex, target, mountainArr);
        
        if (leftIndex != -1) {
            return leftIndex;
        }
        
        // 找出右边降序数组的target
        int rightIndex = findRightArr(maxIndex, right, target, mountainArr);
        
        return rightIndex;
    }
    
    private int findMaxIndex(int left, int right, int target,  MountainArray mountainArr) {
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (mountainArr.get(mid) > mountainArr.get(mid+1)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    private int findLeftArr(int left, int maxIndex, int target, MountainArray mountainArr) {
        while (left < maxIndex) {
            int mid = (left + maxIndex) >>> 1;
            if (mountainArr.get(mid) < target) {
                left = mid + 1;
            } else {
                maxIndex = mid;
            }
        }
        if (mountainArr.get(left) != target) {
            return -1;
        }
        return left;
    }
    
    private int findRightArr(int maxIndex, int right, int target, MountainArray mountainArr) {
        while (maxIndex < right) {
            int mid = (maxIndex + right) >>> 1;
            if (mountainArr.get(mid) > target) {
                maxIndex = mid + 1;
            } else {
                right = mid;
            }
        }
        if (mountainArr.get(right) != target) {
            return -1;
        }
        return right;
    }
}
```

