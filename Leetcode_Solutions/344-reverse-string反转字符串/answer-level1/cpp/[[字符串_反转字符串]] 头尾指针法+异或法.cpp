头尾双指针，是反转字符串时常用的方法。
```c
void reverseString(char* s, int sSize){
	char temp;
	int start=0;
	int end=sSize-1;
	while(start<end){
		temp=s[start];
		s[start++]=s[end];
		s[end--]=temp;
	}
}
```
异或法可以交换两个数字。
```c
void reverseString(char* s, int sSize){
    for (int a = 0, b = sSize-1; a < b; a++, b--){
        s[a] = s[a] ^ s[b];  //a=a^b
        s[b] = s[a] ^ s[b];  //b=a^b^b=a
        s[a] = s[a] ^ s[b];  //a=a^b^a^b^b=b
    }
}
```