### 解题思路
此处撰写解题思路

### 代码

```c
bool isPalindrome(int x){
    int a[20];
	if(x<0){
		return false;
	}
	int x2=x;int k=1;int i=0;int temp=0;
	while(x2/pow(10.0,k)){
		temp=x2%10;
		a[i++]=temp;
		x2=x2/10;
	}
	int j=0;
	while(j<i/2){
		if(a[j]!=a[i-j-1]){
			return false;
		}
		j++;
	}
	return true;
}
```