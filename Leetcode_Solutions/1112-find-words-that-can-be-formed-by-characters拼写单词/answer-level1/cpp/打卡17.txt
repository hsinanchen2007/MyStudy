### 解题思路
  用一个数组来保存chars的各字符个数，然后就只要遍历words中的每个字符串中的各个字符个数是否都能小于或等于chars中相同的各个字符个数。符合条件的就加上这个字符串的长度即可。

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> r(26 , 0);
        for(auto x : chars){
            r[(x - 'a')]++;
        }
        int s = 0;
        for(auto x : words){
            vector<int> t = r;
            int i;
            for(i = 0 ; i < x.length() ; i++){
                if(t[(x[i] - 'a')])t[(x[i] - 'a')]--;
                else break;
            }
            if(i == x.length())s += x.length();
        }
        return s;
    }
};
```