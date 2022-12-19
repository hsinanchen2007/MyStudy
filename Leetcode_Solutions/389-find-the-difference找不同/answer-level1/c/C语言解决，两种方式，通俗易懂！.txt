# 方式一：利用数组记录s出现字符个数，当遍历t时把相应字符个数减一，因为t=s+一个随机字符，数组出现小于0的情况即为那个随机字符。```
代码块
```char findTheDifference(char * s, char * t){
    int map[26] = {0};
    int len_s = strlen(s);
    int len_t = strlen(t);
    for(int i=0;i<len_s;i++)
        map[s[i]-'a']++;
    for(int j=0;j<len_t;j++)
        if(--map[t[j]-'a']<0)
            return t[j];
    return 0;
}
**# 方式二：利用异或解决 
思路：0异或任何数A 结果还是A
     相同数B异或本身 结果为0**
char findTheDifference(char * s, char * t){
    int a = 0;
    int len_s = strlen(s);
    int len_t = strlen(t);
    for(int i=0;i<len_s;i++)
        a = a^s[i];
    for(int j=0;j<len_t;j++)
        a = a^t[j];
    return a;
}
