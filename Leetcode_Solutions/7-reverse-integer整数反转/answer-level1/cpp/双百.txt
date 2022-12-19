```
class Solution {
public:
    int reverse(int x) {
    	bool flag = false;
  		long n = x, ans=0, i;
        if(n<0){
    		flag = true;
    		n=-n;
    	}
  		while(n){
  			ans = ans*10 + n%10;
  			n/=10;
  		}
  		if(flag) ans=-ans;
  		long lo=-1*(1<<31),hi=(1<<31)-1;
  		if(ans>hi || ans<lo) ans=0;
  		return ans;
    }
};
```
