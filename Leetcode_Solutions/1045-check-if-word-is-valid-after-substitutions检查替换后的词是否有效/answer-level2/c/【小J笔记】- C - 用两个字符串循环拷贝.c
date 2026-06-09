- 使用两个字符串,str0和str1，每次从str0中删除abc字符串
- 无法删除的字符按顺序保存到str1中
- 一轮处理完之后，如果str1相比str0发生变化，那么将str1拷贝到str0，否则返回无效
- 如果最后str0为空串，那么有效，否则无效
```
#define MAX_SIZE (20010)
char g_str0[MAX_SIZE];
char g_str1[MAX_SIZE];

bool isValid(char * S)
{
    int i;
    int j;
    int len = strlen(S);
    for (i = 0; i < len; i++) {
        g_str0[i] = S[i];
    }
    while (true) {
        len = strlen(g_str0);        
        if (len == 0) {
            return true;
        } 
        j = 0;
        for (i = 0; i < len; i++) {
            if (strncmp(g_str0 + i, "abc", 3) == 0) {
                i += 2;
            } else {
                g_str1[j] = g_str0[i];
                j++;              
            }
        }
        g_str1[j] = '\0';        
        if ((strncmp(g_str0, g_str1, strlen(g_str0)) == 0) && (g_str0[0] != '\0')) {
            return false;
        } 
        strncpy(g_str0, g_str1, strlen(g_str1) + 1);
    }
    return false;
}
```
