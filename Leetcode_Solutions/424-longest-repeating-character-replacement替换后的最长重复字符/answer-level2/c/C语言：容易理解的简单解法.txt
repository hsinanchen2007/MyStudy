### 解题思路
和1004题类似，不加判断重复的map会超时。

### 代码

```c
int max(int a, int b){
    return a > b ? a : b;
}
int characterReplacement(char * s, int k){
    int left = 0, right = 0, cnt = 0, res = 0;
    int len = strlen(s);
    int map[26] = {0};

    for (int i = 0; i < len - k; i++){
        //避免大写字母重复判断
        map[s[i] - 'A']++;
        if (map[s[i] - 'A'] > 1)
            continue;

        left = 0;
        right = 0;
        cnt = 0;
        while (right < len){
            if (s[right] != s[i])
                cnt++;
            while (cnt > k){
                if (s[left] != s[i])
                    cnt--;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
    }
    return res;
}
```