### 解题思路
硬碰出来的...
![image.png](https://pic.leetcode-cn.com/3b19fb8122cc9203bc799a752feff54b023dbd6b9d5c392c945c41e109c44c08-image.png)

### 代码

```c
bool buddyStrings(char * A, char * B){
	int ALen, BLen;
	int l, r, i;
	char ACh, BCh;
	int AHash[26] = { 0 };
	int BHash[26] = { 0 };
	int equalOven = 0;
	ALen = strlen(A);
	BLen = strlen(B);
	if (ALen < 2 || ALen != BLen) {
		return false;
	}
	for (i = 0; i < ALen; i++) {
		AHash[A[i] - 'a']++;
		BHash[B[i] - 'a']++;
	}
	for (i = 0; i < 26; i++) {
		AHash[i] = AHash[i] < BHash[i] ? AHash[i] : BHash[i]; 
		if (AHash[i] > 0 && AHash[i] % 2 == 0) {
			equalOven = 1;
			break;
		}
	}
	
	for (l = 0; l < ALen; l++) {
		if (A[l] != B[l]) {
			break;
		}
	}
	for (r = ALen - 1; r >= 0; r--) {
		if (A[r] != B[r]) {
			break;
		}
	}
	if (l >= r) {
		return equalOven == 1 ? true : false;
	}
	if (A[l] != B[r] || B[l] != A[r]) {
		return false;
	}
	if ((r - l) > 1 && memcmp(&A[l+1], &B[l+1], r - l - 1) != 0) {
		return false;
	}
	return true;
}
```