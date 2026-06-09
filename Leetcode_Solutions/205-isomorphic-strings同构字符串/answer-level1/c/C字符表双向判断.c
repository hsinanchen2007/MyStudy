### 解题思路
此处撰写解题思路

### 代码

```c
bool isIsomorphic2(char * s, char * t);

bool isIsomorphic(char * s, char * t){
    bool one = isIsomorphic2(s, t);
    bool two = isIsomorphic2(t, s);
    return (one && two);
}

bool isIsomorphic2(char * s, char * t){
    int length = strlen(s);
    if(length != strlen(t))
        return false;

    char one[127] = {0};
    char two[127] = {0};
    int i = 0, index = 0;
    for(i = 0; i < length; i++){
        index = s[i];
        if(one[index] != 0){
            if(two[index] != t[i])
                return false;
        } else {
            one[index] = 1;
            two[index] = t[i];
        }
    }
    return true;
}
```