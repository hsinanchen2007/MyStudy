### 解题思路
此处撰写解题思路

### 代码

```c
bool isAnagram(char * s, char * t){
    int ns[26] = {0};
    int nt[26] = {0};
    int i;

    while(*s){
        ns[*s - 97] ++;
        s ++;
    }
    while(*t){
        nt[*t - 97] ++;
        t ++;
    }

    while(i < 26){
        if(ns[i] != nt[i]){
            return false;
        }
        ++ i;
    }

    return true;
}
```