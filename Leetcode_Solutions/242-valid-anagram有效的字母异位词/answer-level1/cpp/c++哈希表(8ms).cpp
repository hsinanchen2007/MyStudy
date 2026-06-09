构建一个长度位26的数组，用来记录s中每个字符出现的次数。再以t中的字符为下标，将数组中对应下标的次数减一。这样，如果是异位词，最终的数组元素全部都是0。
```
class Solution {
public:
    bool isAnagram(string s, string t) {
        int c[26] = {0};
        for(char n : s)
            c[n - 'a']++;
        for(char n : t)
            c[n - 'a'] --;
        for(int i = 0;i<26;i++){
            if(c[i] == 0)
                continue;
            else
                return false;
        }
        return true;
    }
};
```
