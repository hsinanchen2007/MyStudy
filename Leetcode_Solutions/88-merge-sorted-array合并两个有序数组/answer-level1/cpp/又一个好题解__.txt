### 解题思路
每一位都比一下，大的放后面，小的放前面
![批注 2020-04-09 143301.png](https://pic.leetcode-cn.com/d0b80707366af39d2081b2d24deaac88d743e8aef397fc62560bab28d63d81bd-%E6%89%B9%E6%B3%A8%202020-04-09%20143301.png)
又快又小
### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,x=n+m-1;
        if(x==0&&m==0){
            nums1[0]=nums2[0];
        }
        while(x>0&&j!=-1){
            if(i>-1 && nums1[i]>nums2[j]){
                nums1[x]=nums1[i];
                nums1[i]=0;
                i--;
            }else{
                nums1[x]=nums2[j];
                j--;
            }
            x--;
        }
        if(nums1[0]==0){
            nums1[0]=nums2[0];
        }
        return;
    }
};
```