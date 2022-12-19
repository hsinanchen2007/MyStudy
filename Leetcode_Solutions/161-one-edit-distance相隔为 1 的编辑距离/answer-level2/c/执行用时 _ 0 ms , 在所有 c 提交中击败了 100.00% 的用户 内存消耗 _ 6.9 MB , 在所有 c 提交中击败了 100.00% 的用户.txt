```
void swap(char** a,char** b) {
    char* temp = NULL;
    temp = *a;
     *a  = *b;
     *b  = temp;
}

bool isOneEditDistance(char * s, char * t){
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    if(len_s > len_t) {
        swap(&s,&t);//将短字符串保存在s中
    }
    //更新字符串长度
    int len_ss = strlen(s);
    int len_tt = strlen(t);

    //如果字符串只差大于1，则编辑距离一定大于1，返回false
    if(len_ss + 1 < len_tt) {
        return false;
    }
    //如果字符串长度相等，则有且只有一个字符不同时，才返回true
    if(len_ss == len_tt) {
        int res = 0;
        for(int i = 0;i < len_ss;i++) {
            res += (s[i] != t[i]);
        }
        return res==1;
    }
    //如果字符串长度差1，则只需判断短字符串是长字符串的子序列即可,设s短字符串，t长字符串
    int k = 0;
    for(int i = 0;i < len_tt && k < len_ss;i++) {
        if(s[k] == t[i]) {
            k++;
        }
    }
    return k == len_ss;
}
```
