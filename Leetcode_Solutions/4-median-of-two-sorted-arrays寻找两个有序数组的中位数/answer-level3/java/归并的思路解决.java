### 解题思路

两个数组 正好相当于 归并排序中对数组 分成了两个。 然后构造一个长度为两个数组之和的一半加一的数组 （length/2+1, length为两个数组之和），从两个数组的第一位进行判断，不断放入构建的数组， 不用放满，\
 当达到 该数组一般长度时 （length / 2）判断，长度是奇数还是偶数，判断完后直接返回即可。

***另外， 也可以使用不开辟新数组的做法，直接使用较长数组空间也可。***

![两个数组的中位数.PNG](https://pic.leetcode-cn.com/a988de819c9ee7fba328d83c8b3dbffdd78d737a7889c2584fc7197b634d5a29-%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%B8%AD%E4%BD%8D%E6%95%B0.PNG)


### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // 归并排序的变种 
        int n1 = nums1.length, n2 = nums2.length;
        int length = n1 + n2;
        int [] arr = new int[length/2 + 1];  // 两个数组之和的一半 +1
        int index = 0;  // arr 数组游标
        int i=0, j=0;
        double res = 0;
        boolean flag = true;  // 不用判断到最后  达到一半就行的标志位

        while(i<n1&&j<n2){
            if(nums1[i] < nums2[j]){
                arr[index] = nums1[i++];
            }else{
                arr[index] = nums2[j++];
            }
            if(index == length / 2){ // 当达到标志位直接进行 计算
                res = length % 2 == 0?(arr[index]+arr[index-1])/2.0:arr[index];
                flag = false;   // 更改标志位 打断后面的计算
                break;
            }
            index++;
        }
        while(i<n1&&flag){ 
            arr[index] = nums1[i++];
            if(index == length / 2){
                res = length % 2 == 0?(arr[index]+arr[index-1])/2.0:arr[index];
                break;
            }
            index ++;
        }
        while(j<n2&&flag){
            arr[index] = nums2[j++];
            if(index == length / 2){
                res = length % 2 == 0?(arr[index]+arr[index-1])/2.0:arr[index];
                break;
            }
            index ++;
        }
        return res;
    }
}
```