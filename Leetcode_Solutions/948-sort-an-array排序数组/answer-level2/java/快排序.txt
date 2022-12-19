### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        
 quickSort(nums, 0, nums.length - 1);
return nums;
    }

       public static void quickSort(int[] a, int l, int r) {

        if (l < r) {
            int i,j,x;

            i = l;
            j = r;
            x = a[i];
            while (i < j) {
                while(i < j && a[j] > x)
                    j--; // 从右向左找第一个小于x的数
               if(i < j)
                    a[i++] = a[j];
               while(i < j && a[i] < x)
                    i++; // 从左向右找第一个大于x的数
                 if(i < j)
                    a[j--] = a[i];
             }
             a[i] = x;
             quickSort(a, l, i-1); /* 递归调用 */
             quickSort(a, i+1, r); /* 递归调用 */
         }
    }
 
}
```