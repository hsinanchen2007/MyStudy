### 解题思路
对数组以及指针状态抽了一下，清晰很多
所有计数都从0开始
### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        ArrState arr1 = new ArrState(nums1),
                 arr2 = new ArrState(nums2);
        int totalLen = nums1.length + nums2.length;
        int mid = (totalLen - 1) / 2;
        if ((totalLen & 1) == 1)
            return findK(arr1, arr2, mid);
        else
            return (findK(arr1, arr2, mid) + findK(arr1, arr2, mid + 1)) / 2.;
    }

    // k 从0开始
    public static int findK(ArrState arr1, ArrState arr2, int k) {
        arr1.reset();
        arr2.reset();
        while (true) {
            if (k == 0)
                return Math.min(arr1.get(k), arr2.get(k));
            if (arr1.oob())
                return arr2.get(k);
            if (arr2.oob())
                return arr1.get(k);
            int halfK = k / 2;
            int mov = (k + 1) / 2;
            if (arr1.get(halfK) > arr2.get(halfK))
                arr2.movPos(mov);
            else
                arr1.movPos(mov);
            k = k - mov;
        }
    }

    private static class ArrState {

        int[] num;
        int pos;
        static final int INF = Integer.MAX_VALUE;

        public ArrState(int[] n) {
            num = n;
            reset();
        }

        public int get(int k) {
            if (oob(k)) return INF;
            return num[pos + k];
        }

        public void movPos(int inc) {
            pos += inc;
        }
        // out of boundary
        public boolean oob(int k) {
            return pos + k >= num.length;
        }

        public boolean oob() {
            return oob(0);
        }

        public void reset() {
            pos = 0;
        }

    }

}
```