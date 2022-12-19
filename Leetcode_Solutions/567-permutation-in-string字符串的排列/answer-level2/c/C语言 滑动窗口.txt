```
bool isSame(int* map1, int * map2)
{
    for (int i = 0; i < 26; i++) {
        if (map1[i] != map2[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(char * s1, char * s2) {
    int map1[26] = {0};
    int map2[26] = {0};
    if (s1 == NULL || s2 == NULL) {
        return false;
    }
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 > len2) {
        return false;
    }
    for (int i = 0; i < len1; i++) {
        int index = s1[i] - 'a';
        int index2 = s2[i] - 'a';
        map1[index]++;
        map2[index2]++;
    }
    if (isSame(map1, map2)) {
        return true;
    }
    for (int i = 1; i <= len2 - len1; i++) {
        int delCharIndex = s2[i - 1] - 'a';
        int addCharIndex = s2[i + len1 - 1] - 'a';
        map2[delCharIndex]--;
        map2[addCharIndex]++;
        if (isSame(map1, map2)) {
            return true;
        }
    }
    return false;
}
```
