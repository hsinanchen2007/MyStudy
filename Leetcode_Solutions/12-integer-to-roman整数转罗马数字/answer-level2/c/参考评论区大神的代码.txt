### 解题思路
此处撰写解题思路

### 代码

```c
struct hash
{
	int num;
	char roman[4];
};

struct hash hash_table[]={
	1000,"M",
	900,"CM",
	500,"D",
	400,"CD",
	100,"C",
	90,"XC",
	50,"L",
	40,"XL",
	10,"X",
	9,"IX",
	5,"V",
	4,"IV",
	1,"I",
};
char * intToRoman(int num){
#define SIZE 256
	char *p = malloc(SIZE);
	if(p == NULL)
		return NULL;

	int i;
	memset(p,0,SIZE);
	for(i=0;i<sizeof(hash_table)/sizeof(struct hash);i++)
	{
		while(num >= hash_table[i].num)
		{
			num = num - hash_table[i].num;
			strcat(p,hash_table[i].roman);
		}
	}
	return p;
}
```