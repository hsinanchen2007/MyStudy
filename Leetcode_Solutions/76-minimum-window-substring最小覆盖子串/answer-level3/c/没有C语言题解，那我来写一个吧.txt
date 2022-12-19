直接上代码

#define MAX 128     //字符的ASCII码小于128

char * minWindow(char * s, char * t){
    int i;
    int Hash_t[MAX] = {0};      
    int Hash_w[MAX] = {0};
    int match       = 0;
    int need_match  = 0;
    int slen        = 0;
    int tlen        = 0;
    int left        = 0;
    int right       = 0;
    int min         = 0;
    int start       = 0;
    bool find_flag  = false;
    char *ret       = NULL;

    if (NULL == s || NULL == t) {
        return "";
    }

    slen = strlen(s);
    tlen = strlen(t);
    if (0 == slen || 0 == tlen || slen < tlen) {    //要注意异常场景 slen < tlen
        return "";
    }

    min = slen;

    ret = malloc(sizeof(char) * (slen + 1));
    if (NULL == ret) {
        return "";
    }
    memset(ret, 0, sizeof(char) * (slen + 1));      //要申请 +1 ，防止缺少\0

    for (i = 0; i < tlen; i++) {
        Hash_t[t[i]]++;
    }

    for (i = 0; i < MAX; i++) {
        if (0 != Hash_t[i]) {
            need_match++;       //这里注意，need_match，是指不同字符元素的数量
        }
    }

    for (right = 0; right < slen; right++) {
        if (0 != Hash_t[s[right]]) {
            Hash_w[s[right]]++;
            if (Hash_w[s[right]] == Hash_t[s[right]]) {
                match++;        //与need_match匹配
            }
        }

        while (match == need_match) {
            if (0 != Hash_t[s[left]]) {
                Hash_w[s[left]]--;
                if (Hash_w[s[left]] < Hash_t[s[left]]) {
                    match--;
                }
            }
            left++;
        }

        if (left > 0 && min > (right - left + 1)) {
            min = right - left + 2;               //+2是减去left++的1和right-left的1
            start = left - 1;
            find_flag = true;
        }
    }

    if (!find_flag) {
        return "";
    }

    for (i = 0; i < min; i++) {
        ret[i] = s[i + start];
    }

    return ret;
}