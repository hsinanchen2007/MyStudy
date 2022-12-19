### 解题思路
由于当前的数组大小不确定，我们可以考虑从尾部向前遍历的方法，为了保证不使用额外的空间，可以在num1上直接操作
从尾部向前遍历一共有四种情况:
    1.如果num1的数据大于num2 尾部直接填充num1数据即可
    2.如果num2的数据大于num1 尾部直接填充num2数据即可
    3.当前index1<0 说明了num1全部遍历完毕 则之后填充的数据全部为num2中数据
    4.当前index2<0 说明了num2全部遍历完毕 则之后填充的数据全部为num1中数据

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        //从尾向前进行遍历
        int index1 = m-1;
        int index2 = n-1;
        int indexMerge = m+n-1;
        //从尾向前遍历
        while(index1>=0 || index2>=0){
            //如果index1 < 0 说明了index2依旧还有数
            if(index1<0) nums1[indexMerge--] = nums2[index2--];
            //如果index2<0 说明index1依旧还有数
            else if(index2<0)  nums1[indexMerge--] = nums1[index1--];
            //如果nums1[index1] > nums2[index2] 尾部填充nums1 数据
            else if (nums1[index1] > nums2[index2])  nums1[indexMerge--] = nums1[index1--];
             //如果nums2[index2] > nums1[index1] 尾部填充nums2 数据
             else   nums1[indexMerge--] = nums2[index2--];
        }
    }
}

```