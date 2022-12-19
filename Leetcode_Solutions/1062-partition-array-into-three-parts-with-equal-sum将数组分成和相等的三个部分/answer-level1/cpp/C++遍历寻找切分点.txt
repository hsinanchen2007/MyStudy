### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n=A.size();
        if(n<3) return false;
        int sum=0;
        for(int a:A)
        {
            sum+=a;
        }

        if(sum%3 != 0) return false;
        int target=sum/3;
        int split=1;
        sum=0;

        for(int i=0; i<n; ++i)
        {
            sum+=A[i];
            if(sum==target*split && i<n) split++;
        }

        return split>3;
    }
};
```