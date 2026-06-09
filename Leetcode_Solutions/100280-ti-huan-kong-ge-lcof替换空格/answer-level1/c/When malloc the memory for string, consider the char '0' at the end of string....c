### 解题思路
/* KEY POINT : (char *)malloc(3 * length * sizeof(char) + 1); */

### 代码

```c
int lengthofString(char* s){
    int len=0;
    char *t=s;
    while(*t++ != '\0')
        len++;
    return len;
}

/* KEY POINT : (char *)malloc(3 * length * sizeof(char) + 1); */
char* replaceSpace(char* s){
    int length = lengthofString(s);     // Get the length of strings
    char *p = (char *)malloc(3 * length * sizeof(char) + 1);        // Malloc memory for returned strings, the possible size is from length to 3*length+1
    char *t = p;                        // Save the pointer of strings
    char c;
    while((c=*s++) != '\0'){            // Save the current char in c
        if(c == ' '){                   // If the current char is space
            *p++ = '%';
            *p++ = '2';
            *p++ = '0';
        }else{                          // If the current char is NOT space
            *p++ = c;
        }
    }
    *p = c;                             // End the strings as char '\0';
    return t;                           // Return the pointer of strings
}
```