### 解题思路


### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum=0;
        int A=0;
        int B=0;
        int sum_a=nums1.size();
        int sum_b=nums2.size();
        int count=sum_a+sum_b;
        int list[count];
        double middle=0.0;
        while(sum<count)
        {
            if(sum_a!=0&&sum_b!=0){
                if(nums1[A]<=nums2[B])
                {
                    list[sum]=nums1[A];
                    A++;
                    sum_a--;
                }
                else {
                    list[sum]=nums2[B];
                    B++;
                    sum_b--;
                 }
                }
            else if(sum_b==0)
            {
                list[sum]=nums1[A];
                A++;
                sum_a--;
            }
            else{
                list[sum]=nums2[B];
                B++;
                sum_b--;
            }
            sum++;
        }
        if(sum%2==0){
            middle=(list[sum/2-1]+list[sum/2])/2.0;
        }
        else{
            middle=list[(int)(sum/2)];
        }
        return middle;
    }

};
```