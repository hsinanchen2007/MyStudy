第一次写题解
直接数成对*2
如果有奇数的则+1就可

class Solution {
public:
    int longestPalindrome(string s) {
        int hashCount[52]={0};
        for(string::size_type i=0;i<s.size();i++){
            if('a' <= s[i] && s[i]<='z'){
                hashCount[s[i]-'a']++;
            }else{
                hashCount[s[i]-'A'+26]++;
            }
        }
        int sum = 0;
        bool flag = false;
        int x=0;
        for(int i = 0; i < 52; i++){
                x=hashCount[i]/2;
            if(x>=1){
                sum+=2*x;
            }
            if(hashCount[i]&1){
                flag=true;
            }
        }
        if(flag==true){
            sum+=1;
        }
        return sum;
    }
};
