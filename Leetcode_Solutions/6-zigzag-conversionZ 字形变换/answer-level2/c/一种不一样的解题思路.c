### 解题思路
总思路：将一维数组s[len]按照Z字形转换的规则转换为二维数组a[numRows][len],然后将a数组中非空字符提取存入一维数组b[len]中，数据b即为我们要求的结果。
z字形转换规则：实际上就是如何将一维数组下标按z转换成二维数组a的两个下标。
设a的第一维下标为idx，第二维下标为idy，s的下标为idz。经观察发现z字形转换时，
一、当numRows > 1时，这三个下标存在以下规律：
1.字符在直线上时：
(1)idx = i; i的取值范围：0 < i < numRows
(2)idy = n * (numRows - 1); n的取值范围：n = 0,1,2,3...
(3)idz =  2 * n * (delta - 1) + i; idz的取值范围：idz < strlen(s);
2.字符在斜线上时：
(1)idx = numRows -1 -j; j的取值范围：1 <= i < numRows - 1
(2)idy = n * (numRows - 1) + j; n的取值范围：n = 0,1,2,3...
(3)idz = (2 * n + 1) * (delta - 1) + j; idz的取值范围：idz < strlen(s);
二、当numRows == 1时，直接将s打印出来即可；

执行效率和内存消耗并不占优，此处仅仅是提供一种不同于其他思路的方法，记录之。

### 代码

```c

char * convert(char * s, int numRows){
    int len = 0;
    int delta = numRows;
    int delta_i = 0;
    int n = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    char **a = NULL;
    char *b = NULL;
	int idx = 0;
	int idy = 0;
	int idz = 0;
    

    len = (int)strlen(s);


	a = (char **)malloc(sizeof(char *) * delta);
	memset(a, 0x00, delta * sizeof(char *));

	for(delta_i = 0; delta_i < delta; delta_i++)
	{
	    a[delta_i] = (char *)malloc(len * sizeof(char));
        memset(a[delta_i], 0x00, len * sizeof(char));
	}
    
    //直线

	if (delta > 1) {

        for (n = 0; n < len; n++)
        {
            for (i = 0; i < delta; i++)
            {
				idz = 2 * n * (delta - 1) + i;
				if(idz < len) {
    				idx = i;
	    			idy = n * (delta - 1);
		    		a[idx][idy] = s[idz];
				}
				else {
				    break;
				}
            }
        }


    //斜线
	    for (n = 0; n < len; n++)
		{
			for (j = 1; j < (delta - 1); j++)
			{
				idz = (2 * n + 1) * (delta - 1) + j;
				if (idz < len) {
				    idx = delta - 1 - j;
					idy = n * (delta -1) + j;
					a[idx][idy] = s[idz];
				}   
			}
		}


#if 0
	for(i = 0; i < delta; i++)
    {
        for(j = 0; j < len ; j++)
        {
	        if(a[i][j] == 0x0)
			{
				printf(" ");
			    //printf("%d",a[i][j]);
			}
			else {
			    printf("%c",a[i][j]);
			}
         }
		printf("\n");
    }
#endif

    b = (char *)malloc((len + 1) * sizeof(char));
    memset(b, 0x00, (len + 1) * sizeof(char));

	/*
	for(k =0; k < len + 1; k++)
	{
		printf("%0x",b[k]);
	}
    */

	k = 0;

    while(k < len)
    {
        for(i = 0; i < delta; i++)
        {
            for(j = 0; j < len; j++)
            {
                if(a[i][j] != 0x0) {
                    b[k] = a[i][j];
					k++;
                }
            }
        }
    }

#if 0
	for(delta_i = 0; delta_i < delta; delta_i++)
	{
	    free(a[delta_i]);
		a[delta_i] = NULL;
	}
    free(a);
	a = NULL;
#endif

    /*
	printf("\n");
	for(k =0; k < len + 1; k++)
	{
		printf("%c",b[k]);
	}
	*/

	}
	else if ( delta == 1) {
	    return s;
	}

    return b;

}
```