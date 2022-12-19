[**leetcode 数据库题目全部题解**](https://leetcode-cn.com/circle/article/vGr1Mc/)

题意不难理解。utf-8最多4个字节。

位操作，特别是左移和右移，是易出错的。由于本题的二进制格式是固定的，可以不用左移或右移操作。

用二进制整数：0bxxxxxxxx，表示二进制格式，避免位操作出错。

检测思路：
```
while (位置p有效){
    位置p处的整数v;
    if((v & 0b10000000) == 0){
        还要检测的字节数 = 0;
    }else if((v & 0b11100000) == 0b11000000){
        还要检测的字节数 = 1;
    }else if((v & 0b11110000) == 0b11100000){
        还要检测的字节数 = 2;
    }else if((v & 0b11111000) == 0b11110000){
        还要检测的字节数 = 3;
    }else{
        没有这样的格式，错误
    }
    位置p前移1步;
    while (位置p有效 并且 还要检测的字节数 > 0){
        if((位置p处的字符 & 0b11000000) != 0b10000000) 出错;
        位置p前移1步;
        还要检测的字节数减少1个;
    }
    if(还要检测的字节数 > 0，说明碰到格式不正确) 错误;
}
到此处，格式一定正确。
```
代码：
```
bool validUtf8(vector<int>& data) {
	int p=0;
	while(p < data.size()){
		int v=data[p];
		int cnt = 0;
		if((v & 0b10000000) == 0){
			cnt = 0;
		}else if((v & 0b11100000) == 0b11000000){
			cnt = 1;
		}else if((v & 0b11110000) == 0b11100000){
			cnt = 2;
		}else if((v & 0b11111000) == 0b11110000){
			cnt = 3;
		}else{
			return false;
		}
		p++;
		while (p < data.size() && cnt > 0){
			if((data[p] & 0b11000000) != 0b10000000) break;
			p++;
			cnt--;
		}
		if(cnt>0) return false;
	}
	return true;
}
```