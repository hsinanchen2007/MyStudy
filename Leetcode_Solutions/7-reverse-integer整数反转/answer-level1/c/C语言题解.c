```
int reverse(int x){
	int max = 0x7fffffff, min = 0x80000000; 
	if (x == min || x == max) //如果没有这个判断，是无法得到x = -x的
		return 0;
	int ret = 0;
	int flag = 0;
	if (x < 0) {
		x = -x;
		flag = 1;
	}
	int tmp;
	int m = max / 10; 
	while (x > 0) {
		if (ret > m)
			return 0;
		else {
			tmp = x % 10;
			ret = ret * 10;
            //判断加上个位数后是否溢出
			if (max - ret < tmp && flag == 0) //正数的情况下
				return 0;
			else if (max - ret < tmp - 1 && flag == 1) //负数的范围比正数多一个
				return 0;
			else ret = ret + tmp;	
		}
		x /= 10;
	}
	if (flag == 1)
		return -ret;
	return ret;
}
```
在学习了原码，反码，补码的基础上写出的答案。

