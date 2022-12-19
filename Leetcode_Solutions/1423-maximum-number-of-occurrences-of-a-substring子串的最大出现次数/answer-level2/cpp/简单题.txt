### 解题思路
此处撰写解题思路
// 不说了，这maxSize根本就没啥用。怪自己审题不仔细，没体会到T T
### 代码

```cpp
class Solution {
public:
    int alph[26] = {0};
    bool isOk(string temp, int k) {
        int nums = 0;
        for(int i = 0; i < temp.length(); i++) {
            int index = temp[i] - 'a';
            alph[index]++;
        }

        for(int i = 0; i < 26; i++) {
            if(alph[i] != 0) nums++;
        }

        if(nums <= k) return true;
        else return false;
    }

    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int len = s.length();
        if(len < minSize) return 0;
        
        map<string, int> hp;
        for(int j = 0; j + minSize - 1 < len; j++) {
            memset(alph, 0, sizeof(alph));
            string temp = s.substr(j, minSize);
            map<string, int>::iterator it = hp.find(temp);
            if(it != hp.end()) hp[temp]++;
            else 
                if(isOk(temp, maxLetters)) 
                    hp.insert(pair<string, int>(temp, 1));
        }

        int nums = 0;
        map<string, int>::iterator it = hp.begin();
        while(it != hp.end()) {
            if(it->second > nums) nums = it->second;
            it++;
        }

        return nums;
    }
};
```