![image.png](https://pic.leetcode-cn.com/f3b9efcce3a8f34178bf890ead5c2a82e03d73391a2235b74b74f54b27389f91-image.png)

```
#define MAX_ASIIC 256
int lengthOfLongestSubstringKDistinct(char * s, int k){
    int bk[MAX_ASIIC] = {0};
    int sum = 0;
    int max = 0;
    int l = 0;
    int r = 0;
    int len = strlen(s);
    if (len == 0) {
        return 0;
    }
    sum++;
    bk[s[l]]++;
    while (l < len) {
        while (r < len && sum <= k) {
            max = fmax(max, r - l + 1);
            r++;
            if (bk[s[r]] == 0) {
                sum++;
            }
            bk[s[r]]++;

        }
        bk[s[l]]--;
        if (bk[s[l]] == 0) {
            sum--;
        }
        l++;
    }
    return max;
}
```
