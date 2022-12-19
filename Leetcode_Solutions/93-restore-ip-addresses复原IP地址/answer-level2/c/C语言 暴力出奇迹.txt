### 解题思路
C语言 暴力法，遍历每个'.'的位置，然后判定是否有效。
比如对于“11012010”，某次遍历到i = 0, j = 3, k = 6，则判断1.101.201.0为有效

### 代码

```c
// #define DEBUG

#ifdef DEBUG
#define dbg(fmt, ...) do {printf("[%s-%d]"fmt"\r\n", __FUNCTION__, __LINE__, ##__VA_ARGS__);} while (0)
#else
#define dbg(fmt, ...) do {} while (0)
#endif /* DEBUG */

#define false 0
#define true  1

bool isValidSegs(char*s, int len)
{
	if ((len == 0) || (len > 3)) {
		return false;
	}

	if (len == 1) {
		;
	} else if (len == 2) {
		if (s[0] == '0') {
			return false;
		}
	} else {
		if ((s[0] == '0') || (s[0] > '2')) {
			return false;
		}
		
		if ((s[0] == '2') && (s[1] > '5')) {
			return false;
		}
		
		if ((s[0] == '2') && (s[1] >= '5') && (s[2] > '5')) {
			return false;
		}
	}
	return true;
}


 /**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** restoreIpAddresses(char * s, int* returnSize)
{
	int i, j, k, len;
	int cnt = 0;
	char **ip, *pos;
	
	len = strlen(s);
	ip = (char **)malloc(1024*sizeof(char *));
	*returnSize = 0;

	for (i = 0; i < 3; i++) {
		for (j = i + 1; j <= i + 3; j++) {
			for (k = j + 1; (k <= j + 3) && (k < len - 1); k++) {
				if (len - k - 1 > 3) {
					dbg("invalid(too long):[%d, %d, %d]", i, j, k);
					continue;
				}
				
				if ((false == isValidSegs(&s[0], i + 1)) || 
					(false == isValidSegs(&s[i + 1], j - i)) || 
					(false == isValidSegs(&s[j + 1], k - j)) || 
					(false == isValidSegs(&s[k + 1], len - k - 1))) { 
					dbg("invalid(seg error):[%d, %d, %d]", i, j, k);
					continue;
				}
				ip[cnt] = pos = malloc(20);
				strncpy(pos, &s[0], i + 1);
				pos[i + 1] = '.';
				pos += i + 2;
				strncpy(pos, &s[i + 1], j - i);
				pos[j - i] = '.';
				pos += j - i + 1;
				strncpy(pos, &s[j + 1], k - j);
				pos[k - j] = '.';
				pos += k - j + 1;
				strncpy(pos, &s[k + 1], len - k - 1);
				pos += len - k - 1;
				*pos = 0;
				dbg("ip:%s", ip[cnt]);
				cnt++;
			}
		}
	}
	dbg("cnt:%d",cnt);
	*returnSize = cnt;
	return ip;
}
```