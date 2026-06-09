```c
void reverse(char *s, int low, int high)
{
    for(int i = 0; i <= (high - low) / 2; i++){
        char t = s[low + i];
        s[low + i] = s[high - i];
        s[high - i] = t;
    }
}

char * reverseWords(char * s)
{
    int i = 0, j = 0, len = strlen(s);
    while(j < len){
        i = j;
        while(s[j+1] != ' ' && s[j+1] != '\0'){
            j++;
        }
        reverse(s, i, j);
        if(s[j+1] == '\0')
            break;
        j += 2;    //跳过空格
    }
    return s;
 }
```