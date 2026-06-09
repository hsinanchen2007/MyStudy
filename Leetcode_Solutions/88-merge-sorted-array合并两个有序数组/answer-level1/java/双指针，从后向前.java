### 解题思路
    根据nums1的length，从最后一个位置开始，每次比较nums1[m] 和 nums2[n]的大小；
将较大值添加到num1[cur]];然后指针向前移一位。
    最后的临界处理，for循环内部的i--和j--，需要在其中一个值为0的时候结束，避免溢出。
当i <=0,表示当前nums1中的m个元素都已经排序结束，此时直接将nums2[j]所有元素直接拼接
到nums1前。 反之j < =0不需要处理，剩下的元素本身就属于nums1，并且排好序。

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
      int i = m-1;
        int j = n-1;
        int k =nums1.length-1;
        for(; k >=0 && i >=0 && j>=0; k--){

            if(nums1[i] >= nums2[j]){
                nums1[k] = nums1[i--];
            }else {
                nums1[k] = nums2[j--];
            }
        }

        if(i <= 0){
            while(j >=0){
                nums1[j] = nums2[j];
                j--;
            }
        }
    }
}
```