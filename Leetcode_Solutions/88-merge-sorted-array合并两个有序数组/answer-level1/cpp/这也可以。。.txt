### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;++i){
            int tmp=nums2[i];
            if(0==m){
                nums1.insert(nums1.begin()+i,tmp);
            }
            else if(tmp<=nums1[0]){
                nums1.insert(nums1.begin(),tmp);
            }
            else if(tmp>=nums1[m-1+i]){
                nums1.insert(nums1.begin()+m+i,tmp);
            }
            else{
                int left(0),right(m-1+i);
                while(left<=right){
                    int mid=(left+right)/2;
                    if(nums1[mid]==tmp){
                        nums1.insert(nums1.begin()+mid,tmp);
                        break;
                    }
                    else if(nums1[mid]>tmp)
                        right=mid-1;
                    else
                        left=mid+1;
                }
                if(left>right) nums1.insert(nums1.begin()+left,tmp);
            }
            nums1.pop_back();
        }
    }
};
```