### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    // nums1有m个，nums2有n个，比较两数组的最大值，放入m+n-1的位置
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m+n-1;
        while(n){
            // nums1个数为0，或者nums1的最大值小于等于nums2
            if (m==0 || nums1[m-1]<=nums2[n-1]) {
                // 将nums2的插入到nums1
                nums1[last--] = nums2[--n];
            }
            else {
                // nums1的调整位置
                nums1[last--]=nums1[--m];
            }
        }
    }
};



#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int last = m+n-1;
    while (n) {
        if (m==0 || nums1[m-1]<=nums2[n-1]) {
            nums1[last--] = nums2[--n];
        }
        else {
            nums1[last--]=nums1[--m];
        }
    }
}

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    merge(nums1, 3, nums2, 3);
    for (int i=0; i<nums1.size(); i++) {
        if (i==nums1.size()-1) cout << nums1[i];
        else cout << nums1[i] << ",";
    }
}



```