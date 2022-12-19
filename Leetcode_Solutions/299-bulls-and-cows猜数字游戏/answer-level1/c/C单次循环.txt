![image.png](https://pic.leetcode-cn.com/55066db183864f8b8840a25777a105c48df6fea60015088ff2b6e5259c972ac8-image.png)

1、数字位置正确的次数为A, 数字正确的次数为B
2、比较每位相同时A计数器加一，B其实只用看两个字符串中0-9每个数字重合的次数之和，也就是每一个数字在两个字符串出现的次数取小再求和
3、B中包含数字正确位置正确和数字正确位置不正确两部分，所以B-A就是奶牛次数
```
#define MIN(a, b) ((a) < (b) ? (a) : (b))

char* getHint(char* secret, char* guess)
{
    int A = 0; //数字正确、位置正确
    int B = 0; //数字正确
    int S[10] = { 0 };
    int G[10] = { 0 };
    char* ans = (char*)malloc(sizeof(char) * 100);
    while (*secret != '\0') {
        if (*secret == *guess) {
            A++;
        }
        S[*secret - '0']++; //统计secret中0-9出现的次数
        G[*guess - '0']++;  //统计guess中0-9出现的次数
        secret++;
        guess++;
    }
    for (int i = 0; i < 10; ++i) {
        B += MIN(S[i], G[i]);
    }
    B -= A;
    sprintf(ans, "%dA%dB", A, B);
    return ans;
}
```
