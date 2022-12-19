
```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();

        for (int i = 0; i < len1; i++){
            for (int j = 0; j < len2; j++){
                if (nums1[i] == nums2[j]){
                    nums1[i] = j;
                    break;
                }
            }
        }
        for (int i = 0; i < len2; i++){
            int j = i + 1;
            for (; j < len2; j++){
                if (nums2[j] > nums2[i]){
                    nums2[i] = nums2[j];
                    break;
                }
            }
            if (j == len2){
                nums2[i] = -1;
            }
        }
        for (int i = 0; i < len1; i++){
            nums1[i] = nums2[nums1[i]];
        }
        return nums1;
    }
};
```