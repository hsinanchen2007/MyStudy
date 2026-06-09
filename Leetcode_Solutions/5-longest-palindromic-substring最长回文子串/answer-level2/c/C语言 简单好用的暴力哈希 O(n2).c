```
#define N  1001
#define mod 16777259
unsigned int val[N][N];//val(i,j)即字符串str(i,j)的哈希值
char * longestPalindrome(char * s) {
    if(*s==0) return s;
	int len = 0, tl = 1;
	while (s[len]) len++;
	char *rt = s;
	for (int i = 0;i < len;i++) {//对每一个子串str(i,j)求取哈希值val(i,j)
		val[i][i] = s[i];
		for (int j = i + 1;j < len;j++)//选用128进制
			val[i][j] = (val[i][j - 1] << 7 | s[j]) % mod;//哈希函数 H(key) = key % 适当的质数
		for (int j = i - 1;j >= 0;j--) {
			val[i][j] = (val[i][j + 1] << 7 | s[j]) % mod;
			if (i - j >= tl && val[i][j]==val[j][i]) {//如果str(i,j)==str(j,i)即找到一个回文
				tl = i - j + 1;//更新回文串长度
				rt = s + j;//更新回文串首址
			}
		}
	}
    *(rt+tl)=0;
	return rt;
}
```

///由于是暴力算法，复杂度的确太高了
![暴力哈希.png](https://pic.leetcode-cn.com/9c2e24636917547460848de4c18efec415da96871d85b22da56440e3dcab44c9-%E6%9A%B4%E5%8A%9B%E5%93%88%E5%B8%8C.png)
