### 解题思路
一次循环，对称交换值

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int nLength = s.size();
            vector<char>::iterator it;
            it = s.begin();
            for(int i = 0; i < nLength / 2 ; i++)
            {
                char temp = s[i];
        // 		s[i] = s[nLength - i];
        // 		s[nLength - i] = temp;
                *(it + i) = *(it + nLength - 1 -i);
                *(it + nLength - 1 -i) = temp;
            }
    }
};
```