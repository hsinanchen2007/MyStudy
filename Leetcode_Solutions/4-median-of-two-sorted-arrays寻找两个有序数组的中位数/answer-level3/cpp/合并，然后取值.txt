``class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int k=0;
        
        vector<int> nums(nums1.size()+nums2.size());
        for(;i<nums1.size() || j<nums2.size();){
        
            if(i==nums1.size()){
                nums[k++] = nums2[j++];
                continue;
            }
            
            if(j==nums2.size()){
                nums[k++] = nums1[i++];
                continue;
            }
            
            if(nums1[i]>nums2[j]){
                nums[k++] = nums2[j++];
            }else if(nums1[i]<nums2[j]){
                nums[k++] = nums1[i++];           
            }else{
                nums[k++] = nums2[j++];
                nums[k++] = nums1[i++];    
            }
        }
        
        if((nums1.size()+nums2.size())%2==1){
            return nums[(nums1.size()+nums2.size()-1)/2];
        }else{
            return ( nums[(nums1.size()+nums2.size())/2-1] + nums[(nums1.size()+nums2.size())/2] ) /2.0;
        }
    }
};`
```javascript []
- # ***- console.log('Hello world!')***
```javascript []
`console.log('Hello world!')`
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
代码块
```
代码块
```
# 1. **# [代码块]()**
```
```
```
