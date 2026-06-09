### 解题思路
先把nums2放到num1尾部，在进行排序
执行用时 :
4 ms
, 在所有 cpp 提交中击败了
96.09%
的用户
内存消耗 :
8.7 MB
, 在所有 cpp 提交中击败了
84.25%
的用户
### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++)
        {
            nums1[m+i]=nums2[i];
        }
        for(int i=0;i<m+n;i++)
        {
            for(int j=i+1;j<m+n;j++)
            {
                if(nums1[i]>nums1[j])
                swap(nums1[i],nums1[j]);

            }
            
        }
    }
private:
void swap(int &t1,int &t2)
{
    int tmp=t1;
    t1=t2;
    t2=tmp;
}
};
```