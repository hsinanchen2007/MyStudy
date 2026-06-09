###O(n²)
看到这种合并有序列表/链表题目，自然想到使用指针i j分别指向两个表头

循环遍历时
1. 如果nums1[i]<=nums2[j] :     i自增
2. 如果nums1[i]>nums2[j]  :     从pos=i开始对[i,nums1.size()-1]的所有元素后移一位，为了空出位置填装nums2[j]
                                注意将nums2[j]移入nums1后，应该将此时nums1中的**已用位置总数（也就是参数m）+1**
                                为什么呢？我们想要i在循环结束以后，如果在还有空位的情况下，指向空位的第一个
                                如果循环完毕没有空位(i==nums1.size())或者num2的最大元素都小于nums1最大元素(j==nums2.size())
                                那么结束循环
所以退出条件为i<m && i<s1 && j<s2
如果j<s2.size() 将剩余的元素加入到nums1空位中去
### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        if(n==0) return;
        int s1=nums1.size();
        int s2=nums2.size();
        while ( i < m && i<s1 && j<s2){
            if(nums1[i]<=nums2[j]){
                i++;
            }else{
                move_back(nums1,i);
                nums1[i++]=nums2[j++];
                m++;
            }
        }
        while(j<n){
            nums1[i++]=nums2[j++];
        }
    }

    void move_back(vector<int> & nums,int pos){
        int size=nums.size();
        for(int i=size-1;i>pos;--i){
            nums[i]=nums[i-1];
        }
    }
};
```
###O(nlogn)
直接加入空位+快排
O(n)+O(nlogn)=O(nlogn)