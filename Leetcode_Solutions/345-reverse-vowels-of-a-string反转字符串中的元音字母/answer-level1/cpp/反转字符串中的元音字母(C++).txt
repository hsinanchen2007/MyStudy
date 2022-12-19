双指针
思路：
    从两边往中间找
    左边遇到不是元音字母则往右继续找，右边遇到不是元音字母则往左找，遇到元音字母则交换
    我提交的时候没有考虑字符串为0的情况，提示数组越界，加个判断则通过了。
```
    bool is_ok(char ch){
	    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
		    return true;
	    return false;
    }
    string reverseVowels(string s) {
        if(s.size() <= 0) return s; 
        string::size_type left = 0, right = s.size()-1;
	    while(left < right){
            if(!is_ok(s[right])){
			    --right;
                continue;
		    }
            if(!is_ok(s[left])){
			    ++left;
                continue;
		    }
            swap(s[left],s[right]);
            ++left,--right;
	    }
        return s;
    }
```
