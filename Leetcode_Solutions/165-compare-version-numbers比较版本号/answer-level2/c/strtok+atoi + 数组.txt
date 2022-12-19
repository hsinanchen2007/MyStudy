### 解题思路
1.分割版本号存储到数组中
2.取两个版本中最大长度
3.for循环逐一比较版本数字

### 代码

```c
#define MAX_LEN 1000

int ver1[MAX_LEN];
int ver2[MAX_LEN];

void get_version_num(char *version, int *ver, int *num)
{
	char *tmp = NULL;
	int n = 0;
	
	tmp = strtok(version, ".");
	if (tmp == NULL) {
		ver[n++] = atoi(version);
		*num = n;
		return;
	}
		 
	while (tmp != NULL) {
		ver[n++] = atoi(tmp);	
		tmp = strtok(NULL, ".");
	}
	*num = n;
}

void init_data(void)
{
	int i;

	for (i = 0; i < MAX_LEN; i++) {
		ver1[i] = 0;
		ver2[i] = 0;
	}
}

int compareVersion(char * version1, char * version2)
{
	int v1_num = 0;
	int v2_num = 0;
	int max_num;
	int i;

	if (version1 == NULL || version2 == NULL)
		return -1;

	init_data();

	get_version_num(version1, ver1, &v1_num);
	get_version_num(version2, ver2, &v2_num);
	max_num = v1_num > v2_num ? v1_num : v2_num;

	for (i = 0; i < max_num; i++) {
		if (ver1[i] > ver2[i])
			return 1;
		else if (ver1[i] < ver2[i])
			return -1;
	}		
	
	return 0;
}
```