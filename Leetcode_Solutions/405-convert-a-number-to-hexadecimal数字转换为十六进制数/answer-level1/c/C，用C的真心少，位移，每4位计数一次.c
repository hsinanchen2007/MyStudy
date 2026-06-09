flag用来标记开始记数时的位置，只要最左位是1，即开始记数。

```
	int flag = 0, b = 31;
	char *res = (char *)calloc(9, 1), *temp = res;
    if(!num)
    *res='0';
	char a[17] = "0123456789abcdef";
	for (int i = 0; i < 8; i++){
		int t = 0;
        long c=1;
		for (int j = 0; j < 4; j++){
			if ((c << b--)&num){
				flag = 1;
				t += pow(2, 3 - j);
			}
		}
		if (flag){
			*temp++ = a[t];
		}
	}
	return res;
```
