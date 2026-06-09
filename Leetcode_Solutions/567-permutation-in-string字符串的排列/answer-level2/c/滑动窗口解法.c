bool checkInclusion(char * s1, char * s2){
    if (s1 == NULL || s2 == NULL) {
        return false;
    }
    int map1[26] = { 0 };
    int map2[26] = { 0 };
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 > len2 || len2 == 0) {
        return false;
    }

    for (int i = 0; i < len1; i++) {
        map1[s1[i] - 'a']++;
        map2[s2[i] - 'a']++;
    }
    if (memcmp(map1, map2, sizeof(int) * 26) == 0) {
        return true;
    }

    for (int i = len1; i < len2; i++) {
        map2[s2[i - len1] - 'a']--;
        map2[s2[i] - 'a']++;
        if (memcmp(map1, map2, sizeof(int) * 26) == 0) {
            return true;
        }
    }

    return false;
}