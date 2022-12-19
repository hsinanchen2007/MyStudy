先判断两字符串长度是否相等，若不相等则false，若相等则将两字符串中每种字母的个数做差,若结果为0则true，不为0则false
```
bool isAnagram(char * s, char * t){
    int n=strlen(s),m=strlen(t);
    if(n!=m)
        return false;
    int a[26]={0};
    for(int i=0;i<n;i++){
        a[s[i]-'a']++;
        a[t[i]-'a']--;
    }
    for(int i=0;i<26;i++)
        if(a[i]!=0)
            return false;
    return true;
}
```
