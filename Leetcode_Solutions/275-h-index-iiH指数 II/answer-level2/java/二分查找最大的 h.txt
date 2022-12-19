由于数组是从小到大排好序的，所以我们的任务是：  
在数组中找一个最大的 h，使得后 h 个数大于等于 h，进行二分查找即可。
```java
class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r + 1 >>> 1;
            if (citations[n - mid] >= mid) l = mid;
            else r = mid - 1;
        }
        return r;
    }
}
```
更多题解欢迎关注 [https://github.com/Jerring/LeetCode](https://github.com/Jerring/LeetCode) ^_^