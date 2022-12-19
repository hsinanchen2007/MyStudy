### 解题思路
我们稍微观察一下就可发现以下规律
0 0 交换-> 0 0 取非-> 1 1
0 1 交换-> 1 0 取非-> 0 1
1 0 交换-> 0 1 取非-> 1 0
1 1 交换-> 1 1 取非-> 0 0
a b -> if a==b a=!a b=!b
然后在原地修改就可以了，无需交换，时间复杂度为O(m*n/2)，注意我们行只遍历一半，
当行为奇数时最中间一个没有遍历到，在该行遍历结束后直接将其取反即可，
空间消耗也只是记录两个行列的大小的常数空间

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m=A.size();
        int n=A.at(0).size();
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n/2;++j)
            {
                if(A.at(i).at(j)==A.at(i).at(n-j-1))
                {
                    A.at(i).at(j)=!A.at(i).at(j);
                    A.at(i).at(n-j-1)=!A.at(i).at(n-j-1);
                }
            }
            if(n&1) A.at(i).at(n/2)=!A.at(i).at(n/2);
        }
        return A;
    }
};
```