### 解题思路

![image.png](https://pic.leetcode-cn.com/b0448460ff506d1bebd6bf3f7235ea6d7963e9e1ed40482eb4052423cc97e7f2-image.png)

### 代码

```c


char * reverseOnlyLetters(char * S){
    int len = strlen(S);
    if (len > 100) {
        return " ";
    }
    for (int i = 0; i < len; i++) {
        if (S[i] - '!' < 0 || S[i] - 'z' > 122 ) {
            return " ";
        }
    }
    int j = len - 1;
    for (int i = 0; i < len && i < j; i++) {  //因为是整个数组中所有的字母要交换,且不一定是对称交换，所以应该是i < len ，并且保持i < j 可以遍历整个数组以及交换两个对应的字母
       if (!isalnum(S[i]) || (S[i] - '0' >= 0 && S[i] - '0' <= 9)) {
           continue;
       }
       if (!isalnum(S[j]) || (S[j] - '0' >= 0 && S[j] - '0' <= 9)) {
           j--;
           i = i- 1;  //这里要注意保持i不动
           continue;
       }
       char temp = S[i];
       S[i] = S[j];
       S[j] = temp;
       j--;   //这里也要注意，更新j 的值。
    }
    return S;
}
```