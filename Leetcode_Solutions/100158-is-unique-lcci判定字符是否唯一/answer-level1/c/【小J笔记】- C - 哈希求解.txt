- 个人认为涉及到字符是否唯一的判断统统用哈希来处理，速度快好理解
```
#define MAX_SIZE (128)

int g_visit[MAX_SIZE];

bool isUnique(char* astr)
{
    int i;
    int len = strlen(astr);
    for (i = 0; i < MAX_SIZE; i++) {
        g_visit[i] = false;
    }
    for (i = 0; i < len; i++) {
        if (g_visit[astr[i]] == true) {
            return false;
        } else {
            g_visit[astr[i]] = true;
        }
    }
    return true;
}
```
