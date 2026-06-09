### 解题思路
此处撰写解题思路

### 代码

```c
bool detectCapitalUse(char * word){
    int length=0,i;
    while(word[length]!=0) length++;
    if(word[0]>='A'&&word[0]<='Z'){
        if(word[1]>='A'&&word[1]<='Z'){
            for(i=1;i<length;i++)
                if(word[i]>='a'&&word[i]<='z') return 0;
        }
        else{
            for(i=1;i<length;i++)
                if(word[i]>='A'&&word[i]<='Z') return 0;
        }
    }
    else{
        for(i=0;i<length;i++)
            if(word[i]>='A'&&word[i]<='Z') return 0;
    }
    return 1;
}

//python  人傻了，三个库函数即可
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        return word.isupper() or word.islower() or word.istitle()

//java现在正在学
class Solution {
    public boolean detectCapitalUse(String word) {
        
       
        char[] chars = word.toCharArray();
        int upper = 0;//大写字母个数
        int lower = 0;//小写字母个数
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] - 'a' < 0)
                upper++;
            else 
               lower++; 
        }
        
        if (upper == chars.length || lower == chars.length || (upper == 1 && chars[0] < 'a'))
            return true;
        else 
            return false;
    }
}    //if判定条件是关键思路


