### 解题思路
1. 从后往前遍历，依次从nums1和nums2中取出元素，大的放后面，并更新指针位置
2. 当某一个集合的元素遍历完成时，分两种情况
   - 当nums1中先处理完了，nums2中还有元素，则需要将nums2中的元素依次拷贝到nums1中
   - 当nums2中的元素先处理完了，则无需拷贝
 
### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int p = m + n - 1;
        int p1 = m - 1;
        int p2 = n - 1;
        while(p1 >= 0 && p2 >= 0){
            nums1[p--] = nums1[p1] >= nums2[p2] ? nums1[p1--]:nums2[p2--];
        }

        if(p2 >= 0){
           System.arraycopy(nums2,0,nums1,0,p2 + 1);
        }

    }
}
```