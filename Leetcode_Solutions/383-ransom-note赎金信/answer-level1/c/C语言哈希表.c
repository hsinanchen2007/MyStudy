### 解题思路
平平无奇哈希表
![image.png](https://pic.leetcode-cn.com/3c0e1bd13c9bb8742b87fe6d6c8659f3c75a73af395c663b0477b3744f79e19d-image.png)


### 代码

```c
bool canConstruct(char * ransomNote, char * magazine){
    int* hash1 = (int*)malloc(sizeof(int) * 127);
    int* hash2 = (int*)malloc(sizeof(int) * 127);
    memset(hash1, 0, sizeof(int) * 127);
    memset(hash2, 0, sizeof(int) * 127);

    int len1 = strlen(ransomNote);
    int len2 = strlen(magazine);
    int i;

    for(i = 0; i < len1; i++) {
        hash1[ransomNote[i] - '0']++;
    }
    for(i = 0; i < len2; i++) {
        hash2[magazine[i] - '0']++;
    }

    for(i = 0; i < 127; i++) {
        if(hash1[i] > hash2[i]) {
            return false;
        }
    }
    return true;
}
```