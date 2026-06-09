
```
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1, j = n - 1, index = m + n - 1;
        while (i >= 0 || j >= 0 ) {
            if ((i >= 0 && j >= 0 && nums1[i] >= nums2[j]) || j < 0) {
                nums1[index--] = nums1[i--];
            } else if ((i >= 0 && j >= 0 && nums1[i] < nums2[j]) || i < 0 ){
                nums1[index--] = nums2[j--];
            }
        }
    }
}
```

1、双指针问题；
2、要么顺序遍历要么倒叙遍历，若是顺序遍历要移动nums1后面的所有，所以倒序；
3、两指针分别指向两数组最后的有效位。另一指针index用来放值，它初始指向num1中两个数组个数总和的位置。从后往前遍历；
4、只要两数组没循环完就一直循环，所以i和j有一个大于等于0就行；
5、index位置放i指向的数，情况分两种：第一种i和j都没循环完，i指向的数比j指向的数大；第二种nums2循环完了，但是nums1没循环完；
6、反之同理；