![image.png](https://pic.leetcode-cn.com/7c54ea54e010281c101277fe3391cc9f95f4a09d4b6ab8446465af29e403928c-image.png)
解题思路：对chars数组的各个字母计数，与字符串数组中的字母比较，若相等，计数减一。若计数小于0则不能构造该单词，反之则可以。
``` 
        int charCount[26];
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        for (auto& c:chars)
            charCount[c - 'a']++;
        
        for (auto& word:words) {
            int tempCharCount[26];
            copy(begin(charCount), end(charCount), begin(tempCharCount));
            bool isValid = true;
            for (auto& w:word) {
                if (tempCharCount[w - 'a'] == 0) {
                    isValid = false;
                    continue;
                }
                tempCharCount[w - 'a']--;
            }
            
            if (isValid)
                res += word.size();
        }
        
        return res;
    }
```

