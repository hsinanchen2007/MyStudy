### 解题思路
假设delta_t>0, a = t + delta_t; b = t- delta_t
从而 a恒等于 (
((t+delta_t)+(t-delta_t)) + 
((t+delta_t)-(t-delta_t)
)/2
其中，(t+delta_t)-(t-delta_t) = 2*delta_t > 0
因此，实现的时候需要计算“差值的绝对值”
这里所谓的绝对值实际上就是“补码“表示

执行用时 :4 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    int maximum(int a, int b) {
    	long sum = long((long)a + (long)b);
    	long sub = long((long)a - (long)b);
    	long abs_sub = (sub ^ (sub >> 63)) - (sub >> 63);
//    	cout << hex << "a = " << a << " b = " << b <<endl;
//    	cout << hex << "sum = " << sum <<" sub = "<<sub<<endl;
//    	long abs_sub = (sub>>63)?(~sub+1):sub; // 选择运算符仍旧包含比较，不符题意
//    	cout << "~sub+1 = " << ~sub+1<<endl;
//    	cout << "my abs_sub = " << abs_sub << endl;
//    	cout << "SB's sub = " << (sub ^ (sub>>63)) - (sub>>63) << endl;
//    	cout << "具体：sub >> 63 = " << (sub >> 63) << endl;
//    	cout << "sub ^ (sub>>63) = " << (sub ^ (sub>>63)) << endl;
////    	int mask_bit = sub >> 63;
////    	long abs_sub = (sub ^ 63b{mask_bit}) + 1;
////    	long abs_sub = (sub ^ 0xFFFFFFFFFFFFFFFF) + 1;
////    	cout << "abs_sub = " << abs_sub << endl;
    	long max_num = (long)(sum + abs_sub);
//    	cout << "max_num = " << max_num << endl;
    	max_num /=2;
    	return max_num;
//    	//std::max内部仍旧是存在比较运算符，显然不够骚
//    	return std::max(a,b);
    }
};
```