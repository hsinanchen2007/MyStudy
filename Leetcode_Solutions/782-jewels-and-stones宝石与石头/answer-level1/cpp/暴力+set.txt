方法一 暴力
```
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res=0;
        for(char s:S){
            for(char j:J){
                if(s==j){
                    ++res;
                    break;
                } 
            }  
        } 
        return res;
    }
};
```
方法二 set
```
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res=0;
        unordered_set<char> st;
        for(char j:J) st.insert(j);
        for(char s:S)
            if(st.count(s)) ++res;
        return res;
    }
};
```
