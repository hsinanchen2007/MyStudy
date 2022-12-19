```
class Solution {
public:
    string reverseWords(string s) {
        string ret = "" ;
        int i=0 , j=0 ;
        while (j<=s.length() && i <s.length()) {
            if( (s[j]==' ' && s[i] != s[j] ) || (j==s.length() && s[j-1] !=' ') ) {
                int wj = j-1 ; 
                int si = i ;
                int ej = j;
                while (i < wj) {
                    char temp = s[i] ;
                    s[i] = s[wj] ;
                    s[wj] = temp ;
                    i++ ;
                    wj -- ;
                }
                if (si <= ej) {
                    ret += " " + s.substr(si,ej-si) ;
                }
                i = j  ;
            }else if(s[j]==' ' && s[i] == s[j]) {
                i ++ ;
                j ++ ;
            }else{
                j ++ ;
            }
        }
        if (ret.length() > 0)
            ret = ret.substr(1,ret.length()-1) ;
        i=0 ,j =ret.length() -1 ;
        while(i<j) {
            char temp = ret[i] ;
            ret[i] =ret[j] ;
            ret[j] = temp ;
            i++ ;
            j-- ;        
        }
        return ret ;
    }
};
```
