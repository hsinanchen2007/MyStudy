### 解题思路
C 大翻转而后小翻转

### 代码

```c
void reverse(char* s, int start, int end)
{
    char tmp;
    while (start < end) {
        tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        start++;
        end--;
    }
}

void reverseWords(char* s, int sSize){
    reverse(s, 0, sSize-1);
    int start = 0;
    int end = 0;
    while (start < sSize) {
        while (end < sSize && s[end] != ' ') {
            end++;
        }
        reverse(s, start, end-1);
        start = end + 1;
        end = start;
    }
}
```