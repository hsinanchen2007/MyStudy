### 解题思路
超时仅仅比通过多一次strlen调用

### 超时

![image.png](https://pic.leetcode-cn.com/5fbc8463281c796c157123e6ec3a1419ec0c6e2d49ff80d156f28efe38a7c02f-image.png)


```
bool canConstruct(char * s, int k){
    if (strlen(s) < k) return false;

    int cnt[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        cnt[s[i] - 'a'] += 1;
    }

    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] & 1) odd += 1;
        if (odd > k) return false;
    }

    return true;
}
```


### 通过

```c
bool canConstruct(char * s, int k){
    int cnt[26] = {0};
    int length = strlen(s);
    if (length < k) return false;

    for (int i = 0; i < length; i++) {
        cnt[s[i] - 'a'] += 1;
    }

    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2) odd += 1;
        if (odd > k) return false;
    }

    return odd <= k;
}


```