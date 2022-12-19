```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n -1;
        int index = m + n -1;
        while(i >= 0 && j >= 0 && index >= 0){
            if(nums1[i] > nums2[j]){
                nums1[index] = nums1[i];
                i--;
            }else{
                nums1[index] = nums2[j];
                j--;
            }
            index--;
        }
        if(i >= 0){
            for(int p = i; p >= 0; p--){
                nums1[index--] = nums1[p];
            }
        }else if(j >= 0){
            for(int p = j; p >= 0; p--){
                nums1[index--] = nums2[p];
            }
        }
    }
```
