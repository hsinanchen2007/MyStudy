从后往前
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len=m+n-1;
        m--;
        n--;
        while(m >= 0 && n >= 0){
            if(nums1[m] >nums2[n])  nums1[len--] = nums1[m--];
            else
                nums1[len--] = nums2[n--];
        }  
        while(n >= 0){
            nums1[len--] = nums2[n--];
        }
    }
};
```
从前往后
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0){
            swap(nums1,nums2);
            return;
        }
        if(n == 0)
            return;
        auto p1 = nums1.erase(nums1.begin()+m,nums1.end());       //删除nums1占位的0
         p1 = nums1.begin();  
        auto p2 = nums2.begin();
        
        while((p2 != nums2.end()) && (p1 != nums1.end()) ){
            if(*p2 <= *p1) {
                p1 = nums1.insert(p1,*p2);
                p2++;
                p1++;
            }
           else {                           //不要写成 if(*p2 > *p1)。。。找了好久bug。。。
                p1++;
            }
        }
        while(p2 != nums2.end()){
            nums1.push_back(*p2);
            p2++;
        }
    }
};
```
