```
// 一开始正常验证
// 当出现了不相等的情况时，分别跳过左边和右边的字符，取或，看看是否为true.
class Solution {
public:
    static bool ifPalind(string s, int& left, int& right) {
        while(left < right) {
            if(s[left] != s[right]) {
                return false;
            }
            left += 1;
            right -= 1;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;
        if( ifPalind(s, left, right) ) {
            return true;
        }
        else {
            // 因为为引用，因此重新构造了两对参数.
            // 第一对跳过了左边的字符
            // 第二对跳过了右边的字符
            int leftf = left+1;
            int rightf = right;
            int lefts = left;
            int rights = right-1;
            return ifPalind(s, leftf, rightf) || ifPalind(s, lefts, rights);
        }
    }
};
```