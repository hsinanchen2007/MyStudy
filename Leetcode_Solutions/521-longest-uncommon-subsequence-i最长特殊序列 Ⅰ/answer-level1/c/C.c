### 解题思路
这题目真的很弱智

### 代码

```c
int findLUSlength(char * a, char * b){
    int len1 = strlen(a);
    int len2 = strlen(b);

    if(len1 == len2) {
        for(int i = 0; i < len1; i++) {
            if(a[i] != b[i]) {
                return len1;
            }
        }
        return -1;
    }
    return fmax(len1, len2);
}
```