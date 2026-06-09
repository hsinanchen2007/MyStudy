### 解题思路
和66题的解题思路类似，用carry变量记录进位值，注意字符串数组分配空间的问题，默认的结束符也占一位
此处仅做C写法代码参考

### 代码

```c
#define max(a, b) ((a) > (b) ? (a) : (b))

char * addBinary(char * a, char * b){
	int lena = strlen(a), lenb = strlen(b), carry = 0, tmp = 0;
	int len = max(lena, lenb), i = lena - 1, j = lenb - 1;
	int idx = len - 1;
	char *p = (char *)malloc(sizeof(char)* (len + 1));
	p[len] = '\0';
	while (i >= 0 || j >= 0){
		if (i >= 0 && j >= 0)
			tmp = (a[i] - '0') + (b[j] - '0') + carry;
		else if (i >= 0)
			tmp = (a[i] - '0') + carry;
		else
			tmp = (b[j] - '0') + carry;

		if (tmp == 2) {
			p[idx--] = '0';
			carry = 1;
		}
		else if (tmp == 3){
			p[idx--] = '1';
			carry = 1;
		}
		else{
			carry = 0;
			p[idx--] = tmp + '0';
		}
		i--;
		j--;
	}
	
	if (carry == 1){
		char *q = (char *)malloc(sizeof(char)* (len + 2));
		q[0] = '1';
		for (i = 0; i < len + 1; i++) q[i + 1] = p[i];
		return q;
	}
	else{
		return p;
	}
}
```