### 解题思路
纵向遍历
1.以第一个字符串为为参考；
2.外层循环移动字符；
3.内层循环遍历后续字符串中对应位置字符，发现不一样（包含结束符\0），跳出内外层循环；
4.根据遍历成功的累计次数，找到公用字符个数以及字符串。
注意：字符串指针*p的内存空间申请。

另一种思路：在跳出循环时，修改第一个字符串当前字符为\0，返回值利用第一个字符串。

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    int cnt = 0;
	int m = 0;
	int i = 0;	//列索引
	int j = 0;	//行索引
	char *p = NULL;// = (char*)malloc(sizeof(char)*(strlen(*strs)+2));


    if(strsSize == 0)
    {
        return "";
    }
    else if(strsSize == 1)
    {
        return *strs;
    }

	for(i = 0; i < strlen(*strs); i++)	//外循环:以第一个字符串对标
	{
		for(j = 1; j < strsSize; j++)	//字符串内循环：遍历后续
		{
			/*if(*(*(strs+j)+i) == '\0')	//提前结束break
			{
				i = strlen(*strs); //强行退出外循环
				break;
			}	
			else */if(*(*(strs+j)+i) != *((*strs)+i))  //不一样break
			{
				i = strlen(*strs); //强行退出外循环
				break;
			}
			
			if(j >= (strsSize-1))
			{
				cnt ++;
			}
		}
	}

    p = (char*)malloc(sizeof(char)*(cnt+1));    //用的时候在申请空间

	for(m = 0; m < cnt; m++)
	{
		p[m] = strs[0][m];
	}
	p[m] = '\0';
	
	return p;
}
```