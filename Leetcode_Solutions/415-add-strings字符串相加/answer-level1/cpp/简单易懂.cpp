class Solution {
public:
```
string addStrings(string num1, string num2) {
//先将num2字符串各位代表的整数加到num1上，然后做进位处理
	int i;
	int carry=0;//表进位 
   	string tmp;
    	if(num1.size()<num2.size()){//令num1为长的数 
       		tmp=num1;
       		num1=num2;
    		num2=tmp;
	}
	int l1=num1.size();
	int l2=num2.size();
	for(i=1;i<=l2;i++)
		num1[l1-i]+=num2[l2-i]-'0';
	for(i=l1-1;i>=0;i--){
		num1[i]+=carry;
		carry=(num1[i]-'0')/10;
		num1[i]=(num1[i]-'0')%10+'0';
	}
	if(carry){
		char c='0';
		c+=carry;
		num1=c+num1;
	}
	return num1;
}
```    
};