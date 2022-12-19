分成以下几种情况讨论：
1.如果串长度为1，返回空串。
2.如果在串的前半部分出现非a，直接换成a，返回就可以
3.还有一种情况是字符串全部是a，那么在最后一个字符换成b就Ok啦。
注意：因为原串是回文串，所以只用考虑前半部分就可以啦。
```
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n==1)return "";
        //如果所有字符都相同，全部为a，则最后一个用b替换
        //string ans;
        bool flag=false;
        for(int i=0;i<n/2;i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome[n-1]='b';
        return palindrome;
    }
};
```
方法二：原理均一样，就是代码有所差别：
```
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n==1)return "";
        bool flag=false;

        for(int i=0;i<n;i++){
            if((n&1)&&n/2==i)continue;
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                flag=true;
                break;
            }
        }
        if(!flag)palindrome[n-1]='b';
        return palindrome;
    }
};
```
