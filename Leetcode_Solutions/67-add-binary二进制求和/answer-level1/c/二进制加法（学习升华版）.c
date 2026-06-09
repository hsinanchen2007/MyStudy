### 解题思路
1.自己提交了一版，功能是实现了，但是过于臃肿；
2.学习了他人的方法，感觉还是比较简洁，并进行了优化。
3.整体思路就是，对应位求和，然后求商作进位位，剩下的余数为结果位。
4.改方法非常巧妙利用了(i >=0)||(j >= 0)。

### 代码

```c
char * addBinary(char * a, char * b){

    int carry = 0;	//进位

	int length = (strlen(a)>strlen(b)? strlen(a)+2:strlen(b)+2);

	char* result = (char*)malloc(sizeof(char)*length);		//开辟空间
	result[length-1] = '\0';

	for(int i = strlen(a)-1,j = strlen(b)-1,k = length -2; (i >=0)||(j >= 0); i--,j--,k--)
	{
		int sum = carry;
		sum += (i >= 0? a[i]-'0':0);
		sum += (j >= 0? b[j]-'0':0);

		carry = sum /2;
		result[k] = '0'+ sum % 2;
	}
	
	if(carry == 0)  //最后无进位，直接返回
		return result+1;    
	result[0] = '1';    //有进位，补一个最高位
		return result;
}


```