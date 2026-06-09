### 解题思路
这道题有很多思路，但是我都没想到，所以看了解题。
第一种方法是用动态规划，定义一个vector<bool> temp来存储第i个字符和第j个字符是否重复，
最重要的是 temp[j] = (s[i] == s[j] && (i - j < 3 || temp[j + 1]));
首先确保s[i]==s[j]，且若比较的位置相差3以下，他们中间就没有字符，若距离大于等于3那就要判断i,j之间字符是否是重复的了。


第二种方法是中心扩散法。通过找到回文的中心，然后向外扩散。
根据回文中心可以为一个数或者两个数，分别讨论。
重点是start = i-(curlen-1)/2;和end = i+curlen/2;



还有一个拉马车法。看不懂。。。。
### 代码

```cpp
class Solution {
public:

    // 执行用时 :1064 ms, 在所有 C++ 提交中击败了5.03% 的用户
    // 内存消耗 :6.8 MB, 在所有 C++ 提交中击败了100.00%的用户
    string longestPalindrome(string s) {
        int n = s.size();
        vector<bool> temp(n, false);
        int maxlen = 0;
        int start = 0, end = 0;
        for(int i = 0;i<n;++i){
            for(int j = 0;j<=i;++j){
                // temp[j] = (s[i]==s[j] && (temp[j+1] || (i-j<3))); //为啥这样写不对？？？？
                temp[j] = (s[i] == s[j] && (i - j < 3 || temp[j + 1]));
                if(temp[j] && (i-j+1)>maxlen){ 
                    maxlen = i-j+1;
                    start = j;
                    end = i;
                }
            }
        }
        
        return s.substr(start, end-start+1);
    }
    


//     执行用时 :52 ms, 在所有 C++ 提交中击败了68.37% 的用户
//     内存消耗 :6.7 MB, 在所有 C++ 提交中击败了100.00%的用户
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1) return s;
        int start = 0, end = 0, curlen=0;
        for(int i = 0;i<n;++i){
            int len1 = palindromeCore(s, i, i);//返回以i为中心的回文的长度
            int len2 = palindromeCore(s, i, i+1);//返回以i和i+1位中心的回文长度
            curlen =max(max(len1,len2), curlen);
            if(curlen>end-start+1){
                start = i-(curlen-1)/2;
                end = i+curlen/2;
            }
        }
        return s.substr(start, curlen);
    }
    int palindromeCore(string& s, int center1, int center2){
        int l = center1, r = center2;
        while(l>=0&&r<s.size()&&s[l]==s[r]){
            --l;
            ++r;
        }
        return r-l-1;计算回文长度。
    }
    
};
```