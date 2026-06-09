### 解题思路
1、两个字符串字母重复的位置要一样，否则无法转化；
2、字符串中不能26个字母都有，否则也无法转化。
![image.png](https://pic.leetcode-cn.com/8be16e58c1b8366ec70300195eb63dd48ef16b7f3f66a89728eba3799f223a72-image.png)


### 代码

```c
#define         WORD_MUN        26

bool canConvert(char * str1, char * str2)
{
    int         index;
    int         strMap[WORD_MUN];
    int         len;
    int         count   = 0;

    if ((str1 == NULL) || (str2 == NULL)) {
        return false;
    }

    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    len     = (int)strlen(str1);

    if (len <= 0) {
        return false;
    }

    if (memcmp(str1, str2, len) == 0) {
        return true;
    }

    /* str2 */
    memset(strMap, 0, sizeof(strMap));
    for (int i = 0; i < len; i++) {
        index   = str2[i] - 'a';
        if (strMap[index] == 0) {
            count++;
        }
        strMap[index]++;
    }
    if (count == WORD_MUN) {
        return false;
    }

    /* str1 */
    memset(strMap, -1, sizeof(strMap));
    for (int i = 0; i < len; i++) {
        index       = str1[i] - 'a';
        if ((strMap[index] != -1) && (str2[i] != str2[strMap[index]])) {
            return false;
        }

        strMap[index]   = i;
    }

    return true;
}
```