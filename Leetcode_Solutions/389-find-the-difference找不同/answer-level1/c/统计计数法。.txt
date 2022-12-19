### 解题思路
此处撰写解题思路

### 代码

```c
char findTheDifference(char * s, char * t){

int maps1[26] = {0};
int maps2[26] = {0};

while(*s !='\0')
{
    maps1[*s - 'a']++;
    s++;
}
while(*t !='\0'){
    maps2[*t - 'a']++;
    t++;
}

for(int i = 0; i < 26; i++) {
    if(maps1[i] != maps2[i])
    {
        return i+'a';
    }
}
return 'a';



}
```