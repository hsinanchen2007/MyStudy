### 解题思路
当前值最好是由一个 数的平方组成的，那就是1；
如果不是一个平方呢？就需要拆成两半了，这两半最好都由一个数的平方组成，
我们只需要逐个计算比这个数小的平方数，加上的另一个数，这样的最小。
就由一个平方数+上另一个数组成，另一个数我们都算过，只要遍历所有的平方数
退而求其次呢，等于比他小的某一个数字的装入数+1；

### 代码

```cpp
class Solution {
public:
public:
	int numSquares(int n) {
		vector<int> mem(n + 1, n+1);
        mem[0]=0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j*j <= i; j++) {
				mem[i] = get_min(mem[i], mem[i - j*j] + 1);
			}
		}
		return mem[n];
    }
    int get_min(int x, int y){
        if(x<y) return x;
        else return y;

    }
};
```