### 解题思路
1、先排除两种特殊情况；
2、两个数组从后往前遍历（nums1从m-1开始），大的数插在nums1最后方，直到遍历完某一个数组；
3、如果nums2没有遍历完，则将其按顺序插入nums1最前方

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0) nums1 = nums2;
        else if(n == 0) return;
        else{
            int ni = n - 1;
            for(int mi = m - 1, record = 0; ni != -1 && mi != -1; record++)
            {
                if(nums1[mi] > nums2[ni])
                {
                    nums1[nums1.size() - 1 - record] = nums1[mi];
                    mi--;
                } 
                else
                {
                    nums1[nums1.size() - 1 - record] = nums2[ni];
                    ni--;
                } 
            }

            if(ni != -1)
            {
                for(int j = 0; j <= ni; j++) nums1[j] = nums2[j];
            }
        }
    }
};
```