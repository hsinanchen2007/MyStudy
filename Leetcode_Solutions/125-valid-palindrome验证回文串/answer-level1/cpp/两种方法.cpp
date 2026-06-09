方法一 
```
class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0,j=s.size()-1;i<j;){
            if(s[i]<'0'||('9'<s[i]&&s[i]<'A')||s[i]>'z'||('Z'<s[i]&&s[i]<'a')){
                i++;
                continue;
            } 
            if(s[j]<'0'||('9'<s[j]&&s[j]<'A')||s[j]>'z'||('Z'<s[j]&&s[j]<'a')){
                j--;
                continue;
            } 
            if(s[i]!=s[j]){
                if(s[i]>='0'&&s[i]<='9'||(s[j]>='0'&&s[j]<='9')) return false;
                if(abs(s[i]-s[j])!=32) return false; 
            } 
            i++;
            j--;     
        }
        return true;
    } 
};
```
```
class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0,j=s.size()-1;i<j;){
            if(!isalnum(s[i])){
                i++;
                continue;
            } 
            if(!isalnum(s[j])){
                j--;
                continue;
            } 
            if(s[i]!=s[j]){
                if(isdigit(s[i])||isdigit(s[j])) return false;
                if(abs(s[i]-s[j])!=32) return false; 
            } 
            i++;
            j--;     
        }
        return true;
    }
};
```
方法二
```
class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(auto c: s)
            if(isalnum(c)) str += tolower(c);
        for(int i=0,j=str.size()-1;i<j;i++,j--)
            if(str[i]!=str[j]) return false;
        return true;
    } 
};
```


