```
class Solution {
    public boolean isPerfectSquare(int num) {
        if(num==Integer.MAX_VALUE)
            return false;
        for(int i=1;i*i<=num;i++){
			if(i*i==num)
				return true;
		}
		return false;
    }
}
```