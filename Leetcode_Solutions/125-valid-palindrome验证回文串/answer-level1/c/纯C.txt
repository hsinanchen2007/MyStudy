### 解题思路
纯C

### 代码

```c
bool isPalindrome(char * s){
    int length = strlen(s);
    int indexOfS = 0;
    int newIndex = 0;
    char* pcTemp = (char*)malloc(length * sizeof(char));
    int left = 0;
    int right = 0;

    for (indexOfS = 0; indexOfS <= length - 1; indexOfS++)
    {
        if (isdigit(*(s + indexOfS)) || isupper(*(s + indexOfS)))
        {
            pcTemp[newIndex++] = *(s + indexOfS);
        }
        else if (islower(*(s + indexOfS)))
        {
            pcTemp[newIndex++] = toupper(*(s + indexOfS));
        }
    } 

    right = newIndex - 1;

    while (left < right)
    {
        if (pcTemp[left] != pcTemp[right])
        {
            return false;
        }

        left++, right--;
    }   

    return true;
}
```