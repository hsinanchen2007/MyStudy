

```
int calculateTime(char * keyboard, char * word)
{
    int i = 0, j = 0, pre = 0, cur = 0, sum = 0;
    while(word[i] != '\0')
    {
        while(keyboard[j] != '\0')
        {
            if(word[i] == keyboard[j])
            {
                cur = j;
                sum += abs(cur - pre);
                pre = cur;
                break;
            }
            j += 1;
        }
        j = 0;
        i += 1;
    }
    return sum;
}
```
