### 解题思路

#### 分析
- 输入两个有序数组
- 输出中位数
- 奇数个数的中位数是最中间的数。
- 偶数个数的中位数是中间两数的平均数。

因此需要考虑两种情况。

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int num=0;//走了多少步
        int n1=0;
        int n2=0;
        int mid=0;
        int len=nums1.length+nums2.length;
        int count=len/2 +1;//需要走多少步
        //len为奇数，走len/2步
        //len为偶数，走len/2+1步
        while(n1<nums1.length && n2<nums2.length){
            //谁小谁先走
            if (nums1[n1]<=nums2[n2]){
                num++;//++后的num表示当前走的是第num个
                //判断当前的数字是否需要记录
                //如果len为偶数
                if (len%2==0 && num==(count-1)){
                    mid=nums1[n1];
                }
                //不管是len是奇数还是偶数，第count个数肯定是要进行记录的
                if (num==count){
                    mid=nums1[n1]+mid;
                    break;
                }
                n1++;
            }else {
                num++;
                if (len%2==0 && num==(count-1)){
                    mid=nums2[n2];
                }
                if (num==count){
                    mid=nums2[n2]+mid;
                    break;
                }
                n2++;
            }
        }
        if (num==count){
            if (len%2==0){
                return (double)mid/2;
            }else {
                return (double)mid;
            }
        }
        while(n2!=nums2.length){
            num++;
            if (len%2==0 && num==(count-1)){
                mid=nums2[n2];
            }
            if (num==count){
                mid=nums2[n2]+mid;
                break;
            }
            n2++;
        }
        while(n1!=nums1.length){
            num++;
            if (len%2==0 && num==(count-1)){
                mid=nums1[n1];
            }
            if (num==count){
                mid=nums1[n1]+mid;
                break;
            }
            n1++;
        }
        if (len%2==0){
            return (double)mid/2;
        }else {
            return (double)mid;
        }
    }
}
```