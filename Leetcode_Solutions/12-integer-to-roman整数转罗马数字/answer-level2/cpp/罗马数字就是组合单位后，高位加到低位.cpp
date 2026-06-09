经过组合后单位数字表示如下(每一个组个算一个单位)
I             1
IV            4
V             5
IX            9
X             10
XL            40
L             50
XC            90
C             100
CD            400
D             500
CM            900
M             1000

然后直接

```
class Solution {
public:
    string intToRoman(int n) {
        string ans="";
		while(n){
			if(n>=1000){
				ans+="M";
				n-=1000;
			}else if(n>=900){
				ans+="CM";
				n-=900;
			}else if(n>=500){
				ans+="D";
				n-=500;
			}else if(n>=400){
				ans+="CD";
				n-=400;
			}else if(n>=100){
				ans+="C";
				n-=100;
			}else if(n>=90){
				ans+="XC";
				n-=90;
			}else if(n>=50){
				ans+="L";
				n-=50;
			}else if(n>=40){
				ans+="XL";
				n-=40;
			}else if(n>=10){
				ans+="X";
				n-=10;
			}else if(n>=9){
				ans+="IX";
				n-=9;
			}else if(n>=5){
				ans+="V";
				n-=5;
			}else if(n>=4){
				ans+="IV";
				n-=4;
			}else{
				ans+="I";
				n--;
			}
		}
		return ans;
    }
};
```
