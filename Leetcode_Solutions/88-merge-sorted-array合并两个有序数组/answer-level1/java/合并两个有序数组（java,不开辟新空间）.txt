### 解题思路
合并两个有序数组，不开辟多余空间，倒序进行比较，直接写入nums1 中
直到有一个索引小于0 则有一个数组已经遍历结束，再把另一个数组直接复制给nums1(只有当遍历完num2剩余时才需要复制)

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m-1;
        int j = n-1;
        while(i>=0 && j >=0){
            if(nums1[i] > nums2[j]){
                nums1[i+j+1] = nums1[i--]; // i+j+1 算法为 i+j+1 = (m+n-1) - (m-1-i) -(n-1-j) 去括号所得 即为当前nums1中应该放置的索引位置
            }else{
                nums1[i+j+1] = nums2[j--];
            }
        }

        if(j >= 0){
            for(int k =0;k<=j;k++){
                nums1[k] = nums2[k];
            }
        }
    }
}
```