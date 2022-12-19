### 解题思路
![批注 2020-03-16 141658.png](https://pic.leetcode-cn.com/c733ae5d59cfbe3ccdd7ae577866a43002f28ee0af13f58307e4f948b8dfb452-%E6%89%B9%E6%B3%A8%202020-03-16%20141658.png)

### 代码

```c
char res[100010];
char tmp[50010];
char* compressString(char* S){
    int l = strlen(S);
    if(l <= 2)
        return S;
    int cnt = 1;
    int pos = 1;
    res[0] = S[0];
    for(int i = 1;i < l; ++i){
        if(S[i] != S[i - 1]){
            int j = 0;
            while(cnt){
                tmp[j++] = '0' + cnt % 10;
                cnt /= 10;
            }
            for(int k = j - 1;k >= 0; --k)
                res[pos++] = tmp[k];
            res[pos++] = S[i];
            cnt = 1;
        }
        else
            ++cnt;
    }
    int j = 0;
    while(cnt){
        tmp[j++] = '0' + cnt % 10;
        cnt /= 10;
    }
    for(int k = j - 1;k >= 0; --k)
        res[pos++] = tmp[k];
    res[pos] = '\0';
    if(pos < l)
        return res;
    else 
        return S;
}
```