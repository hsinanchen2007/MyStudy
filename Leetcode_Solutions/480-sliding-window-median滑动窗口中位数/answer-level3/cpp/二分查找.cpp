维持窗口内的元素有序，窗口向右移动的同时，二分查找实现删除元素和加入元素
```
class Solution {
public:
    //二分查找
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<double> res;vector<int> now;
        for(int i=0;i<k;i++)now.push_back(nums[i]);
        sort(now.begin(),now.end());
        int p=k/2;
        if(k%2)res.push_back((double)now[p]);
        else res.push_back(((double)now[p-1]+(double)now[p])/2);
        for(int i=0;i<=n-k-1;i++){
            int left,join,l=0,r=k-1,mid;
            while(l<=r){
                mid=(l+r)/2;
                if(now[mid]==nums[i])break;
                else if(now[mid]>nums[i])r=mid-1;
                else l=mid+1;
            }
            now.erase(now.begin()+mid);
            l=0;r=k-2;
            while(l<r){
                mid=(l+r)/2;
                if(now[mid]==nums[i+k])break;
                else if(now[mid]>nums[i+k])r=mid-1;
                else l=mid+1;
            }
            if(l!=r)now.insert(now.begin()+mid,nums[i+k]);
            else if(now[l]>=nums[i+k])now.insert(now.begin()+l,nums[i+k]);
            else now.insert(now.begin()+l+1,nums[i+k]);
            if(k%2)res.push_back((double)now[p]);
            else res.push_back(((double)now[p-1]+(double)now[p])/2);
        }
        return res;
    }
};
```
