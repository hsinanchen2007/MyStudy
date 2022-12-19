# 168. Excel表列名称（C++）
本质是10进制转化为26进制，需要考虑一个特殊情况，余数为0时，需要-1.
```
class Solution {
public:
    string convertToTitle(int n) {
        string rst = "";
		while( n > 0 ){
			int yushu = n % 26;
			if( yushu == 0 ){
				rst += 'Z';
				n = (n / 26) - 1;
				continue;
			}
			
			n /= 26;
			rst += ('A'+yushu-1);
		}
		reverse(rst.begin(), rst.end());
		return rst;
    }
};
```
