### 解题思路
要分情况：
nums1与nums2有效部分都没有遍历完；
nums1遍历完，nums2没有
nums2遍历完，nums1没有

### 代码

```cpp
class Solution {//insert nums2 into nums1 and sort 
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m+n-1 ; i >= 0 ; i--){
            //starting from right end, put larger one into right
            if (m>=1 && n>=1){
                if(nums2[n-1] > nums1[m-1]){
                    nums1[i]=nums2[n-1];
                    n--;
                }
                else{
                    swap(nums1[i],nums1[m-1]);//do not just overwrite nums1[i],or lead to comparison problems with nums2 later
                    m--;
                }
                continue;
            }
            if (n<1)break;//if nums2 finish, automatically we are done 
            if (m<1 && n>=1){//if nums1 finishes, keep insert nums2 into nums1
                nums1[i]=nums2[n-1];
                n--;
            }
        }
    }
};
```