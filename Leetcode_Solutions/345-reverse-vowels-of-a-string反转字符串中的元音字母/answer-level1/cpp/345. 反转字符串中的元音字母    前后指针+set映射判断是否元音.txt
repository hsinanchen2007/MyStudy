### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        set<char> a;
        a.insert('a');
        a.insert('e');
        a.insert('i');
        a.insert('o');
        a.insert('u');
        a.insert('A');
        a.insert('E');
        a.insert('I');
        a.insert('O');
        a.insert('U');
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            while(!(a.find(s[i])!=a.end())&&i<j)
                i++;
            while(!(a.find(s[j])!=a.end())&&i<j)
                j--;
            swap(s[i++],s[j--]);
        }
        return s;
    }
};

```