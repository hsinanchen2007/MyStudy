判断两串字符串，如果字符串的和相等且积相等，则判定两串字符串相等
```
bool isAnagram(char * s, char * t){
    unsigned long s1,s2,t1,t2;
    s1 = s2 = t1 = t2 = 1;
    while(*s != '\0'){
        *s -=96;
        s1 *= *s;
        s2 += *(s++);
    }
    while(*t != '\0'){
        *t -= 96;
        t1 *= *t;
        t2 += *(t++);
    }
    
    if(s1 == t1 && s2 == t2)
        return true;
    return false;
}
```
