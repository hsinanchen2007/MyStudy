char* reverseLeftWords(char* s, int n){
    n%=strlen(s);
    reverse(s,0,n-1);
    reverse(s,n,strlen(s)-1);
    reverse(s,0,strlen(s)-1);
    return s;
}
void reverse(char *s, int start, int end)
{
    char t;
    for(int i=0;i<=(end-start)/2;i++)
    {
        t=s[start+i];
        s[start+i]=s[end-i];
        s[end-i]=t;
    }
}