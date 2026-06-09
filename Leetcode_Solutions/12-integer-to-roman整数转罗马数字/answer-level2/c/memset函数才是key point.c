### 解题思路
此处撰写解题思路
单纯使用查表，不过这道题的关键不是在于查表，查表的思路其实很简单，我在编程时遇到的问题在于strcat这里
如果不进行memset函数（我是新手，还不知道，所以偷偷看了答案），发现我的答案就差了一个memset，结果完全不同，所以新手要了解一下memset

### 代码

```c


char * intToRoman(int num){
    int i=0,a[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
	char *final=NULL;
	final=(char*)malloc(16);
	memset(final, 0, 16);
	char *romaji[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	while(num>0)
	{
		if(num/a[i]>=1)
		{
			num=num-a[i];
			strcat(final,romaji[i]);
		}
		else{
			i++;
		}
	}
	return final;

}


```