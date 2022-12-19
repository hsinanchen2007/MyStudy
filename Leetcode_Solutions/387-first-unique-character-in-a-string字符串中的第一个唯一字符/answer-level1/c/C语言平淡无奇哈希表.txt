### 解题思路
![image.png](https://pic.leetcode-cn.com/c1311253dc8ea05f686742673b6a5e7601e0176c0ca295e56bf4d5f508d060a3-image.png)


### 代码

```c
int firstUniqChar(char * s){
    int* hash = (int*)malloc(sizeof(int) * 26);
    memset(hash, 0, sizeof(int) * 26);
    int i;
    int len = strlen(s);
    for(i = 0; i < len; i++) {
        hash[s[i] - 'a']++;
    }
    for(i = 0; i < len; i++) {
        if(hash[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}
```