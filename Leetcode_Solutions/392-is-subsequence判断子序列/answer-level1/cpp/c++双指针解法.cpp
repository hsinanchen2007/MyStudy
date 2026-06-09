class Solution {
public:
    bool isSubsequence(string s, string t) {
         int i=0,j=0;
         int lens=s.size();int lent=t.size();
         while(j<lent&&i<lens)//双指针判断 时间复杂度为o(n)
         {
             if(s[i]==t[j])
             {
                 i++;j++;
             }
             else j++;
         }
         if(i==lens)return true;
         else return false;
    }
};