
![image.png](https://pic.leetcode-cn.com/9cc4e5aecaf71effae64d0ac1cf357614a203d645debb1ba2ae1fde4de436770-image.png)

```

class Solution {
public:
    int kthGrammar(int N, int K) {
    	return fun(N,K-1);
    }
    int fun(int N, int K){
//    	cout<<N<<","<<K<<endl;
		if(N==1)return 0;
		int a=fun(N-1,K/2);
		int b=K%2;
		if(a==0){
			if(b==0)return 0;
			else return 1;
		}
		else{
			if(b==0)return 1;
			else return 0;
		}
		return 1;
    	
	}
};
```
