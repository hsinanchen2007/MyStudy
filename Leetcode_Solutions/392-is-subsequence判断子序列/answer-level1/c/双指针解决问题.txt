bool isSubsequence(char * s, char * t){
    int i=0,j=0;
    int lent=strlen(t);
    int lens=strlen(s);
    if(lens==0)
        return true;
    while(i<lens&&j<lent){
      while(j<lent&&t[j]!=s[i])
          j++;
      if(t[j]==s[i]){
          i++;
          j++;
      }
    }
    if(s[i]=='\0')
        return true;
    else
        return false;
}