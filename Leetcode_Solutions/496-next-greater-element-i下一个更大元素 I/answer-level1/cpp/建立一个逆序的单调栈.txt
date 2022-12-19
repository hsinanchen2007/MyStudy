### 解题思路
1.若当前元素比栈顶元素小，说明栈顶是当前元素右边第一个大的元素
2.若当前元素比栈顶元素大，说明栈顶不是当前元素右边第一个大的元素且此值在栈里或者不存在
>操作为：弹出比当前元素小的栈元素，使得当前元素成为右边第一个大的元素的首要考虑


### 代码

```cpp

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     int n = nums1.size();
     int m = nums2.size();
     vector<int> r_max;
     vector<int> out;
     stack<int> s;
    
     for(int i=m-1;i>=0;i--){
         
        while(!s.empty() && s.top()<nums2[i]) 
         {
             s.pop();
         }
         if(s.empty()) {
             r_max.push_back(-1);   
         }
         else r_max.push_back(s.top());
         
         s.push(nums2[i]);
         
     }
        vector<int>::iterator index;
        
        for(int i=0;i<n;i++){
            
            index = find(nums2.begin(),nums2.end(),nums1[i]);
            out.push_back(r_max[nums2.end()-1-index]);
        }
    return out;
    }
};
```