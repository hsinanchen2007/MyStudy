### 解题思路
先倒序遍历字符串，遇到#号往前两位映射到字母，否则直接映射，得到一个新的字符串。然后将新字符串反转即可

### 代码

```c
char* freqAlphabets(char* s){
//倒序遍历
    int len = strlen(s);
    int i = len - 1;
    char *ans = (char*)calloc(len, sizeof(char));
    int j = 0;
    while(i >= 0){
        if(s[i] == '#'){
            ans[j] = (s[i - 2] - '0') * 10 + (s[i - 1] - '0') + 96;
            i -= 3;
        }
        else{
            ans[j] = s[i] - '0' + 96;
            i--;
        }
        j++;
    }
    //反转字符串
    len = strlen(ans);
    char *p1, *p2;
    p1 = ans;
    p2 = ans + len - 1;
    while(p1 < p2){
        char c = *p1;
        *p1 = *p2;
        *p2 = c;
        p1++;
        p2--;
    }
    return ans;
}
```