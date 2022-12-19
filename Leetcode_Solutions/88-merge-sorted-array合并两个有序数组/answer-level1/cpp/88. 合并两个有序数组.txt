## 把两数组末端的元素放到nums1的后面 100%
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1, no=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j])
                nums1[no--] = nums1[i--];
            else
                nums1[no--] = nums2[j--];
        }
        //如果i>=0不用管；如果j>=0，把nums2剩余数字放到nums1中
        while(j>=0) nums1[no--] = nums2[j--];
    }
};
```
## 利用辅助vector
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3;
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                nums3.push_back(nums1[i]);
                i++;
            }
            else{
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            nums3.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            nums3.push_back(nums2[j]);
            j++;
        }
        for(int i=0; i<m+n; i++){
            nums1[i] = nums3[i];
        }
    }
};
```
## 直接放到一块排序
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};
```