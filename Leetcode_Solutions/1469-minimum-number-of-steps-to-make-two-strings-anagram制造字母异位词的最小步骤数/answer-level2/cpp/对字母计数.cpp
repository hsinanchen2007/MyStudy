`
class Solution {
public:
    int minSteps(string s, string t) {

        int count=0;
        int a[26]={0};
        for(int i=0;i<s.length();i++)
        {
           a[s[i]-'a']+=1;
        }
        for(int i=0;i<t.length();i++)
        {
            a[t[i]-'a']-=1;
        }
        for(int i=0;i<26;i++)
            if(a[i]>0)
                count+=a[i];
        return count;

    }
};
`