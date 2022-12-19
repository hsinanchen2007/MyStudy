C 语言实现
```C []
bool canConstruct(char * ransomNote, char * magazine){
    int table[26] = {0};
    while (*ransomNote) table[*ransomNote++ - 'a']++;
    while (*magazine) table[*magazine++ - 'a']--;
    for (int i = 0; i < 26; ++i) if (table[i] > 0) return false;
    return true;
}
```