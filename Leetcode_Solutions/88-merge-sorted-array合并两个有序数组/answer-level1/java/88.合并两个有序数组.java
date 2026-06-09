### 解题思路
为了节省空间，不新建数组，而是从尾向首遍历，将较大的元素放入nums1的末尾(填充原本用来占位的0)。这样达到O(m+n)的时间复杂度

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        //两个指针 从后向前遍历数组 将大的数放入nums1的尾部
        int p = m-1, q = n-1;//p遍历nums1,q遍历nums2
        int index = m + n-1;
        while (p >= 0 && q >= 0) {
            if(nums1[p]<nums2[q]){
                nums1[index--]=nums2[q];
                q--;
            }else{
                nums1[index--]=nums1[p];
                p--;
            }
        }
        //如果nums2数组有剩余,并入nums1
        if (q>=0){
            //注意 此处的复制长度写成q+1,而不是(n-q-1).后者在遇到nums1=[0]时会出错
            System.arraycopy(nums2,0,nums1,0,q+1);
        }
    }
}
```