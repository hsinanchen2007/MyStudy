### 解题思路
此处撰写解题思路

### 代码

```c
#define MAXLEN 27

bool check(int map1[], int map2[])
{
    for (int i = 0; i < MAXLEN; i++) {   
        if (map1[i] != map2[i]) {
            return false;
        }
    }

    return true;
}

bool checkInclusion(char * s1, char * s2)
{
    int l = 0;
    int r = 0;
    int map1[MAXLEN] = {0};
    int map2[MAXLEN] = {0};

    if (strlen(s1) > strlen(s2)) {
        return false;
    }

    while (r < strlen(s1)) {
        map1[s1[r] - 'a']++;
        map2[s2[r++] - 'a']++;
    }
    r--;

    while (r < strlen(s2)) {
        if (check(map1, map2)) {
            return true;
        }

        if (r + 1 == strlen(s2)) {
            break;
        }
        map2[s2[l++] - 'a']--;
        map2[s2[++r] - 'a']++;
    }

    return false;
}


```