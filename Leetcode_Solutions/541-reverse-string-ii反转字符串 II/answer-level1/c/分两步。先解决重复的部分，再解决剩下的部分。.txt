### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/3f0c583d27ea1f78b2935d5b5644910f6a63c209c3f9111222cd3700ed4250ae-image.png)

### 代码

```c

void swap (char* a, int len)
{
    for (int i = 0; i < len / 2; i++) {
        char temp = a[i];
        a[i] = a[len-1-i];
        a[len-1-i] = temp;
    }
}
char * reverseStr(char* s, int k)
{
    int len = strlen(s);
    if (len < 1 || len > 10000 || k < 1 || k > 10000) {
        return " ";
    }
    int n = len / (2*k);
    for (int i = 0; i < n; i++) {
        swap(&s[i*2*k], k);
    }
    if (len - n*2*k < k) {
        swap(&s[n*2*k], len - n*2*k);
    } else if (len - n*2*k >= k && len - n*2*k < 2*k) {
        swap(&s[n*2*k], k);
    }
    return s;
}
```