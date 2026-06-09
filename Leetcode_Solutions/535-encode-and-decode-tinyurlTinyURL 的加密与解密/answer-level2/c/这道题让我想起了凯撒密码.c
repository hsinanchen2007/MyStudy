### 解题思路
此处撰写解题思路
1）其实这道题目挺好的，让我想起了大学在图书馆看的密码学一书
2）里面讲了最原始的密码就是凯撒密码，所谓凯撒密码，就是每个数加一个偏移，或者颠倒数字的位置
3）题解很多人用了hashmap，这和电视剧里面演的密码本又有何不同呢，莫尔斯密码不就是这个事儿吗，可以把每个字母设置成定长的数字
4）德国的恩尼格码机器，就是一种高明的加密机器
大家浪费了这道题目，哎。尤其是直接返回参数的，你这是明文传输啊。
### 代码

```c
int key = 0x5a;
/** Encodes a URL to a shortened URL. */
char* encode(char* longUrl) {
    char *res = longUrl;
    while (*longUrl) {
        *longUrl ^= key;
        longUrl++;
    }

    return res;
}

/** Decodes a shortened URL to its original URL. */
char* decode(char* shortUrl) {
    char *res = shortUrl;
    while (*shortUrl) {
        *shortUrl ^= key;
        shortUrl++;
    }

    return res;
}

// Your functions will be called as such:
// char* s = encode(s);
// decode(s);
```