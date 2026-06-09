执行用时：1 ms   消耗内存：33.7 MB

```
class Solution {
    public int hammingDistance(int x, int y) {
        int sum = 0;
	while(x > 0 || y > 0){
            if(x % 2 != y % 2){
                 sum ++;
            }
            x = x / 2;
            y = y / 2;
	}
	return sum;
    }
}
```
