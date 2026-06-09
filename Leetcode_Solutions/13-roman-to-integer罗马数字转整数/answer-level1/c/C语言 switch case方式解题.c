### 解题思路
1.switch case方式，字符I,X,C单独处理，当下一位接对应特属字符时，做为被减数后正常跳过，下一位可正常做加数。
2.能这么做关键在于特属情况只有两位相连的情况，只需要判断特属字符的下一位即可。

### 代码

```c
int romanToInt(char* s){
	int strLength = strlen(s);
	int count = 0;
	while (*s){
		switch (*s){
			case 'I':{
				if (((*(s + 1)) == 'V') || ((*(s + 1)) == 'X')) {
					count -= 1;
				}
				else {
					count += 1;
				}
				break;
			}
			
			case 'V': 
				count += 5; 
				break;

			case 'X':{
				if (((*(s + 1)) == 'L') || ((*(s + 1)) == 'C')) {
					count -= 10;
				}
				else {
					count += 10;
				}
				break;
			}
			case 'L': 
				count += 50; 
				break;

			case 'C': {
				if (((*(s + 1)) == 'D') || ((*(s + 1)) == 'M')) {
					count -= 100;
				}
				else {
					count += 100;
				}
				break;
			}

			case 'D': 
				count += 500; 
				break;

			case 'M': 
				count += 1000; 
				break;

			default:
				break;
		}
		s++;
	}

	return count;
}
```