### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int b[50001];
    int countReversePairs(vector<int>& nums, int L, int R) {
        // 计算[L, R]区间内的逆序对
        int cnt = 0; // 注意：逆序对的数量可能会非常大，会爆掉int, 记得考虑下long long
        int mid = (L+R)/2;
        
        if(L< mid) 
            cnt += countReversePairs(nums, L, mid); //递归计算左区间的逆序对
        if(mid+1 < R)
            cnt += countReversePairs(nums, mid+1, R); //递归计算右区间的逆序对
        
        int i=L, j=mid+1, k=L;
        while(i<=mid || j<=R) {
            while(i<=mid && (j>R || nums[i]<=nums[j]) ) {
                // cout << nums[i] << " <= " << nums[j] << endl;
                b[k++] = nums[i++];
            } 
            while(j<=R  && (i>mid || nums[j]<nums[i]) ) {
                //cout << nums[i] << " > " << nums[j] << endl;
                b[k++] = nums[j++];
                cnt += mid-i+1;
                // cout << cnt <<endl;
            }
        }
        for(int i=L; i<=R; i++) 
            nums[i] = b[i];
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int ans;
        if(nums.size() == 0) return 0;
        ans = countReversePairs(nums, 0, nums.size()-1);
        return ans;
    }
};
```