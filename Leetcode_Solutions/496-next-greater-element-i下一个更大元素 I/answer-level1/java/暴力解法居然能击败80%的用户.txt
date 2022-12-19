执行用时 :4 ms, 在所有 Java 提交中击败了96.96%的用户
内存消耗 :36.9 MB, 在所有 Java 提交中击败了80.56%的用户

```
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] result = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++) {
            int big = -1;
            int numIndex = -1;
            for (int j = 0; j < nums2.length; j++) {
                if (nums2[j] == nums1[i]) {
                    numIndex = j;
                }
            }
            if (numIndex > -1) {
                for (int k = numIndex; k < nums2.length; k++) {
                    if (nums2[k] > nums1[i]) {
                        big = nums2[k];
                        break;
                    }
                }
            }
            result[i] = big;
        }
        return result;
    }
}
```
