![image.png](https://pic.leetcode-cn.com/5b4819502093f06f682c78eb68cbe57630dcac3280f890bf3f506964091abd79-image.png)

```
class Solution {
public:
    void reverse(string &s,int l,int r){//反转下标为l到r的区间
	int i,tmp;
	int mid=l+(r-l)/2;
	for(i=l;i<=mid;i++){
	    tmp=s[i];
	    s[i]=s[l+r-i];
	    s[l+r-i]=tmp;
	}
    }
    string reverseStr(string s, int k) {
        int i=0;
        int n=s.size();
        while(i<n){
        	if(i+2*k<=n){
        	    reverse(s,i,i+k-1);
        	    i=i+2*k;
		}
		else if(i+k<=n){
	    	    reverse(s,i,i+k-1);
		    return s;
		}
		else{
			reverse(s,i,n-1);
			return s;
		}
	}
	return s;
    }
};

```
