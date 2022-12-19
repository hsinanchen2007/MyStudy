### 解题思路
规律：
target=序列长度*序列中位数，分两类情况：1.中位数是整数，序列长度是奇数2.中位数小数点后为0.5，序列长度是偶数。序列长度从最大可能值到最小可能值，判定（序列中位数=(double)target/序列长度）是否符合上面这两种情况，如果符合即为正确序列。

比如：
9=2+3+4=3*3,9=4+5=2*4.5,15=1+2+3+4+5=5*3.

时间复杂度：O(target)

执行用时 :
4 ms
, 在所有 C++ 提交中击败了
87.69%
的用户
内存消耗 :
8.3 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int maxlen=(int)sqrt(target*2);
        int i,j;
        vector<vector<int>> vec;
        for(i=maxlen;i>=2;i--)
        {
            double temp=((double)target)/((double)i);
            vector<int> res;
            if((temp-(int)(temp))==0&&i%2==1)
            {
                for(j=((int)temp)-i/2;j<=((int)temp)+i/2;j++)
                {
                    res.emplace_back(j);
                }
                vec.emplace_back(res);
            }
            else if((temp-(int)(temp))!=0&&((temp-(int)(temp))==0.5&&i%2==0))
            {
                for(j=((int)temp)-i/2+1;j<=((int)temp)+i/2;j++)
                {
                    res.emplace_back(j);
                }
                vec.emplace_back(res);
            }
            
        }
        return vec;
    }
};
```