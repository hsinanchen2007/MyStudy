执行用时 : 8 ms, 在Reverse Vowels of a String的C提交中击败了98.80% 的用户

内存消耗 : 7.8 MB, 在Reverse Vowels of a String的C提交中击败了25.00% 的用户

```c
bool isvowel(char ch)
{
    if(
        (ch == 'a') ||  (ch == 'o') ||  (ch == 'e') ||  (ch == 'i') ||  (ch == 'u') ||
        (ch == 'A') ||  (ch == 'O') ||  (ch == 'E') ||  (ch == 'I') ||  (ch == 'U')
    )
        return true;
    else 
        return false;
}

char * reverseVowels(char * S){
    char *save = S;
    char *start = S;
    char *end = S + strlen(S) - 1;
    char ch;
    while(start <= end)
    {
        if( isvowel(*start) && isvowel(*end) ) // 如果都是字符，交换他们
        {
            ch = *start;
            *start = *end;
            *end = ch;
            
            start++;
            end--;
        }
        else
        {
            if(!isvowel(*start))
                start++;
            if(!isvowel(*end))
                end--;
        }
    }
    return save;
}
```