### 解题思路
二分法迭代
性能惨不忍睹啊。。。考虑下不使用迭代，使用循环是不是好一些？

解题思路直接看注释吧。
主要思路就是
1、根据数组元素的个数确定中位数（第k小的数）的位置
2、使用二分法迭代：每次去掉一般的剩余中位数的一半。


### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 != 0 && len2 == 0){//有一个输入为空，则直接找中间点即可
            int mid = len1 / 2;
            return (len1 & 1 == 1) ? ((double)(nums1[mid]) / 1.0) : ((double)(nums1[mid] + nums1[mid - 1]) / 2.0);
        }

        if(len1 == 0 && len2 != 0){//有一个输入为空，则直接找中间点即可
            int mid = len2 / 2;
            return ((len2 & 1 == 1) ? ((double)(nums2[mid]) / 1.0) : ((double)(nums2[mid] + nums2[mid - 1]) / 2.0));
        }

        int pos_median;//初始中位数的位置
        int len = len1 + len2;
        //计算初始中位数的位置
        if((len) & 1 == 1){//奇数
            pos_median = (len + 1) / 2;//中位数为合并后的数组的第pos_median小的数，其在数组中的位置为(pos_median - 1)
        }else{//偶数
            pos_median = len / 2;//中位数为合并后的数组的第pos_median和第(pos_median + 1)小的数的均值，其在数组中位置分别为(pos_median - 1)和pos_median
        }

        //设置数组的起始和结束位置，便于迭代中进行计算
        int s1 = 0;
        int e1 = len1 - 1;
        int s2 = 0;
        int e2 = len2 - 1;
        //开始迭代

        if(len & 1 == 1){
            return getMedian_BS(nums1,s1,e1,nums2,s2,e2,pos_median);
        }else{
            int m1 = getMedian_BS(nums1,s1,e1,nums2,s2,e2,pos_median);
            int m2 = getMedian_BS(nums1,s1,e1,nums2,s2,e2,(pos_median + 1));
            return 0.5 * (m1 + m2);
        }
    }

    int getMedian_BS(vector<int> &nums1, int start1, int end1, vector<int> &nums2, int start2,
                                           int end2, int pos_median) {

        if(pos_median == 1 && (end1 != -1 && end2 != -1)){
            return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
        }

        //如果其中一个数组为空且另外一个数组不为空，则直接返回从不为0的数组中找到中位数返回即可
        if(end1 == -1 && (end2 != 0 || (start2 == end2))){
            return nums2[start2 + pos_median - 1];
        }

        if((end1 != 0 || (start1 == end1)) && end2 == -1){
            return nums1[start1 + pos_median - 1];
        }
        
        int mid = pos_median / 2;

        //计算数组的长度,用来计算下一个position点
        int len1 = end1 - start1 + 1;//nums1数组的剩余长度
        int len2 = end2 - start2 + 1;//nums2数组的剩余长度

        //计算中间数的位置,取小的那个值，用于position点的比较
        int counts_nums1 = (len1 > mid) ? mid : len1;
        int pos_nums1 = start1 + counts_nums1 - 1;
        int counts_nums2 = (len2 > mid) ? mid : len2;
        int pos_nums2 = start2 + counts_nums2 - 1;

        if(nums1[pos_nums1] >= nums2[pos_nums2]){//舍弃nums2的前(pos_median/2)个元素
            if(len2 > mid){//根据具体长度确定下一个递归的参数，特别是结束点和pos_median
                return getMedian_BS(nums1,start1,end1,nums2,pos_nums2 + 1,end2,pos_median - counts_nums2);
            }else{
                return getMedian_BS(nums1,start1,end1,nums2,start2,-1,pos_median - counts_nums2);
            }

        }else{//舍弃nums1的前（pos_median/2）个元素
            if(len1 > mid){//根据具体长度确定下一个递归的参数，特别是结束点和pos_median
                return getMedian_BS(nums1,pos_nums1 + 1,end1,nums2,start2,end2,pos_median - counts_nums1);
            }else{
                return getMedian_BS(nums1,start1,-1,nums2,start2,end2,pos_median - counts_nums1);
            }
        }
    }
};
```