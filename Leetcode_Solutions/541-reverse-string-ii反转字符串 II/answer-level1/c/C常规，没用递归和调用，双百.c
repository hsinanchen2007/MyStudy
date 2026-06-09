![1.png](https://pic.leetcode-cn.com/2cf7e1ffc0c4b451774c3685b4103f7166000e69ba3bb967bfcec52c5c724f84-1.png)


### 解题思路
定义cnt记录反转的次数，每次反转后cnt+2，新的起点为k*cnt

### 代码

```c
char * reverseStr(char * s, int k){
	int len = strlen(s), cnt = 0;
	char *res = (char*)calloc(len + 2, 1);
	while (len){
		if (len >= k * 2){
			for (int i = 0; i < k; i++)
				res[i + k*cnt] = s[k - i - 1 + k*cnt];
			for (int i = k; i < k * 2; i++)
				res[i + k*cnt] = s[i + k*cnt];
			cnt += 2;
			len -= k * 2;
		}
		else if (len >= k&&len < k * 2){
			for (int i = 0; i < k; i++)
				res[i + k*cnt] = s[k - i - 1 + k*cnt];
			for (int i = k; i < len; i++)
				res[i + k*cnt] = s[i + k*cnt];
			len = 0;
		}
		else{
			for (int i = 0; i < len; i++)
				res[i + k*cnt] = s[len - i - 1 + k*cnt];
			len = 0;
		}
	}
	return res;
}
```