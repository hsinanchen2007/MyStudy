### 解题思路
①首先创建一个新的数组,数组长度为两个数组长度之和
②遍历数组,把数组1中的元素赋值给新数组中
③在遍历数组1的基础上,把数组2的元素赋值给新数组
④把新数组排序,排成有序数组,方便二分查找
⑤根据数组长度的奇偶性,判断中位数

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len=nums1.length+nums2.length;
        int[] newArr=new int[len];
        for (int i = 0; i < nums1.length; i++) {
            newArr[i]=nums1[i];
        }
        int count=0;
        for (int i = nums1.length; i < len; i++) {
            newArr[i]=nums2[count];
            count++;
        }
        Arrays.sort(newArr);
        double midNum=0;
        if (len % 2 == 0) {
            int mid = len / 2;
            midNum = (newArr[mid-1] + newArr[mid]) * 1.0 / 2;
        } else {
            int mid=(len+1)/2;
            midNum=newArr[mid-1];
        }
        return midNum;
    }
}
```