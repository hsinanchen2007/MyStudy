
试了一大堆办法发现太麻烦了，最后列了numRows=3，4，5，6的四种情况，总结了下标的规律。
由于是新手，定义变量名字不规范。。。
刚开始还犯了很低级的错误，最后没加上'\0'，报错搞了半天。。。

```c
char * convert(char * s, int numRows){
    int m=strlen(s);
	char *p=(char*)malloc((m+1)*sizeof(char));
	int k=0,i=0;
	int n=2*numRows-2;
	for(;i<numRows;i++)
	{
		int j=i;
		int pr=n-2*i;
		while(j<m)
		{
			p[k]=s[j];
			k++;
			if(i==0 || i==numRows-1)
			{
				if(numRows==1)
                {
                    j=j+1;
                } 
                else
                {
                    j=j+n;
                }
			}
			else
			{
				j=j+pr;
				pr=n-pr;	
			} 
		}
	}
	p[m]='\0';
	return p;
}
```