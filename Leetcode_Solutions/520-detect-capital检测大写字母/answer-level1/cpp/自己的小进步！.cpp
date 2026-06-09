### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
bool detectCapitalUse(string word) {
   
	if (word[0] >= 'A'&&word[0] <= 'Z') {
        if (word[1] >= 'A'&&word[1] <= 'Z'){
            for(int i=2;i<word.size();){
                if(word[i] >= 'A'&&word[i] <= 'Z'){
                    i++;
                }
                else{return false;}
            }    
        } 
        if (word[1] >= 'a'&&word[1] <= 'z'){
            for(int i=2;i<word.size();){
                if(word[i] >= 'a'&&word[i] <= 'z'){
                    i++;
                }
                else{return false;}
            }    
        } 
	}//end if
	if (word[0] >= 'a'&&word[0] <= 'z') {
		for (int i = 1; i < word.size(); ) {
			if (word[i] >= 'a'&&word[i] <= 'z') {
				i++;
			} else{return false;}
		}
	}
	return true;

}
};
```