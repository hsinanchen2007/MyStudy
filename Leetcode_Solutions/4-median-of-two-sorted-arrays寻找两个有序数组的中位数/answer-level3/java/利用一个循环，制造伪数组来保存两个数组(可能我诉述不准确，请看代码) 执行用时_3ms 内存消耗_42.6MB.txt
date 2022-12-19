### 解题思路
 将nums1和nums2两个数组“伪拼接”为一个有序的数组
 先找出中位数的下标midNum(若拼接的数组长度为偶数，那么得到的下标有两个)
 然后从两个数组中各拿一个数进行大小比较，小的则放在“伪拼接”数组里
 当比较次数等于midNum时停止比较，即找到中位数，再根据“伪拼接”数组的长度奇偶性判断下标有几个
### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len_1=nums1.length,len_2=nums2.length;
        //中位数的下标
        int midIndex=(len_1+len_2)/2;
        //count记录对两个数组的总的遍历次数 x为nums1当前的下标 y为nums2当前的下标
        int count=0,x=0,y=0;
        //两个数组长度之和是否为偶数
        boolean isOu=(len_1+len_2)%2==0?true:false;
        //0代表默认前一次遍历的是nums1 1代表前一次遍历的是nums2
        int befor_array=0;
        double midNum=0;
        while (true){
            //0代表默认当前遍历的是nums1
            int curr_array=0;
            //若nums1和nums2都没有遍历完
            if(x<nums1.length&&y<nums2.length){
                if(nums1[x]<=nums2[y]){
                    x++;
                    //记录当前遍历的是nums1
                    curr_array=0;
                }else {
                    y++;
                    //记录当前遍历的是nums2
                    curr_array=1;
                }
                //若只有nums1没有遍历完===> nums1的长度>nums2的长度
            }else if(x<nums1.length){
                x++;
                curr_array=0;
                //若只有nums2没有遍历完===> nums1的长度<nums2的长度
            }else {
                y++;
                curr_array=1;
            }

            //长度为偶数,且遍历到中位
            if(isOu&&count==midIndex){
                //前两次遍历的都是nums1
                if(befor_array==0&&curr_array==0){
                    midNum=(double)(nums1[x-1-1]+nums1[x-1])/2;
                }else if(befor_array==1&&curr_array==1){
                    //前两次遍历的都是nums2
                    midNum=(double)(nums2[y-1-1]+nums2[y-1])/2;
                }else {
                    //前两次nums1和nums2都被遍历了
                    midNum=(double)(nums1[x-1]+nums2[y-1])/2;
                }
                //找到中位数，退出循环
                break;
            }else if(!isOu&&count==midIndex){ //长度为奇数,且遍历到中位
                //当前遍历的是nums1
                if(curr_array==0){
                    midNum=(double) nums1[x-1];
                }else {
                    //当前遍历都是nums2
                    midNum=(double) nums2[y-1];
                }
                //找到中位数，退出循环
                break;
            }
            //将当前的遍历对象记录为 下一次的 前一次遍历对象
            befor_array=curr_array;
            count++;
        }
        return midNum;
    }
}
```