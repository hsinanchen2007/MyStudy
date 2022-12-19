通过滑窗求解
```
#define MAX_NUM(a, b)   ((a) > (b) ? (a) : (b))
int equalSubstring(char * s, char * t, int maxCost){
    int len1 = strlen(s);
    int len2 = strlen(t);
    if (s == NULL || t == NULL || len1 == 0 || len2 == 0) {
        return 0;
    }
    int count = 0;
    int cost = 0;
    int max = 0;
    int len = len1 > len2 ? len2 : len1;
    for (int i = 0; i < len; i++) {
        if (s[i] == t[i]) {
            count++;
            max = MAX_NUM(max, count);
        }else {
            while (true) {
                if (cost + abs(s[i] - t[i]) <= maxCost) {
                    cost += abs(s[i] - t[i]);
                    count++;
                    max = MAX_NUM(max, count);
                    break;
                }
                if (count > 0) {
                    cost -= abs(s[i - count] - t[i - count]);
                    count--;
                }else{
                    break;
                }
            }
        }
    }
    return max;
}
```
