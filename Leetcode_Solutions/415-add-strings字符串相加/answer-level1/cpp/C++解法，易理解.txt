```
int main(int argc, char** argv) {
	string num1,num2,ret;
	cin >> num1 >> num2;
	int i=num1.size()-1;
	int j=num2.size()-1;  //起始时分别指向个位数 
	int ad=0,rest=0; //进位和余数 
	while(i>=0||j>=0){
		int f1=i>=0?num1[i]-'0':0; //越界时补零
		int f2=j>=0?num2[j]-'0':0;
		int sum=f1+f2+ad;
		ad = sum/10;
		rest = sum%10;
		ret = to_string(rest)+ret;
		i--; j--;
	} 
	/*重要步骤*/
	if(ad)  ret = to_string(ad)+ret;  //最有一个进位单独处理
	cout << ret;
	return 0;
}
```
