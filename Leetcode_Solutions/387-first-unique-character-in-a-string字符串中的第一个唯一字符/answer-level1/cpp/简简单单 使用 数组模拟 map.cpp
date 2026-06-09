利用一个数组记录出现的次数, **重点看题目的 所有字符都是小写字母**
遍历字符串记录每个字符出现的次数
第二次遍历字符串， 若该字符只出现一次， 返回结果


`    int firstUniqChar(string s) {
        if (s.size() == 0) {
            return -1;
        }
        if (s.size() == 1) {
            return 0;
        }
        int hashmap[26];
        memset(hashmap, 0, 26 * sizeof(int));
        for (int i = 0; i < s.size(); ++i) {
            ++hashmap[s[i] - 'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (hashmap[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
`