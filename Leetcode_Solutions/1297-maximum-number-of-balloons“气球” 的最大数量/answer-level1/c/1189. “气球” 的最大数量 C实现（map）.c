### 解题思路
此处撰写解题思路

### 代码

```c
#define CHARACTERNUM 26

inline void CalCharCnt(int* map, char* text)
{
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] == 'b' || text[i] == 'a' || text[i] == 'l' || text[i] == 'o' || text[i] == 'n') {
            map[text[i] - 'a']++;
        }
        i++;
    }
    return;
}

bool HasBalloon(int* map)
{
    int index = 'b' - 'a';
    if (map[index] > 0) {
        map[index]--;
    } else {
        return false;
    }
    index = 'a' - 'a';
    if (map[index] > 0) {
        map[index]--;
    } else {
        return false;
    }
    index = 'l' - 'a';
    if (map[index] > 1) {
        map[index] -= 2;
    } else {
        return false;
    }
    index = 'o' - 'a';
    if (map[index] > 1) {
        map[index] -= 2;
    } else {
        return false;
    }
    index = 'n' - 'a';
    if (map[index] > 0) {
        map[index]--;
    } else {
        return false;
    }
    return true;
}

int maxNumberOfBalloons(char * text){
    if (!text) {
        return 0;
    }
    int mallocSize = sizeof(int) * CHARACTERNUM;
    int* map = (int*)malloc(mallocSize);
    memset(map, 0, mallocSize);
    CalCharCnt(map, text);
    int cnt = 0;
    while (HasBalloon(map)) {
        cnt++;
    }
    free(map);
    return cnt;
}
```