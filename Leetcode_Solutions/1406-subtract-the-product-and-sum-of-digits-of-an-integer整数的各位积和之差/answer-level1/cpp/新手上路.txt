```
int subtractProductAndSum(int n) {
    int ji = 1;
	 int he = 0;
	 //vector<>
	 while (n)
	 {
		 ji *= n % 10;
		 he += n % 10;
		 n /= 10;
	 }
	 return ji-he;    
    }
```
