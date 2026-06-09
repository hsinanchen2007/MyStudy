执行用时 :4 ms, 在所有 cpp 提交中击败了98.90%的用户
内存消耗 :9.2 MB, 在所有 cpp 提交中击败了49.67%的用户

    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(!isdigit(s[i])&&!isalpha(s[i])){
                i++;
            }
            else if(!isdigit(s[j])&&!isalpha(s[j])){
                j--;
            }
            else{
                if(tolower(s[i])!=tolower(s[j])){
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
```