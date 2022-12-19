
这道题第一思路是用二分查找
![image.png](https://pic.leetcode-cn.com/ae95fe2a44dbea6cfdb648af4c5b4b6d64d69147e3f0253733c8ead360f374e5-image.png)


因为使用**二分法**：
    所以复杂度为*O(n*logk), k介于 left=sum/threshold（向下取整） 和 right=num_max之间；而right<=10^6, left>=1; 故logk <=6log2(10) ~=18;
    主要是**估算可能除数的上下界**，上面的估算方法略强于 1~10^6（即不估算）；

解释一下上面估算的**原因**：
    1）因为每个元素除以除数d都要向上取整，向上取整结果res=(num+x)/d (此时x介于[0,d),x使得该式余数为0），相当于将元素放大了，sum_res>=sum 必然存在，因此有 threshold >= ans == sum_res/d >= sum/d, ans为各元素除以 d以后累加的真实结果，也即各项res累加结果，由于有向上取整，必然要大于等于sum_res/d；经过缩放后可以得到threshold>=sum/d （表达式除法均为c++的向下取整除法），从而有d>=sum/threshold;
    2）也因为有向上取整，所以只要元素不为0，那么只要d超过了最大值num_max，此时无论d如何增加，最后运算结果ans总是为n-k, n为数组的长度，而k为数组中零元素的个数；所以可知，d的最大边界为right=num_max;   
    从而可得二分法的左右边界[left,right] 为 [sum/threshold, num_max];
```c++
class Solution {
public:
int smallestDivisor(vector<int>& nums, int threshold) {
        long int sum=0;
        int right=INT_MIN;
        int res=INT_MAX;
        for(int num:nums){
            sum+=num;
            if(num>right) right=num;
        }
        int left=sum/threshold;
        if(left==0) left=1;

        while(left<right){
            int mid=left+(right-left)/2;

            int tmp=0;
            for(int num:nums){
                tmp+=num/mid+( ( num % mid == 0 ) ? 0 : 1 );
            }
            if(tmp<=threshold) {
                if(mid<res) res=mid;
                right=mid;
            }else{
                left=mid+1;
            }

        }
        return res;
    }
};
```