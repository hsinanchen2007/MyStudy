# 171. Excel表列序号（C++）
遍历string元素，并转化为10进制。
```
class Solution {
public:
    int titleToNumber(string s) {
		int rst = 0;
        for( char item : s ){
			rst = (rst*26) + ((item-'A')+1);
		}
		return rst;
    }
};

```
