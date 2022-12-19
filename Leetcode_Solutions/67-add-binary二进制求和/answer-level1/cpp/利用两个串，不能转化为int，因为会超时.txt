### 解题思路
利用两个串，不能转化为int，因为会超时

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		if(a.length()>=b.length()){
			a+="0";
			for(int i=0;i<b.length();++i){
				a[i]+=b[i]-'0';
			}
			for(int i=0;i<a.length();++i){
				a[i+1]+=(a[i]-'0')/2;
				a[i]=(a[i]-'0')%2+'0';
			}
			if(a[a.length()-1]=='0')a.erase(a.end()-1);
			reverse(a.begin(),a.end());
			return a;
		}else{
			b+="0";
			for(int i=0;i<a.length();++i){
				b[i]+=a[i]-'0';
			}
			for(int i=0;i<b.length();++i){
				b[i+1]+=(b[i]-'0')/2;
				b[i]=(b[i]-'0')%2+'0';
			}
			if(b[b.length()-1]=='0')b.erase(b.end()-1);
			reverse(b.begin(),b.end());
			return b;
		}
		return "";
    }
};
```