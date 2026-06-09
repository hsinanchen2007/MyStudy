### 解题思路
这题怎么弄也都是O(n),空间复杂度可以优化。
执行用时 : 0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 : 35.9 MB, 在所有 Java 提交中击败了85.96%的用户
### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {

        int[] res = new int[m+n];
        int i, j, t;
        for(i = 0, j = 0, t = 0; i < m && j < n; t++){
            if(nums1[i] <= nums2[j]){
                res[t] = nums1[i];
                i++;
            }
            else{
                res[t] = nums2[j];
                j++;
            }
        }

        if(i == m){
            while(j < n){
                res[t] = nums2[j];
                j++;
                t++;
            }
        }
        if(j == n){
            while(i < m){
                res[t] = nums1[i];
                i++;
                t++;
            }
        }

        for(i = 0; i < m + n; i++){
            nums1[i] = res[i];
        }
    }
}
```