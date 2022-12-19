### 解题思路
类似于，插入排序，先找到第一个 小于等于p2指向的值的元素位置p1，放上去。而前面循环搬动
1 2 6 0 0 0 
1 2 3

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1,p2=0;
        int cnt=p1;
       
        for(;p2<n;++p2){
            while(p1>=0&&nums2[p2]<nums1[p1]){
                nums1[p1+1]=nums1[p1];
                p1--;
            }
            nums1[p1+1]=nums2[p2];
            cnt++;
            p1=cnt;;
            
        }
      
    }
};
```