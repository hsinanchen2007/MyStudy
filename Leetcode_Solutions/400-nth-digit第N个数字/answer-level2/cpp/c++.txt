```

class Solution {
public:
    int findNthDigit(int n) {
    	int level[10];
    	level[0] = 9;
    	level[1] = 90*2 + 9;
    	level[2] = 900*3 + 90*2 +9;
		level[3] = 9000*4 + 900*3 + 90*2 +9;
		level[4] = 90000*5 + 9000*4 + 900*3 + 90*2 +9;
		level[5] = 900000*6 + 90000*5 + 9000*4 + 900*3 + 90*2 +9;
		level[6] = 9000000*7 +900000*6+90000*5 + 9000*4 + 900*3 + 90*2 +9;
		level[7] = 90000000*8 + 9000000*7 +900000*6+90000*5 + 9000*4 + 900*3 + 90*2 +9;
		level[8] = INT_MAX;
		if(n<10) return n;
		int i = 0;
		while(n>level[i]){
			i++;
		}
		n = n - level[i-1];
		int num = pow(10,i);
		int count = (n-1)/(i+1);
		int mod = (n-1)%(i+1);
		num = num + count;
		
		string temp = to_string(num);
		return temp[mod] -'0';
    }
    
};
```
