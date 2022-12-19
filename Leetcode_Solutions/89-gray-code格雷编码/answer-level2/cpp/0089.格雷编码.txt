### 解题思路
二进制码和格雷码之间的转换有公式.
$G_i$表示格雷码, $B_i$表示二进制码.
$G_{n-1}=B_{n-1}$
$G_i=B_i\oplus B_{i+1}(i=0,1,2...n-2)$

### 代码

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int N=(1<<n);
        for(int i=0;i<N;i++)
            ans.push_back(i^(i>>1));
        return ans;
    }
};
```