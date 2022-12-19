![20190916-102413(eSpace).png](https://pic.leetcode-cn.com/98f96523f5e981692c1636e0efcc94e8abff28f1613a88509aef3cd40691faf2-20190916-102413\(eSpace\).png)

1、使用双指针
2、通过字符串长度比较进行初步筛选

int strStr(char * haystack, char * needle){
    if (needle[0] == '\0') {
         return 0;
    } 
    if(strlen(haystack) < strlen(needle)) {
        return -1;
    }
    
    for (int i = 0; i <= strlen(haystack) - strlen(needle); i++) {
        if (haystack[i] == needle[0]) {
            int j;
            for (j = 1; needle[j] != '\0'; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (needle[j] == '\0') {
                return i;
            }
        }
    } 
    return -1;
}

