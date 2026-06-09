### 解题思路
注意：如果相等，继续让i或j向右滑动；
注意它的终止条件是i<=target/2
还有就是二位动态数组：先定义一个vector存储 然后pushback到二维里

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        
        int i=1,j=2;
        int sum=i+j;
        while(i<=target/2)
        {
            if(sum<target)
            {
                ++j;
                sum=sum+j;
            }
            else if(sum>target)
            {
                sum=sum-i;
                ++i;
            }
            else//sum==target
            {vector<int> a;
                for(int k=i;k<=j;++k)
                    a.push_back(k);
                res.push_back(a);
                ++j;sum=sum+j;
            }
        }
        return res;


    }
};
```