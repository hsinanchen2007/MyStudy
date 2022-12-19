```
void reverseString(char* s, int sSize){
    solve(s, 0, sSize-1);
}

void solve(char *s, int left, int right) {
    if (left >= right) {
        return;
    }
    char tmp = s[left];
    s[left] = s[right];
    s[right] = tmp;
    solve(s, left+1, right-1);
}


```
