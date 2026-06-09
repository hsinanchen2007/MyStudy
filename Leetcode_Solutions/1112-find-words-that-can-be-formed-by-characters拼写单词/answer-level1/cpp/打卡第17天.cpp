检查字符个数是否都在chars里字符数目之内
```
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int a[26] = {0};
        for(auto k: chars){
            a[k-'a'] += 1;
        }
        int count = 0;
        for(string s: words){
            if(check(s, a)){
                count += s.size();
            }

        }
        return count;


    }
    bool check(string& s, int a[]){
        int tmp[26] = {0};
        for(char c : s) {
            tmp[c-'a'] += 1;
        }
        for(int i=0;i<26;i++){
            if(tmp[i]>a[i]){
                return false;
            }
        }
        return true;
    }
};
```
