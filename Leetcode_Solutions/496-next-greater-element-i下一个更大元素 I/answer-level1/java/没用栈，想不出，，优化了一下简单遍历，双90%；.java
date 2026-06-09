执行用时 :6 ms, 在所有 Java 提交中击败了90.67%的用户
内存消耗 :36.5 MB, 在所有 Java 提交中击败了90.47%的用户
```
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        
        int [] Index = new int [nums1.length];
        for (int i = 0; i < nums1.length;i++){
            for (int j = 0; j < nums2.length; j++){
                if (nums1[i]==nums2[j]){
                    Index[i] = j;
                    break;
                }
            }
        }

        int [] ans = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++){
            ans[i] = -1;
            for (int j = Index[i]; j < nums2.length; j++){
                if (nums2[j] > nums1[i]){
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
}
```
