### 解题思路
模板题

### 代码

```cpp
class Solution {
public:
    int tmp[50010];
    long long merge_sort(vector<int>& q,int l,int r){
        if(l>=r) return 0;
        int mid=l+r>>1;
        long long pre=merge_sort(q,l,mid)+merge_sort(q,mid+1,r);
        int i=l;
        int j=mid+1;
        int k=0;
        while(i<=mid&&j<=r){
            if(q[i]<=q[j]) tmp[k++]=q[i++];
            else {
                tmp[k++]=q[j++];
                pre+=mid-i+1;
            }
        }
        while(i<=mid) tmp[k++]=q[i++];
        while(j<=r) tmp[k++]=q[j++];
        for(i=l,j=0;i<=r;i++,j++) q[i]=tmp[j];
        return pre;
    }
    int reversePairs(vector<int>& nums) {
        long long ans=merge_sort(nums,0,nums.size()-1);
        return ans;
    }
};
```