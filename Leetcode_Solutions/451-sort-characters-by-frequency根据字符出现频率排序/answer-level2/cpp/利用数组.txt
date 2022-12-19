### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string frequencySort(string s) {
        pair<int, char> freq[256];
        for(int i = 0 ; i < 256 ; i ++){
            freq[i].first = 0;
            freq[i].second = i;
        }

        for(int i = 0 ; i < s.size() ; i ++)
            freq[s[i]].first ++;

        sort(freq, freq + 256, greater<pair<int, char>>());

        int index = 0;
        for(int i = 0 ; i < s.size() ; i ++){
            while(!freq[index].first)
                index ++;
            s[i] = freq[index].second;
            freq[index].first --;
        }

        return s;
    }
};
```