
```c++
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> char_count;
        for(char ch:chars)
           char_count[ch]++;
        int ans=0;
        for(string word:words)
        {
            unordered_map<char,int> temp_count;
            for(char ch :word)
                temp_count[ch]++;
            bool is_ans=true;
            for(char ch :word)
            {
                if(temp_count[ch]>char_count[ch])
                {
                    is_ans=false;
                    break;
                }
            }
            if(is_ans)
                ans+=word.length();
                
        }
        return ans;
    }
};
```