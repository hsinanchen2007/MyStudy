### 解题思路
引用一个矩阵map映射A中的字母

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** A, int ASize, int* returnSize){
	char **map = (char**)malloc(sizeof(char*) * ASize);
	char **res = (char**)malloc(sizeof(char*) * 101);
	for (int i = 0; i < ASize; i++){
		map[i] = (char*)calloc(27, sizeof(char));
		for (int j = 0; j < strlen(A[i]); j++)
			map[i][A[i][j] - 'a']++;
	}
	int size = 0;
	for (int j = 0; j < 26; j++){
		int cnt = 101;
		for (int i = 0; i < ASize; i++){
			cnt = cnt < map[i][j] ? cnt : map[i][j]; 
			if (!map[i][j])
				break;			
		}
		while (cnt--){
			res[size] = (char*)calloc(2, sizeof(char));
			res[size++][0] = j + 97;
		}
	}
    for (int i = 0; i < ASize; i++)
        free(map[i]);
    free(map);
	*returnSize = size;
	return res;
}
```