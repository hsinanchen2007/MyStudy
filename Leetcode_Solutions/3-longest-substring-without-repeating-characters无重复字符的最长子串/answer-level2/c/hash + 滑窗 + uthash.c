### 解题思路


### 代码

```c
typedef struct {  
    int ch;                    /* key */  
    char value;  
    UT_hash_handle hh;           
} HASH_NODE;

HASH_NODE *str = NULL;

HASH_NODE *FindCh(int ch) {
    HASH_NODE *s;  
    HASH_FIND_INT(str, &ch, s);  
    return s;  
}

void AddCh(int ch) {  
    HASH_NODE *s;  
    HASH_FIND_INT(str, &ch, s); 
    if (s == NULL) {  
      s = (HASH_NODE*)malloc(sizeof(HASH_NODE));  
      s->ch = ch;
      HASH_ADD_INT(str, ch, s);
    }  
    s->value = 1; 
}
void DelCh(int ch) {  
    HASH_NODE *s = NULL;  
    HASH_FIND_INT(str, &ch, s);  
    if (s != NULL) {  
      HASH_DEL(str, s);
      s->value = 0;
      free(s);
    }
}

void ClearList() {  
  HASH_NODE *node, *tmp;
  HASH_ITER(hh, str, node, tmp) {  
    HASH_DEL(str,node);    
    free(node);              
  }
}

int lengthOfLongestSubstring(char * s){
    if (s == NULL) {
        return 0;
    }
    if (s[0] == '\0') {
        return 0;
    }
    int start = 0;
    int end = 0;
    int max = 0;
    while (s[end] != '\0') {
        if (FindCh((int)(s[end])) == NULL) {
            AddCh((int)(s[end]));
            end++;
            max = (end - start) > max ? end - start : max;
        } else {
            DelCh((int)(s[start]));
            start++;
        }
    }
    ClearList();
    return max;
}
```