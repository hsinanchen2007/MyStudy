![88608659-A17E-4E2A-8780-D7E8B2EEFCB7.jpeg](https://pic.leetcode-cn.com/32c7ac97b351b7b59170bb66c404867f5aaa030a05fef62f2cb3b4a15075f279-88608659-A17E-4E2A-8780-D7E8B2EEFCB7.jpeg)

```
int equalSubstring(char * s, char * t, int maxCost)
{
    int lenS = strlen(s);
    int i;
    int j;
    int tmpCost = 0;
    int returnLen = 0;
    int tmpLen = 0;
    for (i = 0; i < lenS; i++) {
        tmpLen = 0;
        tmpCost = 0;
        for (j = i; j < lenS; j++) {
            if (s[j] != t[j]) {
                tmpCost = tmpCost + ((t[j] - s[j]) > 0 ? (t[j] - s[j]) : (s[j] - t[j]));
            }
            //printf("tmpCost: %d,maxCost： %d, tmpLen: %d\n", tmpCost, maxCost, tmpLen);
            if (tmpCost <= maxCost) {
                tmpLen++;
            }
        }
        if (returnLen < tmpLen) {
            returnLen = tmpLen;
        }
    }

    return returnLen;
}
```
![1F086E0A-4D6F-45E9-A1DB-2DBBF803EE62.jpeg](https://pic.leetcode-cn.com/bed0f01d674731100447fa9503c51dfb01d27a2b1ff917f5a4e9ebd5c1e9dbb3-1F086E0A-4D6F-45E9-A1DB-2DBBF803EE62.jpeg)

```
int equalSubstring(char * s, char * t, int maxCost)
{
    int lenS = strlen(s);
    int cost = 0;
    int start = 0;
    int end = 0;
    int returnVal = 0;

    while (end < lenS) {
        while ((cost <= maxCost) && (end < lenS)) {
            cost = cost + abs(t[end] - s[end]);
            end++;
            if (cost <= maxCost) {
                if ((end - start) > returnVal) {
                    returnVal = end - start;
                }
            }
            if (end == lenS) {
                goto __END__;
            }
        }
        cost = cost - abs(t[start] - s[start]);
        start++;
    }
__END__:
    return returnVal;
}
```

