主要使用哈希表的形式。


```
int char_num[128] = {0};
bool canConstruct(char * ransomNote, char * magazine){
    for (int i = 0; i < 128;       ++i)                        char_num[i] = 0;    
    for (int i = 0; magazine[i];   ++i)                      ++char_num[magazine[i]];
    for (int i = 0; ransomNote[i]; ++i)                      --char_num[ransomNote[i]];    
    for (int i = 'a'; i < 123;     ++i) if (char_num[i] < 0)   return false;
    return 1;
}
```




