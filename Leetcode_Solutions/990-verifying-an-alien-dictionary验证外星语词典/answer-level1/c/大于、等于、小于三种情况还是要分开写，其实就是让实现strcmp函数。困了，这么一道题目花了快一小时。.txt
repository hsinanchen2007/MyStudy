### 解题思路
此处撰写解题思路

### 代码

```c
int charCmp(char a, char b , char *order)
{
    
    int i = 0;
    int ai,bi;
    
    while(order[i] != '\0') {
        if (order[i] == a) {
            ai = i;
            break;
        }
        i++;
    }

    i = 0;
    while(order[i] != '\0') {
        if (order[i] == b) {
            bi = i;
            break;
        }
        i++;
    }

    return ai - bi;
}

int myStrCmp(char *a, char *b, char *order)
{
    int i = 0;

    while(a[i] && b[i]) {
        //printf("a[i] = %c, b[i] == %c, charCmp = %d\n", a[i], b[i], charCmp(a[i], b[i], order));
        if (charCmp(a[i], b[i], order) < 0) {   //str a < strb
            return -1;
        }
        else if (charCmp(a[i], b[i], order) > 0) {   //str a > strb
            return 1;
        }
        else {
            i++;
            continue;   //char a == char b 
        }
        //i++;
    }
    
    if (!a[i] && !b[i]) {
        return 0;
    }
    if(b[i]) {
        return -1;
    }
    if(a[i]) {
        return 1;
    }

    return 0;
}

bool isAlienSorted(char ** words, int wordsSize, char * order){
    for (int i = 0; i + 1 < wordsSize; i++) {
        //printf("%s, %s\n", words[i], words[i + 1]);
        if (myStrCmp(words[i], words[i + 1], order) > 0) {
            return false;
        }
    }
    return true;
}
```