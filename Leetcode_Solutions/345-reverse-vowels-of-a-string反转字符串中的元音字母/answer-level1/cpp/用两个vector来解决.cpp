### 解题思路
思路比较粗暴；
用一个vector来存放元音位置，另一个用来存放元音字母；
然后位置一换；
就是挺占内存

### 代码

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        vector<char> value;
        vector<int> index;
        //set<char> ss = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
        int length = s.size();
        for (int i = 0; i < length; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' )
            {
                index.push_back(i);
                value.push_back(s[i]);

            }
        }
        for (int j = 0; j < index.size(); j++)
        {
            s[index[j]] = value[value.size()-1];
            value.pop_back();

        }
        return s;


    }
};
```