
**滑动窗口**
1. 从字符串的最开始进行，设置两个指针begin=0，end=1。
2. 然后end不断地往后移动，每次移动的过程中都会与前面s[begin,end)的元素进行比较
	1. 如果没有相同的，则end指针继续往后移动，max长度加1.
	2. 如果有相同的，此时比较max与end-begin的值，取更大者。同时，把begin的位置设置为重复元素的下一个位置。
3. 通过设置flag标志位来查看新加入的元素是否重复。


**其他说明**
1. 最开始的时候判断极个别情况，字符串为空以及字符串只有一个字符的情况，可以直接返回。
2. 在k的for循环里 和 在end的for循环里 关于max的赋值三目表达式不同的原因：
	1. 前者中，发现s[k]==s[end]，因此s[end]所对应的字符是不能包含在最短字符串中的，因此最短字符串的长度应该为		end-begin+1-1=end-begin;	
	2. 后者中，属于新加入的元素与前面元素不重复的情况，因此end元素是可以算进去不重复子串中的，所以最短字符串长度为end-begin+1;




```
int lengthOfLongestSubstring(char * s){
    if (s[0]=='\0')
		return 0;
	if (s[1]=='\0')
		return 1;
	
	int max = 0;
	int begin = 0;
	int end;
	bool flag;//判断当前字符是否在画出的窗口内
	int k;
	
	for(end=1;s[end]!='\0';end++){
		flag = false;
		for(k=begin;k<end;k++){
			if(s[k]==s[end]){
				flag = true;
				max = (max>(end-begin))?max:end-begin;
				begin = k+1;
				break;
			}
		}
		
		if(!flag){
			max = max>(end-begin+1)?max:(end-begin+1);
		}
	}
	
	return max;
}
```
