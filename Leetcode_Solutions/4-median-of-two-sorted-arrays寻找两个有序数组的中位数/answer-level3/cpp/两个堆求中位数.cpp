没注意到有序条件，大佬帮看下，用两个堆的话是不是复杂度是不是O((m+n)log(m+n))？（但是能通过。。）
```
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int size1 = n + m >> 1, size2 = n + m - size1; 
        priority_queue<int> maxq;
        priority_queue<int,vector<int>,greater<int>> minq;
        
        int i = 0, j = 0;
        while(size1){
            if(n > m) minq.push(nums1[i++]);
            else minq.push(nums2[j++]);
            size1--;
        }
  
        while(i < n || j < m){
            if (i < n) minq.push(nums1[i++]);
            else if (j < m) minq.push(nums2[j++]);
            auto e = minq.top();
            minq.pop();
            maxq.push(e);
        }
        
        return (n + m)&1 ? maxq.top()*1.0 : (minq.top()+maxq.top())/2.0;
    }
};
```
