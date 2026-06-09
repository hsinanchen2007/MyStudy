### 解题思路
说实话有点慢，还不如直接暴力。
- 相当于一直维护一个大小为k的窗口，将窗口中的数按升序记录在一个数组里面。
- 当窗口大于k时，每次加一个数进来就要删除一个窗口最左端的数，即2次二分。
- 每次插入一个数之后，就只需要与其两边的数比较就行了。

### 代码

```cpp
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<int>vec;
        int start=0;
        long res=(long)INT_MAX+1;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int l=binary_search(vec,nums[i]);
            if(!vec.size()||vec[l]>nums[i]){
                vec.insert(vec.begin()+l,nums[i]);
            }
            else{
                vec.insert(vec.begin()+l+1,nums[i]);
            }
            mp[nums[i]]++;
            if(i-start>k){
                int r=binary_search(vec,nums[start]);
                mp[vec[r]]--;
                vec.erase(vec.begin()+r);
                start++;
            }
            if(l-1>=0) res=res<(long)max(vec[l],vec[l-1])-min(vec[l],vec[l-1])?res:(long)max(vec[l],vec[l-1])-min(vec[l],vec[l-1]);
            if(l+1<vec.size()) res=res<(long)max(vec[l],vec[l+1])-min(vec[l],vec[l+1])?res:(long)max(vec[l],vec[l+1])-min(vec[l],vec[l+1]);
        }
        return res<=t;
    }
    int binary_search(vector<int>& vec,int nums){
        int l=0,r=vec.size()-1;
        while(l<r){
            int mid=l+r>>1;
            if(vec[mid]>=nums) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
```