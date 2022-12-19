不需要排序，也不需要插入。
因为S（字典）中的每个字母和位置一一对应，可用一维数组pos记录每个位置出现的字符
再遍历T，用一维数组count记录每个字母出现的次数。
然后按照位置依次追加：该位置出现字符（追加次数已被count数组记录），将已追加的字符次数清空为0。
最后遍历count数组，将不为0的字符追加到字符串末尾即可。
```
    string customSortString(string S, string T) {
        int pos[S.length()];
        for (int i = 0; i < S.length(); ++i) {
            pos[i] = S[i];
        }
        int count[26] = {0};
        for (int i = 0; i < T.length(); ++i) {
            count[T[i] - 97]++;
        }
        string res;
        for (int i = 0; i < S.length(); ++i) {
            res.append(count[pos[i] - 97], pos[i]);
            count[pos[i] - 97] = 0;
        }
        for (int i = 0; i < 26; ++i) {
            if (count[i]) {
                res.append(count[i], i + 97);
            }
        }
        return res;
    }
```