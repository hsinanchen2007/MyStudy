![image.png](https://pic.leetcode-cn.com/891596f291928c75e35b46af953b3b6e9cee85465866b146233098d32378695a-image.png)

```
#define MAXSIZE 26

bool checkInclusion(char * s1, char * s2){
    int s1Len = strlen(s1);
    int s2Len = strlen(s2);

    int i;
    int j;
    bool differ = false;
    if (s1Len > s2Len) {
        return false;
    }

    int *letter = (int *)malloc(MAXSIZE * sizeof(int));
    memset(letter, 0, MAXSIZE * sizeof(int));

    for (i = 0; i < s1Len; i++) {
        letter[s1[i] - 'a']++;
    }

    for (i = 0; i < s2Len; i++) {
        differ = false;
        letter[s2[i] - 'a']--;
        if (i > s1Len - 1) {
            letter[s2[i - s1Len] - 'a']++;
        }
        if (i >= s1Len - 1) {
          for (j = 0; j < MAXSIZE; j++) {
                if (letter[j] != 0) {
                    differ = true;
                }
                //printf("letter[%u]: %d", j, letter[j]);
            }
            if (differ == false) {
                return true;
            }
        }
    }

    return false;
}
```
