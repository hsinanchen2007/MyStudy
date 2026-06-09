char * gcdOfStrings(char * str1, char * str2){
    if(str1=="" || str2=="")return "";
    char *s1=(char*)malloc(strlen(str1)+strlen(str2)+1);
    char *s2=(char*)malloc(strlen(str1)+strlen(str2)+1);
    strcpy(s1,str1);
    strcpy(s2,str2);
    strcat(s1,str2);
    strcat(s2,str1);
    while(*s1!='\0')             //if(strcmp(s1,s2)!=0)return "";直接用这个函数竟然时间空间都要大
    {                           
        if(*s1++!=*s2++)
        {
            return "";
        }
    }
    str1[gcd(strlen(str1),strlen(str2))]='\0';
    return str1;
}
int gcd(int a,int b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}