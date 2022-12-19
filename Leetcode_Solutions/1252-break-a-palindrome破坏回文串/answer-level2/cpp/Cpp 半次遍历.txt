这是道脑筋急转弯题嘛。。。。

```cpp
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int N = palindrome.size();
        if(N <= 1) return "";
        int cnt = 0;
        while(cnt < N/2 && palindrome[cnt] == 'a') cnt++;
        if(cnt < N/2) palindrome[cnt] = 'a';
        else palindrome[N-1] = 'b';
        return palindrome;
    }
};
```