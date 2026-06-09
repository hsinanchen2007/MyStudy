### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string minWindow(string s, string t) {       
        vector<int> hashVect(256,0);
        int counter = 0;
        int maxlen = s.size()+1;
        int left = 0;
        string strRet = "";

        for (int i = 0; i < t.size(); i++){
            hashVect[t[i]]++;
        }

        for (int right = 0; right < s.size(); right++){
            hashVect[s[right]]--;

            if (hashVect[s[right]] >= 0){
                counter++;

            }

            while (counter == t.size()){
                if (maxlen > right - left + 1){
                    maxlen = right - left + 1;
                    strRet = s.substr(left,maxlen);
                }

                if (hashVect[s[left]] >= 0) counter--;

                hashVect[s[left]]++;
                left++;
            }
        }

        return strRet;
    }
};
```