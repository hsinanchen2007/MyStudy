### 解题思路
执行用时 :
1 ms
, 在所有 java 提交中击败了
39.70%
的用户
内存消耗 :
36.4 MB
, 在所有 java 提交中击败了
77.94%
的用户

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
         for(int i=0;i<n;i++){
            nums1[nums1.length-n+i]=nums2[i];
        }
        Arrays.sort(nums1);
        
    }
}
```