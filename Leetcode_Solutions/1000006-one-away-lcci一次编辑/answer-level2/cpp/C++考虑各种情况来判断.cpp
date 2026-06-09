### 解题思路
1. 首先解决几种简单情况，比如两个字符串相差为大于等于$2$，则直接返回$false$；
2. 如果两个字符串已经相等，直接返回$true$
3. 如果两个字符串长度相等，逐一对比元素，如果有两个或以上不同，返回$false$
4. 如果两个字符串长度差$1$，总让$first$比$second$长，如果第$i$个字符不同，把$first$的第$i+1$个和$second$的第$i$个字符来比较，统计不同的字符长度，如果$≥2$，返回$false$.
5. 否则返回$true$

### 代码

```cpp
class Solution {
public:
    bool oneEditAway(string first, string second) {
        if(abs(int(first.size() - second.size())) >= 2)
	        return false;     	
        
        if(first == second)
        	return true;
        
        bool ok=true;
        if(first.size() == second.size()) { 
        	int replace=0;  // 统计不同的字符数
        	for(int i=0; i<first.size(); i++) {
        		if(first[i] != second[i])
        			replace++;
        		if(replace > 1) { // > 1,不可能了
        			ok = false;
        			break;
				}
        			
			}
//			cout << replace << endl;
			if(replace == 1)
				ok = true;
		}
	
		else {	// 两者长度差1
			if(first.size() < second.size()) {
				string temp=first; // 如果first短，交换
				first = second;
				second = temp;
			}
			int c=0, i=0, j=0;    // c:统计不同字符，i:first的指针, j:second的指针
			while(i < first.size() && j < second.size()) {
				if(first[i] != second[j]) {
					i++;
					c++;
				}
				else {// 对应字符相等，看下一个字符
					i++;
					j++;
				}
				if(c >= 2) { // >2，不可能了
					ok = false;
					break;
				}
			}
			if(c == 1)
				ok = true;
			
		}
		
		return ok;
    }  
};
```