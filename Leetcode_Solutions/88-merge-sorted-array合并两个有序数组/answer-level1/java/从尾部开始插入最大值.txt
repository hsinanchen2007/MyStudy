### 解题思路
从尾部开始比较，大者插入到最后一位
不断循环插入
如果第二个数组索引值大于等于0，插入到数组nums1前部

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        
        //边界情况
        if (m == 0 || n == 0) {
            for (int i = 0; i < n; i++) {
                nums1[i] = nums2[i];
            }
            return ;
        }

        //最大的数组 填充到后面
        int i = m-1;//数组1索引
        int j = n-1;//数组2索引
        int insertIndex = m+n-1;//要插入的开始索引
        
        a: while (i >= 0) {
            while (j >= 0) {
                 if (nums1[i] > nums2[j]) {
                     nums1[insertIndex] = nums1[i];
                     //nums1[i] = nums2[j];
                     i--;
                     insertIndex--;
                     continue a;
                 }  else {
                     nums1[insertIndex] = nums2[j];
                     j--;
                     insertIndex--;
                 }
            }
            i--;
        }

        //System.out.println(j);

        //如果j没走完
        if (j >= 0) {
            for (int k = 0; k <= j ;k++) {
                nums1[k] = nums2[k];
            }
        }
        

    }
}
```