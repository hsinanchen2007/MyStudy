方法一 转字符串
```
class Solution {
public:
    bool isPalindrome(int x) {
        string tmp=to_string(x);
        string tmp2=tmp;
        reverse(tmp2.begin(),tmp2.end());
        if(tmp==tmp2) return true;
        return false;
        // for(int i=tmp.size()-1,j=0;i>0,j<i;i--,j++)
        //     if(tmp[i]!=tmp[j]) return false;
        // return true;
    }
};
```
方法二 利用vector，直接比较首尾
```
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x/10==0) return true;
        vector<int> tmp;
        while(x>0){
            tmp.emplace_back(x%10);
            x=x/10;
        }
        for(int i=tmp.size()-1,j=0;i>0,j<i;i--,j++)
            if(tmp[i]!=tmp[j]) return false;
        return true;
    }
};
```
方法三 将数倒转
```
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x/10==0) return true;
        long long cur = 0;
        int num = x;
        while(num != 0) {
            cur = cur * 10 + num % 10;
            num /= 10;
        }
        return cur == x;   
    }
};
```


