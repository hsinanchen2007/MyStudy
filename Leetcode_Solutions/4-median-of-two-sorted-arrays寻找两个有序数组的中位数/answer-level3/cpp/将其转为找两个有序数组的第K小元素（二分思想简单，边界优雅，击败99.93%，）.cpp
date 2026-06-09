面试时，被问到log(n+m)求两个有序数组的第K大元素，其实寻找两个有序数组的中位数可以转为求第K小。
官方题解给的解法不太通用，而且边界条件太多了。
方法一：二分法找两个有序数组的第K小元素

[@liweiwei1419](/u/liweiwei1419/)这位同学总结的[二分法模板](https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/)非常好，基本是C++ STL中lower_bound函数和upper_bound函数实现的方式，强烈推荐！其实二分思想就是从数组的两边夹逼或排除，由循环不变式可知循环返回的那个位置就是满足查找条件(比如插入的位置)的位置。
a数组长度为n，b数组长度为m；
首先，找a和b两个有序数组中第K小，就是在a中找某个位置**i**，在b中找某个位置**j**，其满足条件为：
**1、i+j=k
2、a[i-1]<=b[j]&&b[j-1]<=a[i]**
这样第K小即为：**max(a[i-1],b[j-1])**;
其次，我们就可以在a数组中二分查找位置**i**，相应b中位置**j=k-i**，但是要注意b中**j**的位置不能越过b的边界即：**0<=j<=m**，
这样可以得到在a数组中二分查找的范围：**0<=i<=n且k-m<=i<=k**即**max(0,k-m)<=i<=min(k,n);**
我们可以在这个范围内用二分模板查找**i**的位置。
最后，二分找到**i**即代码中的**le**后，注意边界判断如果位置**i**和**j**前面都有元素，**第k小=max(a[i-1],b[j-1])**;如果**i=0**，
**第k小=b[j-1]**;如果**j=0**;**第k小=a[i-1]**;
两个有序数组的中位数即为：**1、两个数组长度(m+n)为奇数，求第(m+n)/2+1小元素；2、两个数组长度(m+n)为偶数，求
第(m+n)/2小、第(m+n)/2+1小,两者平均值**。
![image.png](https://pic.leetcode-cn.com/5cf97342aa1575cb11196cf52e523e6517eb24b35d79f62916c5676b0271ebca-image.png)

```
class Solution {
public:
    int findKthElm(vector<int>& nums1,vector<int>& nums2,int k){
        assert(1<=k&&k<=nums1.size()+nums2.size());
        int le=max(0,int(k-nums2.size())),ri=min(k,int(nums1.size()));
        while(le<ri){
            int m=le+(ri-le)/2;
            if(nums2[k-m-1]>nums1[m]) le=m+1;
            else ri=m;
        }//循环结束时的位置le即为所求位置，第k小即为max(nums1[le-1]),nums2[k-le-1])，但是由于le可以为0、k,所以
        //le-1或者k-le-1可能不存在所以下面单独判断下
        int nums1LeftMax=le==0?INT_MIN:nums1[le-1];
        int nums2LeftMax=le==k?INT_MIN:nums2[k-le-1];
        return max(nums1LeftMax,nums2LeftMax);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()+nums2.size();
        if(n&1){//两个数组长度和为奇数
            return findKthElm(nums1,nums2,(n>>1)+1);
        }
        else{//为偶数
            return (findKthElm(nums1,nums2,n>>1)+findKthElm(nums1,nums2,(n>>1)+1))/2.0;
        }
    }
};

```
![image.png](https://pic.leetcode-cn.com/037bb0912c2a47eccf2eeef36c8d7f6ec11793b1256b5384a1f8adfb92662fd2-image.png)

方法二：二分+递归（太麻烦，可以了解下）
```
class Solution {
public:
    //寻找第K大、小元素
    int findKthElm(vector<int>& a,int abeg,int aend,vector<int>& b,int bbeg,int bend,int k){
        if(abeg>aend){//如果a数组没有元素，直接返回b数组的第K大、小元素
            return b[bbeg+k-1];
        }
        if(bbeg>bend){//如果b数组没有元素，直接返回a数组的第K大、小元素
            return a[abeg+k-1];
        }
        int amid=(abeg+aend)/2;
        int bmid=(bbeg+bend)/2;
        if(a[amid]<b[bmid]){//这里写成a[amid]<b[bmid]是求第k小，改成a[amid]>b[bmid]就是求第K大,本题是求第k小
            if(amid-abeg+bmid-bbeg+2>k){//如果a[mid]<b[bmid]且k小于两个数组大小之和的一半，k一定不在b的右半部分，所以递归在
                //整个数组a和b的左半部分找第K小
                return findKthElm(a,abeg,aend,b,bbeg,bmid-1,k);
            }
            else{//如果a[mid]<b[bmid]且k大于等于两个数组大小之和的一半，k一定不在a的左半部分，所以递归在整个b数组和a数组的
                //右半部分寻找第(k-a左半部分长度)小
                return findKthElm(a,amid+1,aend,b,bbeg,bend,k-(amid-abeg+1));
            }
        }
        else{//和以上注解一样
            if(amid-abeg+bmid-bbeg+2>k){
                return findKthElm(a,abeg,amid-1,b,bbeg,bend,k);
            }
            else{
                return findKthElm(a,abeg,aend,b,bmid+1,bend,k-(bmid-bbeg+1));
            }
        } 
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz=nums1.size()+nums2.size();
        if(sz%2==0){//偶数
            int a=findKthElm(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,sz>>1);
            int b=findKthElm(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,(sz>>1)+1);
            return (a+b)/2.0;
        }
        else{//奇数
            return findKthElm(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,(sz>>1)+1);
        }
    }
};
```
