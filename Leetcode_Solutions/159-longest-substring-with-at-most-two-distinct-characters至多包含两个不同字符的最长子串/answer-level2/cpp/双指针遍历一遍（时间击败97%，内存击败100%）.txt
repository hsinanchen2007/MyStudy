class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int start1, end;
        char a1,a2,c_end;
        int res = 0;
        a1 = s[0];
        start1 = 0;
        int i;
        for(i = 1; i < s.length(); i ++)
            if(s[i]! = a1) {
                a2 = s[i];
                end = i;
                c_end = s[i];
                break;
            }
        for(;i<s.length(); i ++){
            if(s[i]! = a1 && s[i] != a2){
                int tmp = i-start1;
                res = max(res, tmp);
                start1 = end;
                a1 = c_end;
                a2 = s[i];
                end = i;
                c_end = s[i];
            } else if(s[i] != c_end){
                end = i;
                c_end = s[i];
            } 
        }
        int tmp = s.length()-start1;
        res = max(res, tmp);
        return res;
    }
};