# 1. 理解
字符串的相关算法，例如最大公共子串、子串查找、最大回文子串等。这道题有多种解法。
# 2. 思路
## 2.1 分治算法(dfs和bfs)
自上而下，首先判断当前字符串是否是回文子串，然后递归地判断sub(0,size-1)和(1,size-1)子串。
这里又可以区分DFS和BFS算法，时间复杂度都是O(n3),理论上BFS算法在这里要更快一点，不过很遗憾，两种算法都超出了时间限制。
## 2.2 暴力算法(bf1和bf2)
暴力算法又分了两种实现：
bf2略快一些，但都是O(n3)时间复杂度，都超出了时间限制。
## 2.3 动态规划(dp)
动态规划的关键在于找到状态转移方程：
这里定义：p(i,j)表示字符串s[i,j]为回文子串，如果s[i-1]等于s[j+1],则有p(i-1,j+1)。
即$p(i,j) && s[i-1] = s[j+1] => p(i-i,j+1)$。需要区分子串是奇数还是偶数。
# 3. 代码
```c++ []
class Solution {
public:
    string longestPalindrome(string s) {
        return dp(s);
        // return bf1(s);
        // return bf2(s);
        // return is_palindrome(s) ? s : bfs(s);
        // return dfs(s);

    }
    
    string dp(string s){
        string answer = "";
        for(int i=0; i<s.size(); i++){
            for(int j=0; i-j>=0&&i+j<s.size(); j++){
                if(s[i-j] == s[i+j]){
                    if( 2*j+1>answer.size()) answer = s.substr(i-j, 2*j+1);
                }else{
                    break;
                }
            }
        }
        for(int i=0; i+1<s.size(); i++){
            for(int j=0; i-j+1>=0&&i+j<s.size(); j++){
                if(s[i-j+1] == s[i+j]){
                    if(2*j>answer.size()) answer = s.substr(i-j+1, 2*j);
                }else{
                    break;
                }
            }
        }
        return answer;
    }

    string bf2(string s){
        string answer = "";
        string subStr;
        for(int i=1; i<=s.size(); i++){
            for(int j=0; j+i<=s.size(); j++){
                subStr = s.substr(j, i);
                if(is_palindrome(subStr)){
                    answer = subStr;
                    break;
                }
            }
        }
        return answer;
    }

    string bf1(string s){
        string answer = "";
        for(int len=s.size(); len>0; len--){
            for(int i=0; i<s.size(); i++){
                string subStr = s.substr(i, len);
                if(is_palindrome(subStr) && subStr.size() > answer.size()){
                    answer = subStr;
                } 
            }
        }
        return answer;
    }

    string bfs(string s){
        string subLeft = s.substr(0,s.size()-1);
        if(is_palindrome(subLeft)) return subLeft;
        string subRight = s.substr(1,s.size()-1);
        if(is_palindrome(subRight)) return subRight;
        string leftBest = bfs(subLeft);
        string rightBest = bfs(subRight);
        return leftBest.size() >= rightBest.size() ? leftBest : rightBest;
    }

    string dfs(string s){
        if(is_palindrome(s)) return s;
        string subLeft = s.substr(0,s.size()-1);
        string answerL = longestPalindrome(subLeft);
        string subRight = s.substr(1,s.size()-1);
        string answerR = longestPalindrome(subRight);
        return answerL.size() >= answerR.size() ? answerL : answerR;
    }

    bool is_palindrome(string s){
        for(int low=0,high=s.size()-1; low <= high; low++,high--){
            if(s[low] != s[high]) return false;
        }
        return true;
    }
};
```
# 4. 总结
一题多解有时候不是为了这一题，而是拓宽思路，自己在做题时有更多的备选方法。
这道题最优的算法可以降到线性的时间复杂度，暴力算法时O(n3)的复杂度，即使是暴力算法也要好好掌握，毕竟咱先要把题做出来，再谈进一步的优化。