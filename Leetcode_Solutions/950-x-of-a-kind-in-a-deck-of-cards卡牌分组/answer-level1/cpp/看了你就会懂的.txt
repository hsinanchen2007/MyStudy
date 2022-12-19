### 解题思路
先手写快排一下(用sort会快点)，把所有不同的数的个数求出来求出这些数的最大公约数大于1返回true，否则返回false

### 代码

```c
int gcd(int a,int b){             //最大公约数
	return b==0?a:gcd(b,a%b);
}
void quick_sort(int *s,int l,int r){   //快排
	if(l>=r) return;
	int l1 =l,r1=r,k=s[l],t;
	while(l1<r1){
		while(s[r1]>=k&&l1<r1) r1--;
		while(s[l1]<=k&&l1<r1) l1++;
		if(l1<r1){
			t = s[l1];
			s[l1] = s[r1];
			s[r1] = t;
		}
	}
	if(l1!=l){
		s[l]=s[l1];
		s[l1]=k;
	}
	quick_sort(s,l,l1-1);
	quick_sort(s,l1+1,r); 
}
bool hasGroupsSizeX(int* deck, int deckSize){ 
	int flag;              //记录所有数的最大公约数
	quick_sort(deck,0,deckSize-1); 
	int i=1,len=1,tmp = deck[0];
	for(;i<deckSize;i++){  //因为flag初值没有办法设置只有求出第一个数的个数赋值给flag
		if(deck[i]!=tmp) break; 
		len++;
	} 
	flag=len;              //找出第一个数的个数赋值给flag
	if(i!=deckSize){       //接着找不同的数字的个数冰球和flag的gcd   ui后是所有的书的个数的gcd

		tmp=deck[i];
		len=1;
		for(i=i+1;i<deckSize;i++){
			if(deck[i]!=tmp)
			{
				flag = gcd(flag,len);
				len=1;
				tmp = deck[i];
			}
			else len++;
		}
        flag = gcd(flag,len);
	}
    if(flag>1) return true;
	return false;
}
```
![sample.png](https://pic.leetcode-cn.com/437ec50dea8337ed6d56a532a05f61ac0a3bc03b34692637c23c8eae1f72f92b-sample.png)