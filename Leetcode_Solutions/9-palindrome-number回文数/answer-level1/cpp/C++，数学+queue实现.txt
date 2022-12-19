纸片对折
```
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)   return false;
        int len = 0;
        int copy = 0;
        for(int i = x; i; i /= 10)  ++ len;
        for(int j = len / 2; j > 0; -- j){
            copy = copy * 10 + x % 10;
            x /= 10;
        }
        if(len % 2 == 1)    x /= 10;
        if(copy == x)   return true;
        return false;
    }
};
```
queue实现
```
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)   return false;
        queue<int> mm;
        int len = 0;
        int copy = 0;
        for(int i = x; i; i /= 10)  ++ len;
        for(int j = len / 2; j > 0; -- j){
            mm.push(x % 10);
            x /= 10;
        }
        if(len % 2 == 1)    x /= 10;
        for(int j = len / 2; j > 0; -- j){
            copy = copy * 10 + mm.front();
            mm.pop();
        }
        if(copy == x) return true;
        return false;
    }
};
```
