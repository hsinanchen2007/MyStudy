**方法一：暴力查询**
```
class Solution {
    /**
    * 思路：
    * (1) 创建长度为10000的记录数组，用来存储原数组中所有可能数值的个数。
    * (2) 从小到大遍历所有可能的 X 值，X 要同时被原数组长度和每个数的个数除尽。
    * (3) 当某个 X 值完成记录数组的遍历，则当前 X 值符合要求，否则不符合。
    */
    public boolean hasGroupsSizeX(int[] deck) {
        int N = deck.length;
		if (N < 2){
            return false;
        }
        int[] count = new int[10000];
        for (int c: deck){
			count[c]++;
		}

		// search标记外层循环，从小到大遍历可能的 X 值。
        target: for (int X = 2; X <= N; ++X){
            if (N % X == 0) {
                for (int v: count){
					if (v == 1){
						return false;
					}else if (v % X != 0){
						// 如果有不符合的情况，跳出继续外层循环。
						continue target;
					}
				}    
                return true;
            }
        }
        return false;
    }
}
```

**方法二：最大公约数**
```
class Solution {
    /**
    * 思路：
    * (1) 创建长度为10000的记录数组，用来存储原数组中所有可能数值的个数。
    * (2) 遍历记录数组，得出所有数个数的最大公约数。
    * (3) 如果最大公约数大于等于2，则符合要求。
    */
    public boolean hasGroupsSizeX(int[] deck) {
		if (deck.length < 2){
            return false;
        }
		// 建立长度10000的数组存储原数组中每个数的个数。
        int[] count = new int[10000];
        for (int c: deck){
			count[c]++;
		}

        int g = 0;
        for (int i = 0; i < 10000; i++){
			// 如果数组中某个数只有一个，则不符合要求。
			if (count[i] == 1) {
				return false;
			}else if (count[i] > 1) {
				g = gcd(g, count[i]);
				// 如果计算过程出现最大公约数为1，则不符合要求。
				if(g == 1){
					return false;
				}
            }
		}
		// 如果原数组中所有数的个数的最大公约数大于等于2，则符合要求。
        return true;
    }
	
	// 辗转相除求最大公约数。
    public int gcd(int x, int y) {
        return x == 0 ? y : gcd(y%x, x);
    }
}
```
