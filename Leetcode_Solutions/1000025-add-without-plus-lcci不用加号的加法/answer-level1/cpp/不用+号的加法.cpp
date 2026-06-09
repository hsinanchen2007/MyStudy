### 解题思路
ps:异或也叫半加运算，其运算法则相当于不带进位的二进制加法：所以异或常被认作不进位加法。
不能用加法，所以只能用二进制进位来算。把相加和进位分开，分成两步。
step1:a^b，完成不进位加法。step2:a&b，完成进位的运算。step3:把step2左移一位，模拟正常加法的向前进一位。一直到进行到进位没有为止，也就是step3=0的时候，说明全部进位完成，加法u全部算完了。

### 代码

```cpp
class Solution {
public:
    int add(int a, int b) {
        if(b==0)
            return a;
        int step1=0, step2=0, step3=0;
        while(b!=0){
        	step1 = a^b;
	        step2 = a&b;
	        step3 = (unsigned int)step2 << 1;
	        a = step1;
	        b = step3;
		}
        return step1;
    }
};
```