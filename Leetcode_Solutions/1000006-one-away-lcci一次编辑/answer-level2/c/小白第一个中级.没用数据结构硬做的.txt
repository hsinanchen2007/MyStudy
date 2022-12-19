### 解题思路
思路和别人的基本一样 分3个情况讨论

### 代码

```c
bool oneEditAway(char* first, char* second){
    int len1=strlen(first);
    int len2=strlen(second);
    int count=0;

    if(abs(len1-len2) > 1) return false;

    if(len1 == len2){
        for(int i=0; i<len1; i++){
            if(first[i] != second[i]) count++;
            if(count > 1) return false;
        }
    }
    else{
        for(int i=0, j=0; i<len1 && j<len2;){
            if(first[i] != second[j]){
                count++;
                if(len1 > len2) i++;
                else j++;
                if(count > 1) return false;
            }
            else{i++; j++;}
        }
    }

    return true;
}
```