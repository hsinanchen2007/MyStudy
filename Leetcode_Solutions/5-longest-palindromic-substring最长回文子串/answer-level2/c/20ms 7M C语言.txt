```
//基于马拉车思路进行的中心扩展修正，加了一次奇偶回文的判断
char * longestPalindrome(char * s){
    int length;
    length = strlen(s);
    if (length == 0 ||length == 1){
        return s;
    }
    char *p = NULL;
    int offset = 1;
    int center,max = 0;
    //奇偶回文判断
    int sd;
    
    //遍历所有的点
    for (int i = 0;i < length;i++){
        //设置偏移步数j
        int j = 0;
        //当步长没有超过数组长度时
        while (i - j >= 0&& i + j < length){
            //如果两端相等则j++；
            if (s[i-j] != s[i + j]){
                    break;
            }
            j++;
        }
        if ((2 * j - 1) > max){
            max = 2 * j - 1;
            center = i;
            sd = 0;
        }
        j = 0;
        //如果是偶数回文，右侧提前偏移一步
        if (i + 1 < length && s[i] == s[i+1]){
            while (i - j >= 0&& i + j + offset < length){
                if (s[i-j] != s[i + j + offset]){
                    break;
                }
                j++;
            }
        
            if((2 * j) > max){
                max = 2 * j;
                center = i;
                sd = 1;
            }
        }
    }
    p= (char *)malloc(sizeof(char)*(max + 1));
    memcpy(p,&s[center - max / 2 + sd],max + 1);
    p[max] = '\0';
    return p;
}

```
