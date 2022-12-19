```
class Solution {
public:
	string multiply(string &num1, string &num2) {
		int n=num1.length(), m=num2.length();
		if ((n==1 && num1[0]=='0') || (m==1 && num2[0]=='0')) return "0";
		string res(n+m,'0');
		for(int i=n, l=n+m-1, carry=0; i-- || carry; --l){
			for(int j=m, k=l; j || carry; ){
				if (j) carry += (num1[i]-'0')*(num2[--j]-'0') + res[k]-'0';
				res[k--]= carry%10+'0';
				carry /= 10;
			}
		}
		if (res[0]=='0') res.erase(0,1);
		return res;
	}
};
```
