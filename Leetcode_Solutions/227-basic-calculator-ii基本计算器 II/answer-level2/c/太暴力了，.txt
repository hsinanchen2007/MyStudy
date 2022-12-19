### 解题思路
此处撰写解题思路

### 代码

```c


bool ValidAdd(char *s)
{
    if (strstr(s, "+") == NULL && strstr(s, "-") == NULL) {
        return false;
    }
    return true;
}

void DfsAdd(char *s, int64_t *ret)
{
    if (!ValidAdd(s)) {
        return;
    }
    
    int64_t num2 = atoll(&s[1]); 
    //printf("0.%s, %d %d\n", s, *ret, num2);   
    if (s[0] == '+') {
        *ret = *ret + num2;
    } else {
        *ret = *ret - num2;
    }

    int len = strlen(s);
    int i;
    for (i = 1; i < len; i++) {
        if (!isdigit(s[i])) {
            break;
        }
    }
    int aft = i;
    DfsAdd(&s[aft], ret);
}

bool ValidMul(char *s)
{
    if (strstr(s, "*") == NULL && strstr(s, "/") == NULL) {
        return false;
    }
    return true;
}


void DfsMul(char *s)
{
    if (!ValidMul(s)) {
        return;
    }
    
    char *mul = strstr(s, "*");
    char *div = strstr(s, "/");
    char *tag = NULL;
    if (mul != NULL && div == NULL) {
        tag = mul;
    } else if (mul == NULL && div != NULL) { 
        tag = div;
    } else {
        tag = mul < div ? mul : div;
    }

    int key = tag - s;
    int i;
    for (i = key - 1; i >= 0; i--) {
        if (!isdigit(s[i])) {
            break;
        }
    }
    //printf("%d %d\n", i, key);
    int bef = i + 1;
    char buf[100] = {};
    //printf("%s, %c, %d %d\n", &s[bef], s[bef], key, bef);
    strncpy(buf, &s[bef], key - bef);
     int64_t num1 = atoll(buf);

    int len = strlen(s);
    for (i = key + 1; i < len; i++) {
        if (!isdigit(s[i])) {
            break;
        }
    }
    int aft = i;
    memset(buf, 0, sizeof(buf));
    strncpy(buf, &s[key + 1], aft - key - 1);
    int64_t num2 = atoll(buf);

    int64_t ret;
    if (*tag == '*') {
        ret = num1 * num2;
    } else {
        ret = num2 != 0 ? num1 / num2 : 0;
    }
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "%ld", ret);

    char buf1[300000] = {};
    strncpy(buf1, s, bef);
    char buf2[300000] = {};
    strcpy(buf2, &s[aft]);

    sprintf(s, "%s%s%s", buf1, buf, buf2);
    DfsMul(s);
}


int calculate(char * s)
{
    //const int len1 = 100000000;
    char buf[3000000] ={};
    //memset(buf, 0, len1);
    int len = strlen(s);
    printf("%d", len);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace(s[i])) {
            buf[j++] = s[i];
        }
    }
    DfsMul(buf);
    int64_t ret = atoll(buf);
    int i;
    for (i = 1; i < strlen(buf); i++) {
        if (!isdigit(buf[i])) {
            break;
        }
    }
    //printf("0.%s, %d %d\n", &buf[i], i, ret);  
    DfsAdd(&buf[i], &ret);
    return ret;

}
```