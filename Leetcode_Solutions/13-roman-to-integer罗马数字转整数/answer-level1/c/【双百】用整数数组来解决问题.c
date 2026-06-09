### 解题思路
![QQ图片20200401235113.png](https://pic.leetcode-cn.com/91fe8b2bb20198477c85e7795d4c66a1d789a8b81ed932d676b7ee3873927bb1-QQ%E5%9B%BE%E7%89%8720200401235113.png)
此处撰写解题思路
将传进函数的罗马字符串分解并逐个转换存入一个整数数组中，进行和的计算时，进行判断，如果下一个数字比这个数字大，那么这两个数字之和就为下一个数字减去这个数字。
### 代码

```c
int romanToInt(char * s){
    int i,len,sum=0;
    int a[20];
    len=strlen(s);	//测量罗马字符串长度
	for(i=0;i<len;i++){
		switch(s[i]){	//将罗马字符转换为整数
			case 'I':a[i]=1;break;
			case 'V':a[i]=5;break;
			case 'X':a[i]=10;break;
			case 'L':a[i]=50;break;
			case 'C':a[i]=100;break;
			case 'D':a[i]=500;break;
			case 'M':a[i]=1000;break;
			default: a[i]=0;
		}
        if(i>0){	//从第二个数字开始
			if(a[i]>a[i-1])	//如果大于前一个数字
                sum=sum-a[i-1]+a[i]-a[i-1];//那么和就等于去掉前一个数字加上这个数字减去前一个数字
            else sum+=a[i];
        }
        else sum+=a[i];	//先将第一个数字加入和中
	}
	return sum;
}
```