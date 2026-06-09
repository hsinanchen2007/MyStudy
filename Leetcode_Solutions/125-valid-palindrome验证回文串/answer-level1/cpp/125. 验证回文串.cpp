## 借助辅助string
**1. 把s中的数字和字母读入str中，并把大写字母改为小写
2. 判断str是否对称**
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int len_s=s.size();
        //把s中的数字和字母读入str中，并把大写字母改为小写
        string str;
        for(int i=0; i<len_s; i++){
            if(s[i]>='0' && s[i]<='9' || s[i]>='a' && s[i]<='z') str+=s[i];
            if(s[i]>='A' && s[i]<='Z') str+=s[i]+'a'-'A';
        }
        //判断str是否对称
        int len_str=str.size();
        if(len_str==0) return true;
        for(int i=0, j=len_str-1; i<j; i++, j--){
            if(str[i]!=str[j]) return false;
        }
        return true;
    }
};
```
## 双指针法
**1. i从前开始遍历，j从后开始遍历
2. 依次找到最前面和最后面的字母(数字)
3. 边比较边i++,j--
4. 若途中发现两边字母(数字)不同，返回false
5. 当i>=j时，返回true**

**注意：'0'和'P'也符合 '0'-'P'=='a'-'A' ！！！**
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int len=s.size(), i=0, j=len-1;
        while(i<j){
            while(i<=len-1 && (s[i]<'0' || s[i]>'9' && s[i]<'A' || s[i]>'Z' && s[i]<'a' || s[i]>'z')) i++;
            while(j>=0 && (s[j]<'0' || s[j]>'9' && s[j]<'A' || s[j]>'Z' && s[j]<'a' || s[j]>'z')) j--;
            if(i>=j) return true;
            if((s[i]<'9' || s[j]<'9') && s[i]!=s[j]) return false;
            if(s[i]!=s[j] && abs(s[i]-s[j])!='a'-'A') return false;
            while(s[i]==s[j] || s[i]>'9' && s[j]>'9' && abs(s[i]-s[j])=='a'-'A'){
                i++;
                j--;
                if(i>=j) return true;
            } 
        }
        return true;
    }
};
```
## 哈希表法 慢
```cpp
class Solution {
private:
    int hash[36]={0};
public:
    int getid(char ch){
        if(ch>='0' && ch<='9') return ch-'0';
        if(ch>='a' && ch<='z') return ch-'a'+10;
        if(ch>='A' && ch<='Z') return ch-'A'+10;
        return -1;
    }
    bool isPalindrome(string s) {
        int len=s.size(), i=0, j=len-1;
        if(len==0) return true;
        while(i<j){
            while(i<j && getid(s[i])==-1) i++;
            //cout<<"i="<<i<<endl;
            while(i<j && getid(s[j])==-1) j--;
            //cout<<"j="<<j<<endl;
            if(i>=j) return true;
            if(hash[getid(s[i])]%2==1) 
                return false;
            else{
                hash[getid(s[i])]++;
                i++;
            } 
            if(hash[getid(s[j])]%2==0) 
                return false;
            else{
                hash[getid(s[j])]++;
                j--;
            } 
        }
        return true;
    }
};
```