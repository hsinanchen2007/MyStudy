(1)st1 + str2 == str2 + st1
(2)求两个字符串的最大公约数
```
int Gcd (int a, int b)
{
    if (a % b == 0) {
        return b;
    }
    return Gcd(b, a % b);
}

char * gcdOfStrings(char * str1, char * str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 == 0 || len2 == 0) {
        return "";
    }
    int len = len1 + len2 + 1;
    int gcdvalue = 0;
    char *s1 = (char *)malloc(sizeof(char) * len);
    char *s2 = (char *)malloc(sizeof(char) * len);
    char *s = (char *)malloc(sizeof(char) * len);
    int idex = 0;
    int i;
    for (i = 0; i < len1 + len2; i++) {
        if (i < len1) {
            s1[idex++] = str1[i];
        } else {
            s1[idex++] = str2[i - len1];
        }
    }
    s1[idex] = '\0';
    idex = 0;
    for (i = 0; i < len1 + len2; i++) {
        if (i < len2) {
            s2[idex++] = str2[i];
        } else {
            s2[idex++] = str1[i - len2];
        }
    }
    s2[idex] = '\0';
    if (strcmp(s1, s2) != 0) {
        return "";
    } else {
        gcdvalue = Gcd (len1, len2);
        for (int i = 0; i < gcdvalue; i++) {
            s[i] = str1[i];
        }
        s[gcdvalue] = '\0';
    }
    return s;
}
```
![image.png](https://pic.leetcode-cn.com/d89e41a4677e75951fe4b6845c289600a8342e4a1dc57bb52102eeb4af8420ba-image.png)
