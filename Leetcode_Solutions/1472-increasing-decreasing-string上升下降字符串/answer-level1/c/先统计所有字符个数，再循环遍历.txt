### 解题思路
1、建立一个26个字节的数组，用来存储```a-z```的个数
2、循环遍历，从小到大和从大到小。
3、为了减少循环的次数，定义for循环的最大值和最小值，在遍历时动态调整max和min

### 代码

```c
char * sortString(char * s){
	int len = strlen(s);    
	char *ret = (char*)malloc(sizeof(char) * (len+1));
	memset(ret, 0, len+1);
	char tong[26] = {0};
	int i = 0;
	for ( i = 0; i < len; i++) // 统计各个字符的个数
	{
		tong[s[i]-97]++;   // a的ascii为97
	}
	int j = 0;
    int f1 = 0, f2 = 0;
    int max = 25, min = 0;  // for循环的边界值
	while(j < len)
	{
		// 升序
		for ( i = min; i <= max; i++) 
		{
			if(tong[i] > 0)
			{
				ret[j++] = i + 97;
				tong[i]--;
                f1 = 1;
			}
            else
            {
                if(0 == f1)
                {
                    min++;
                }
            }
		}
		for ( i = max; i >= min; i--) 
		{
			if(tong[i] > 0)
			{
				ret[j++] = i+97;
				tong[i]--;
                f2 = 1;
			}
            else
            {
                if(0 == f2)
                {
                    max--;
                }
            }
		}
	}
	return ret;

}
```