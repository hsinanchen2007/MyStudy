int isNo(char ch)
{
    int ret = 0;
    if( (ch >= '0'&& ch<= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        ret = 1;
    }
    return ret;
}

int isEqu(char *s,int i,int j)
{
    if( s[i] >= 'a') return (s[i] == s[j] || s[i] == s[j] + 32);
    if( s[i] >= 'A') return (s[i] == s[j] || s[i] == s[j] - 32);
    return s[i] == s[j];
}

int isPa(char *s,int i,int j)
{
  
    if(i >= j) return 1;
    
    if(!isNo(s[i])) return isPa(s,i+1,j);
    if(!isNo(s[j])) return isPa(s,i,j-1);
    
    return (isEqu(s,i,j))?(isPa(s,i+1,j-1)):0;
}

bool isPalindrome(char * s){
    if(0 == strlen(s)){
        return 1;
    }
    return isPa(s,0,strlen(s) -1);
}

