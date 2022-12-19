### 解题思路
此处撰写解题思路

### 代码

```c
bool isAnagram(char * s, char * t){
    
    if (s == NULL || t == NULL) {
        return false;
    }
    
    int source[27] = { 0 };
    int target[27] = { 0 };
    
    int lenS = strlen(s);
    int lenT = strlen(t);
    
    if (lenS != lenT) {
        return false;
    }
    else 
    {
        if (lenS == 0) {
            return true;
        }
        
        for (int i = 0; i < lenS; i++) {
            source[s[i] - 'a']++;
        }
        
        for (int j = 0; j < lenT; j++) {
            target[t[j] - 'a']++;
        }
        
        for (int k = 0; k < 27; k++) {
            if (source[k] != target[k]) {
                return false;
            }
        }
    }
    
    return true;
}


```