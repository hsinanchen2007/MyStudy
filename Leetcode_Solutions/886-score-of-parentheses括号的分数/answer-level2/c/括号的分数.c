![截图.PNG](https://pic.leetcode-cn.com/8e887f9e10635d47aefd01b1845bf7a50cb8a93eac1dd71052607dd68957e0fe-%E6%88%AA%E5%9B%BE.PNG)

```
int CalScore(char *S, int len)
{
    int i;
    int j = 1;
    if (len == 2) {
        return 1;
    }
    for (i = 1; i < len; i++) {
        if (S[i] == '(') {
            j++;
        } else {
            j--;
        }
        if (j == 0) {
            break;
        }
    }
    if (i == len - 1) {
        return CalScore(S + 1, len - 2) * 2;
    } else {
        return CalScore(S, i + 1) + CalScore(S + i + 1, len - i - 1);
    }
}

int scoreOfParentheses(char * S){
    int len = strlen(S);
    return CalScore(S, len);
}
```
