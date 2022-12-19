### 解题思路
我不管，写了我一个半小时，debug了一个小时的暴力算法，我也要发出来，毕竟这题是困难程度=。=

### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int count=-1;
        vector<int>::iterator it1;
        vector<int>::iterator it2;
        it1=nums1.begin();
        it2=nums2.begin();
        while(it1!=nums1.end()&& it2!=nums2.end()){
            nums.push_back(*it1<*it2?*(it1++):*(it2++));
            count++;
        }
        while(it1!=nums1.end()){
            nums.push_back(*(it1++));
            count++;
        }
        while(it2!=nums2.end()){
            nums.push_back(*(it2++));
            count++;
        }
        if(count%2!=0){
             double mid=0;
    mid=((double)nums[count/2]+(double)nums[count/2+1])/2;
              return mid;
        }
        else{
            double mid;
            mid=(double)nums[count/2];
            cout<<"!!!"<<count;
           return mid;
        }
        
        

    }
};
```