### 解题思路
1.将C[i]+D[j]的和放入查找表中，记录每个和出现的次数
2.检查0-A[i]-B[j]的值是否在表中
    如果在，结果加这个值出现的次数。

### 代码

```cpp
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        //C+D和的次数
        map<int,int>record;
        for(int i=0;i<C.size();i++)        
            for(int j=0;j<D.size();j++)            
                record[C[i]+D[j]]++;
            
        int res = 0;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
                if(record.find(0-A[i]-B[j])!=record.end())
                    res+=record[0-A[i]-B[j]];
            }
        }
        return res;
    }
};
```