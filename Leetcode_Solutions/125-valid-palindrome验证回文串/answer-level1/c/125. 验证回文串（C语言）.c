# 125. 验证回文串
两个指针的方法，遍历数组
```
bool isPalindrome(char * s){
	int left = 0;
	int right = strlen(s) - 1;
	
	if( !s || right <= 0 ){
		return true;
	}
	
	char s_cpy[right+1];
	memcpy(s_cpy,s,strlen(s));
	
	while( left < right ){
		if( ( !isdigit(s_cpy[left]) ) && ( !isalpha(s_cpy[left]) ) ){
			++left;
			continue;
		}
		if( ( !isdigit(s_cpy[right]) ) && ( !isalpha(s_cpy[right]) ) ){
			--right;
			continue;
		}
		
		if( isupper(s_cpy[left]) ){
			s_cpy[left] = tolower(s_cpy[left]);
		}
		if( isupper(s_cpy[right]) ){
			s_cpy[right] = tolower(s_cpy[right]);
		}	
		
		if( s_cpy[left] == s_cpy[right] ){
			++left;
			--right;
			continue;
		}else{
			return false;
		}	
	}
	return true;
}
}
```

想问一下:为什么必须把char * s 拷贝一下 ，而不能直接使用s[i]修改数组的值呢？