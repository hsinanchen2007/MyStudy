# 91. 解码方法
**思路：**
类似爬楼梯，在每一步向下一步走只有两种情况，走一步或走两步；而如果组成的数字大于26的话，无法走两步，还要进行特殊遍历到0的处理
**代码实现：**
```
class Solution {
public:
	int recursion( string &s , int position ) {
		if ( position == s.size() ) {
			return 1;
		} else if ( s[position] == '0' ){
			return 0;
		}
		
		int sum_1 = recursion(s,position+1);
		int sum_2 = 0;
		
		if( position + 1 < s.size() ){
			if ( 10 * (s[position] - '0') + (s[position+1] - '0') <= 26 ) {
				sum_2 = recursion(s,position+2);
			}
		}
		return sum_1 + sum_2;
	}
	
    int numDecodings(string s) {
		if ( s.size() == 0 || s[0] == '0' ) {
			return 0;
		} else {
			return recursion(s,0);
		}
    }
};
```
