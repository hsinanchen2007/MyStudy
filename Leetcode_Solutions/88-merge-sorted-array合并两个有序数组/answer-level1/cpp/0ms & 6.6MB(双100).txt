### 解题思路
新建一个数组存pos用来存储合并的数据
逐项比较nums1和nums2，小的值存入pos
有一个数组遍历完即结束循环
因为是有序数组，所以没比较完的数组元素即为较大的值，将其存入pos即可
最后重置nums1为pos

### 代码

```cpp
class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int m_i = 0;
        int n_i = 0;
        int j = 0;
        int len = m + n;
        vector<int> pos(len);
        while((m_i < m) && (n_i < n))
        {
            pos[j] = ((nums1[m_i] < nums2[n_i]) ? (nums1[m_i]) : (nums2[n_i]));
            if(nums1[m_i] <= nums2[n_i])
            {
                m_i++;
            }
            else
            {
                n_i++;
            }
            j++;            
        }
        while(m_i < m)
        {
            pos[j] = nums1[m_i];
            j++;
            m_i++;
        }
        while(n_i < n)
        {
            pos[j] = nums2[n_i];
            j++;
            n_i++;
        }
        nums1 = pos;
    }
};
```