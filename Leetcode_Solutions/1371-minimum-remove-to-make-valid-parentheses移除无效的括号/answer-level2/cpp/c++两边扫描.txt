先从左到右扫描，移除左边无匹配的右括号，再从右往左扫描，移除右边无匹配的左括号。

```
    string minRemoveToMakeValid(string s) {
        int left = 0;
        int right = 0;
        for(int i = 0;i < s.length();i ++){
            if(s[i] == '(') left ++;
            else if(s[i] == ')'){
                right ++;
                if(right > left){
                    s.erase(i,1);
                    right --;
                    i --;
                }    
            }
        }
        if(left > right){
            int l = left - right;
            int i = s.length() - 1;
            while(l){
                if(s[i] == '('){
                    s.erase(i,1);
                    l --;
                    i ++;
                }
                i --;
            }
        }
        return s;
    }
};
```
