### 解题思路
这里直接采用思路简单直接的贪心算法。
首先，题目要求A的优势最大化，也就是说在两者对应位置上的数据，A比B大的数量要尽可能多，是典型的贪心思路。
求解时首先对A排序，然后直接从左到右遍历B，在遍历时注意：
1、为了保证A比B大的位置尽可能多，B上的每个数据，在A中找到比B大的最小值放在对应位置。虽然A中有更大的值，但是可以使用在后面，充分利用。
2、如果找不到比B大的值，就将A中剩下的最小值放在对应位置。因为是最小值，A中更大的值可以放在其他位置，充分利用。
遍历结束后得到的数组就是答案。
需要注意的是，在寻找1中的最小值的时候，使用二分查找，不然会超时。

### 代码

```cpp
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(),A.end());
        vector<int> res;
        for(int i=0;i<B.size();i++)
        {
            int l=0,r=A.size()-1;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(A[mid]>B[i])
                    r=mid;
                else
                    l=mid+1;
            }
            if(A[l]>B[i])
            {
                res.push_back(A[l]);
                A.erase(A.begin()+l);
            }
            else
            {
                vector<int>::iterator it=A.begin();
                res.push_back((*it));
                A.erase(it);
            }
        }
        return res;
    }
};
```