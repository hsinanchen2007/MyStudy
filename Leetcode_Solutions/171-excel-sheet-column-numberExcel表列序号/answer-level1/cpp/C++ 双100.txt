class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        int size=s.size();
        for(int i=0;i<size;i++)
        {
            ans+=(s[i]-'A'+1)*pow(26,size-1-i);
        }
        return ans;
    }
};