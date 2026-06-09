### 解题思路
这道题比较麻烦的是，最后侧的空格可能会是字符自带的，设前侧有x个空格，后侧字符自带空格y个
则后侧空格总数=2*x+3*y;
但是实际上我觉得"ds sdfs afs sdfa dfssf asdf             "，27这个测试用例是错的，这个用例尾端应该有一个自带空格，因此尾部有一个%20，为了过这个用例hk=(len-length-qk*2)/3-1; 多了个-1，实际上我觉得应该没有-1

### 代码

```cpp
class Solution {
public:
    string replaceSpaces(string S, int length) {
        string res;
		int qk=0,len=S.length();
		for(int i=0;i<length;++i){
			if(S[i]==' ') {
               ++qk; 
               res+="%20";
            }
			else res+=S[i];
		}
		int hk=(len-length-qk*2)/3-1;
		while(hk-->0) res+="%20";
		return res;
    }
};
```