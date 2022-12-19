### 解题思路
此处撰写解题思路
数组从后向前求解，进行分式的通分，tmp=分母;分母=分子；分子=cont[i-1]*分子+tmp；
### 代码

```java
class Solution {
   public  int[] fraction(int[] cont) {
	int[] result= new int[2];
	int tmp=0;
	result[0]=cont[cont.length-1];
	result[1] = 1;
	for (int i = cont.length-1; i >0 ; i--) {
	tmp=result[1];
	result[1]=result[0];
	result[0]=cont[i-1]*result[0]+tmp;
	}
	tmp=gcd(result[0], result[1]);
	result[1]/=tmp;
	result[0]/=tmp;
    return result;  
    
}
//求最大公约数
public  int  gcd(int a,int b) {
	while (a%b!=0) {
		int tmp=a%b;
		a=b;
		b=tmp;		
	}
	return b;	
}
}
```