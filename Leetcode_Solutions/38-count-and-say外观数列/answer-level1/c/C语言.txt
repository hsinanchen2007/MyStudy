### 解题思路
输入n时，在代码在遍历n-1次得到所谓的外观数组，每次遍历得到第i次的数组存储在str中。最后到达n-1时直接返回。
代码中key表示该次用来对比的数字，count表示该数字出现的次数，另外定义指针p指向str的地址，然后进行遍历当前的str字符串，知道达到字符串末尾。
字符串tmp主要用于存储第i次循环时的暂存字符串，第i次循环结束后将它赋值给str。

### 代码

```c
#define RES_LEN 5000


char * countAndSay(int n)
{	
	char *str = (char *)malloc(RES_LEN*sizeof(char));
	char *tmp = (char *)malloc(RES_LEN*sizeof(char));
	str[0]='1';
	str[1]='\0';
	
	
	int i, j, count;
	char key;
	char *p;
	
	for(i = 1; i < n; i++){
		j = 0;
		key = str[0];
		count = 0;
		p = str;
		while(*p != '\0'){
			
			if(*p == key){
				count++;
			}else{
				tmp[j++] = count + '0';
				tmp[j++] = key;
				count = 1;
				key = *p;
			}
			p++;
		}
		tmp[j++] = count + '0';
		tmp[j++] = key;
		tmp[j] = '\0';
		strcpy(str, tmp);
	}
	return str;
}
```