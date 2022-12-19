负数的存储范围要大一点，所以不管x正负先变成负的再说，用一个sign记录符号
还有一个就是用2^31 / 10作为上界，在res×10之前和MAX比较一下，防止越界
轻轻松松两个100%，不用搞别的花里胡哨的，就是简单的乘除取余，if else
```
int reverse(int x){
	//2^31=2147483648
	int MAX=-214748364;
	int res=0,sign=1;
	if(x>0){
		sign=0;
		x=-x;
	}
	while(x<0){
		if(res>MAX){
			res=res*10+x%10;
			x/=10;
		}
		else if(res<MAX)return 0;
		else if(x<8){
			res=res*10+x%10;
			x/=10;		
		}else return 0;
	}
    if(sign==1)	return res;
    else return -res;
}
```
