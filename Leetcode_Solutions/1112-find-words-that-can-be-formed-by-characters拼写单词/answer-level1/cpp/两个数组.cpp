### 解题思路
两个数组word_count、chars_count分别计算words中word的每个字母出现次数和chars中每个字母出现的次数。如果word_count中出现比chars_count大的元素，则说明chars中字母无法组成该word。

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>chars_count(26);
        vector<int>word_count(26);
        bool flag = true;
        string ans;
        for(char c:chars){
            chars_count[c - 'a'] ++;
        }
        for(auto word : words){
            flag = true;
           // cout<<word<<endl;
            for(char i : word){
                word_count[i - 'a']++;
            }
            //cout<<chars_count<<word_count<<endl;
            for(int i = 0; i < word_count.size(); i++){
                if(word_count[i] > chars_count[i]){
                    flag = false;
                    break;
                }
            }
        
            word_count = vector<int>(26,0);//重置word的计数数组
            if(flag){
                ans += word;;
            }
        
        }
       // cout<<ans;
     return ans.size();
    }
};
```