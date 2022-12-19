

### 代码

```cpp
class Solution {
public:
int judge(string &s,vector<int>record){
        for(char c:s)
            record[c-'a']--;;
        for(int n:record)
            if(n<0)
                return 0;
        return s.size();
}
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        if(words.size()==0||chars.size()==0)
            return ans;
        vector<int>record(27,0);
        for(char c:chars)
            record[c-'a']++;
        for(string s:words){
            ans+=judge(s,record);
        }  
        return ans;
    }
};

```