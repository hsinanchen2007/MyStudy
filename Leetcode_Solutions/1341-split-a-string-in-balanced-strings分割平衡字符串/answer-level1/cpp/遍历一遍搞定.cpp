```
class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0;
        int temp = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L'){
                temp++;
            }
            if(s[i] == 'R'){
                temp--;
            }
            if(temp == 0){
                cnt++;
            }
        }
        return cnt;
    }
};
```
