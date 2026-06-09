### 解题思路
1、最原始想法双重循环，里面内循环只要满足有a b c时候就将后面len-当前位置坐标作为内循环计算所有符合长度，但是会导致最后两个用例超时。
2、在1基础上参考其他同学的滑动窗口方法，将外层循环做简化
### 代码
1、最后2个用例用例超时
int numberOfSubstrings(char * s){
    int len;
    int i, j;
    int tmp[3] = {0};
    int cnt = 0;
    if (s == NULL) {
        return 0;
    }
    len = strlen(s);
    for (i = 0; i < len; i++) {
        memset(tmp, 0, sizeof(tmp));
        for (j = i; j < len; j++) {
            tmp[s[j]-'a']++;  
            if ((tmp[0] >= 1) && (tmp[1] >= 1) && (tmp[2] >= 1)) {
                cnt += len - j;
                break;
            }         
        }
    }
    return cnt;
}
2、全用例通过，外层循环去掉改成滑动窗口左边指针处理
int numberOfSubstrings(char * s){
    int len;
    int left, right;
    int tmp[3] = {0};
    int cnt = 0;
    if (s == NULL) {
        return 0;
    }
    len = strlen(s);
    left = 0;
    for (right = 0; right < len; right++) {
        tmp[s[right]-'a']++;  
        while ((tmp[0] >= 1) && (tmp[1] >= 1) && (tmp[2] >= 1)) {
            cnt += len - right;
            tmp[s[left]-'a']--;
            left++;
        }     
    }
    return cnt;
}
```