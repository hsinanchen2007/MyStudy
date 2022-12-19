### 解题思路
1.拷贝后合并, 空间复杂度$O(N)$
2.双指针从后向前扫描, 空间复杂度$O(1)$
### 代码

```c++ []
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)
            return;
        vector<int> nums3;
        for(int i=0; i<m; ++i){
            nums3.push_back(nums1[i]);
        }

        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(nums3[i]<nums2[j])
                nums1[k++] = nums3[i++];
            else
                nums1[k++] = nums2[j++];
        }

        while(i<m)
            nums1[k++] = nums3[i++];

        while(j<n)
            nums1[k++] = nums2[j++];
    }
};
```
```java []
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // 空间复杂度为O(1)解法
        // 双指针, 从后向前
        if(n == 0)
            return;
        
        int p1 = m-1;
        int p2 = n-1;
        int p3 = m+n-1;
        while(p1 >=0 && p2>=0){
            nums1[p3--] = nums1[p1]>nums2[p2] ? nums1[p1--] : nums2[p2--];
        }
        System.arraycopy(nums2, 0, nums1, 0, p2+1);
    }
}
```
```python []
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if n == 0:
            return
        p1, p2, p3 = m-1, n-1, m+n-1
        while p1>=0 and p2>=0:
            if nums1[p1] > nums2[p2]:
                nums1[p3] = nums1[p1]
                p3-=1
                p1-=1
            else:
                nums1[p3] = nums2[p2]
                p3-=1
                p2-=1

        nums1[:p2+1] = nums2[:p2+1]
```