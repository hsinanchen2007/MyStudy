### 解题思路

### 代码
```cpp
class Solution {
public:
	int mysqrt(int x){//返回下界平方根
		long l=0;
		long r=x/2+1;
		long tmp;
		long mid=0;
		while(l<=r){
			mid=(r-l)/2+l;
			tmp=mid*mid;
			if(tmp==x)
				return mid;
			else if(tmp<x)
				l=mid+1;
			else
				r=mid-1;
		}
		return r;
	}
    bool isPerfectSquare(int num) {//判断num是否为完全平方数
        long long tmp;
        tmp=mysqrt(num);
        if(tmp*tmp==num)
        	return 1;
        else
        	return 0;
    }
    bool judgeSquareSum(int c) {//判断c是否为两个完全平方数之和
        for(long i=0;i<=c/2;i++){
        	if(i*i>c)
        		break;
			if(isPerfectSquare(c-i*i))
				return 1;
		} 
		return 0;
    }
};
```