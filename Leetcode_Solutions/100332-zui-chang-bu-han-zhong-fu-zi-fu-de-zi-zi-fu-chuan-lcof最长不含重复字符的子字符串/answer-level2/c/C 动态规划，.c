````
int lengthOfLongestSubstring(char * s){
    int prior = 0; //上次状态下最长子串的长度
    int left = 0;
    int dict[256] = {0}; //映射ASCII码
    int right = 1; //表示字符串中第right个字符
    int i;
    while(*s != '\0'){
        i = *s-0; //字符转换为整数
        //*以下两行用来表示字符之前是否出现过，出现过则把出现位置赋值给left*//
        if(dict[i] > left)    
            left = dict[i];

        dict[i] = right;
        //*读到（最新位）第right位时，与left位的差为最近的非重复子串*//
        prior = (prior>right-left)?(prior:(right-left)); 
        s++;
        right++;
    }
    return prior;
}

```
