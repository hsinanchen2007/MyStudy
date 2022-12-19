s1的排列之一是s2的子串可以理解为，s1中所有字母出现的类型以及个数，和s2中长度为len(s1)的子串中所有字母出现的类型以及个数相同
因此尝试用hash来做
```
void getTemphash(int start, int end, char* s, int* temp)
{
    int i;
    for (i = start; i < end; i++) {
        temp[s[i] - 'a']++;
    }
}
bool checkInclusion(char * s1, char * s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 > len2) {
        return false;
    }

    int temp1[26] = {0};
    int i;

    getTemphash(0, len1, s1, temp1); //建立s1的hash

    for (i = 0; i <= (len2 - len1); i++) {
        int temp2[26] = {0};
        int j;
        getTemphash(i, i + len1, s2, temp2); //遍历建立s2中长度为len(s1)的子串hash
        for (j = 0; j < 26; j++) {
            if (temp1[j] - temp2[j] != 0) {
                break; // 只要有一个字母的个数不同就跳出，代表改子串不符合条件，继续向下遍历
            }
        }
        if (j == 26) {
            return true; //遍历完hash表，代表改子串符合条件，直接返回
        }
    }

    return false; //遍历完所有子串都不行

}
```
