```c
bool checkInclusion(char * s1, char * s2){
    int len1 = strlen(s1), len2 = strlen(s2);
    int map[26] = {0};

    for (int i = 0; i < len1; i++){
        map[s1[i] - 'a']++;
    }
    int right = 0, left = 0;
    int cnt = 0;
    for (right = 0; right < len2; right++){
        if (map[s2[right] - 'a'] > 0){
            cnt++;
        }
        map[s2[right] - 'a']--;
        while (cnt == len1){
            if (right - left + 1 == len1)
                return true;
            map[s2[left] - 'a']++;
            if (map[s2[left] - 'a'] > 0){
                cnt--;
            }
            left++;
        }
    }
    return false;
}
```