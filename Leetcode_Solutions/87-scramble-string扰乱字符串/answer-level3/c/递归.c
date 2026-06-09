### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/be72cb10d3d40e673bed74f4584bee6b2cd90fc4b9927b9c4897bd87e5ef2d29-%E6%8D%95%E8%8E%B7.PNG)
 我也不知道为啥就100%了，分享一下。
用suma,sumb记录分割字符串所有字母的值的和，简单去除部分不必要计算。

### 代码

```c
char *sa, *sb;
bool dfs(int al, int bl,int len,int suma,int sumb)
{
    if(suma!=sumb) return false;
	if (len == 1) return sa[al] == sb[bl];
    int a1=0,b1=0,b2=0;
	for (int k = 1;k < len;k++)
	{
        a1+=sa[al+k-1];
        b1+=sb[bl+k-1],b2+=sb[bl+len-k];
		if (dfs(al, bl, k,a1,b1) && dfs(al + k, bl + k, len - k,suma-a1,sumb-b1)) return true;
		if (dfs(al + k, bl, len - k,suma-a1,sumb-b2) && dfs(al, bl + len - k, k,a1,b2)) return true;
	}
	return false;
}
bool isScramble(char * s1, char * s2) {
	int len = strlen(s1);
	if (!len) return false;
	if (len != strlen(s2)) return false;
	if (len == 1) return s1[0] == s2[0];
	sa = s1, sb = s2;
    int suma=0,sumb=0;
    for(int i=0;i<len;i++)
        suma+=s1[i],sumb+=s2[i];
	return dfs(0, 0, len,suma,sumb);
}
```