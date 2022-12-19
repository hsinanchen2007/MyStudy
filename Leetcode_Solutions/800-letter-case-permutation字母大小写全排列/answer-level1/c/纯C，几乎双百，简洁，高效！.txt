![1.png](https://pic.leetcode-cn.com/7f2ff71fec51a6f1444d879e90a708b3dcf4c9953131083250757429ef2ba3d2-1.png)

### 解题思路
找到思路其实很简单，遍历一次S，如果S[i]>'9',则一定是字母，将已经创建的空间依次复制，并将每个对应的字母改掉就结束了。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCasePermutation(char * S, int* returnSize){
	int len = strlen(S), size = 1;
	char **res = (char**)malloc(sizeof(char*)*pow(2, len));
	*res = (char*)calloc(len + 1, sizeof(char));
	strcpy(*res, S);
	for (int i = 0; i < len; i++){
		if (S[i]>'9'){
			int k = size;
			for (int j = 0; j < k; j++){
				res[k + j] = (char*)calloc(len + 1, sizeof(char));
				strcpy(res[k + j], res[j]);
				res[k + j][i] = S[i] < 'a' ? S[i] + 32 : S[i] - 32;
				size++;
			}
		}
	}
	*returnSize = size;
	return res;
}
```