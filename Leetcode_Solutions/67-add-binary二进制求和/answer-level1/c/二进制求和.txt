```
# include <stdio.h>
# include<string.h>
# include<malloc.h>

/*
	给定两个二进制字符串，返回他们的和（用二进制表示）。
	输入为非空字符串且只包含数字 1 和 0。
*/ 
char * addBinary(char * a, char * b) {
	int lenA = strlen(a),lenB = strlen(b),lenC = lenA;
	int numA;
	int numB;
	char * c = a;
	//选择数组长度较长的作为第一个相加的数组  并赋值给 c
	//选择数组长度较短的作为第二个相加的数组  并赋值给 b 
	//接下来的 相加 取模 所得到的数将会在 c 中进行修改 
	//让 t 作为 进位数 
	//让 b c 两个数组从最后一位数字开始相加(其实 是 3 个数，两个数组从 后面对应的数字，还有个进位数)， 
	//  对 2 取模 是该下标的应填写的数值   对 2 整除 是 进位数， 
	if(lenA < lenB) {
		lenC = lenB;
		c = b;
		b = a;
		lenB = lenA;
	}
	
	char arr[lenC];
	for(int i = 0; i < lenC; i ++) {
		arr[i] = c[i];
	}

	int indexC = lenC - 1;
	int indexB = lenB - 1;
	int result;
	int t = 0;

	while(indexC >= 0 || indexB >= 0) {
		numA = indexC >= 0 ? c[indexC --] - '0' : '0' - '0';
		numB = indexB >= 0 ? b[indexB --] - '0' : '0' - '0';
		result = numA + numB + t;
		arr[indexC + 1] = (result % 2) + '0';
		t = result / 2;
	}
	//确定返回数组的长度 
	int count = t == 0 ? lenC : lenC + 1; 
	char * re = (char *)malloc(sizeof(char) * (count + 1));
	
	if(t != 0){
		re[0] = t + '0';
	}
	
	for(int i = lenC - 1,j = count - 1; i >=0 &&j >= 0; i --,j --){
		re[j] = arr[i];
	}
	
	//最后注意添加结束标记 
	re[count] = '\0';
	return re;
	
}

int main(void) {
	char * str1 = "1010";
	char * str2 = "1011";
	char * str = addBinary(str1,str2);
	
	int index = 0;
	
	while(str[index]  != '\0'){
		printf("%c",str[index ++]);
	}
	return 0;
}
```
