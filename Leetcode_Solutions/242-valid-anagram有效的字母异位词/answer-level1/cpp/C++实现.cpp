
```
/**
题意： 字母个数相同就行
利用26个字母Ascll数组来存这些字母并++ （另一个对比时--）
*/

// 第一种：直接比较sort（或者用unorder_map 都太差了）
    bool isAnagram1(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if (s == t) return true;

        return false;
    }

// 第二种:
    bool isAnagram(string s, string t) {
         if (s.length() != t.length()) return false;

        // 这里暂时26个小写字母
        int arr[26] = {0};
        for (char& c : s) {
            arr[c-'a'] = ++arr[c - 'a'];
        }

        for (char& c : t) {
           if (--arr[c - 'a'] < 0) return false;
        }

        return true;
    }
```
