- 同样哈希处理，S1加，S2减
```
#define MAX_SIZE (128)
int g_visit[MAX_SIZE];

bool CheckPermutation(char* s1, char* s2)
{
    int i;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 != len2) {
        return false;
    }
    for (i = 0; i < MAX_SIZE; i++) {
        g_visit[i] = 0;
    }
    for (i = 0; i < len1; i++) {
        g_visit[s1[i]]++;
        g_visit[s2[i]]--;
    }
    for (i = 0; i < MAX_SIZE; i++) {
        if (g_visit[i] != 0) {
            return false;
        }        
    }
    return true;
}
```
