### 解题思路
从后往前扫描，最后再把结果反转。
需要注意的一个地方就是：- 应该在循环体的最前面加，不然可能会在最终结果的前面多一个-

### 代码

```cpp
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int index = S.size() - 1;
        string res ;
        int count = 0;
        while(index >= 0){
            if(S[index] == '-')
                index--;
            else{
                if(count && count%K == 0)
                    res += '-';
                if(S[index]>='a' && S[index]<='z')
                    res += S[index--] - 32;
                else
                    res += S[index--];
                count++;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
```