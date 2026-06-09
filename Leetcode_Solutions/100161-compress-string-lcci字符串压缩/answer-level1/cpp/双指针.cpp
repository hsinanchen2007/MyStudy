### 解题思路
双指针，难得有思路。。。

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        if(S.length() <= 2)
        return S;
        int l = S.length();
        string S1;
        
        int i = 0, j = 0;

        while(i < l){
            int count = 1;
            j = i + 1;
            while( j < l && S[i] == S[j]){
                j++;
                count++;
            }
            S1 += S[i];
            S1 += to_string(count);
            i = j;
        }
        //cout<<S1;
        return S1.size() > S.size() ? S : S1;
    }
};
```