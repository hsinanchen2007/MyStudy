 ```
class Solution {
public:
    string defangIPaddr(string address) {
     	char add[50];
	int n = 0;
	for (int i = 0; i < address.size() + 1; i++) {
		
			if (address[i] == '.')
			{
				add[n] = '['; n++;
				add[n] = '.'; n++;
				add[n] = ']'; n++;
				i++;
	         }
			add[n] = address[i];
			 n++;	
	}
	address = add;
	return address;   
    }
};
```
不使用字符串的替换功能下如何改进？，本人初三狗，可能比较渣，勿喷，谢谢各位大佬。
提交时间提交结果执行用时内存消耗语言6 分钟前通过4 ms8.1 MBCpp
