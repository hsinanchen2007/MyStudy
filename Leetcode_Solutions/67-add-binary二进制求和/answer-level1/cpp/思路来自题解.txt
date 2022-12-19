```
    #include "iostream"
	#include "string"
	using namespace std;
	class Solution {
	public:
        	string addBinary(string a, string b) {
    	        int asize=a.size();
    	        int bsize=b.size();
	
    	        while(asize<bsize)
    	        {
    	            a='0'+a;
    	            asize++;
    	        }
    	        while(bsize<asize)
    	        {
    	            b='0'+b;
    	            bsize++;
    	        }
    	        int sum=0,temp=0;
    	        for(int i=asize-1; i>=0; i--)
    	        {
    	            sum=a[i] - '0' + b[i] - '0' + temp;
    	            a[i]=sum%2 + '0';
    	            temp=sum/2;
    	        }
    	        if(temp!=0)
    	        {
    	            a='1'+ a;
    	        }
	
    	        return a;
    	}
	};
```
