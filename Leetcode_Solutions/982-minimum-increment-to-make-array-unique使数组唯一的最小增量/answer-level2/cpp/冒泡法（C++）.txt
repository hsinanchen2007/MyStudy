### 解题思路
感觉是冒泡排序的变体。
中间有两段循环体可以优化成直接计算，性能应该还能提升。

### 代码

```cpp
class Solution {
    

public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.size()<2) return 0;
        sort(A.begin(),A.end());
        int s=A.size();
        int i;
        int t=A[0];
        int count=1;
        int sum=0;
        for (i=1;i<s;i++)
        {
            if (A[i]==t){
                count++;
            }
            else 
            {
                for (;count>1 && t <A[i];t++) //1
                {
                    sum+=(--count);
                }
                if (count==1 && t<A[i]) 
                {
                    t=A[i];
                }
                else count++;
            }
        }
        if (count>1) 
        {
            for (;count>1 ;t++) //2
            {
                sum+=(--count);
            }
        }
        return sum;
    }
};
```