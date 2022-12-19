class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt_l = 0, cnt_r = 0, cnt = 0;
        int k = 0;
        while(k < s.length()){
            if(s[k] == 'L')cnt_l++;
            else cnt_r++;
            if(cnt_r == cnt_l){
                cnt++;
                cnt_l = cnt_r = 0;
            }
            k++;
        }
        return cnt;
    }
};