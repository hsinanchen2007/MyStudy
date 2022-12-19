如果一个字符串括号匹配，那么其内层括号也一定是匹配的。

1. 先从左向右扫描找到第一个`)`
2. 从右向左扫描找到第一个`(`，如果找到，对两者做标记
3. 回到1，直到遍历整个字符串

此时，从左到右遍历找出最长的标记了的连续子串就行了。

```cpp []
/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int len=s.size();
        bool*pat=new bool[len];
        for(int i=0;i<len;i++){
            pat[i]=false;
        }
        for(int i=0;i<len;i++){
            if(s.at(i)==')'){
                for(int j=i-1;j>=0;j--){
                    if(!pat[j]&&s.at(j)=='('){
                        pat[i]=true;
                        pat[j]=true;
                        break;
                    }
                }
            }
        }
        int res=0;
        int tmp=0;
        for(int i=0;i<len;i++){
            if(pat[i]){
                tmp++;
            }else{
                res=max(tmp, res);
                tmp=0;
            }
        }
        res=max(tmp, res);
        delete[] pat;
        return res;
    }
};

/*
√ Accepted
  √ 230/230 cases passed (16 ms)
  √ Your runtime beats 46.24 % of cpp submissions
  √ Your memory usage beats 97.46 % of cpp submissions (9.1 MB)
*/
```
```java []
/*
 * @lc app=leetcode.cn id=32 lang=java
 *
 * [32] 最长有效括号
 */
class Solution {
    public int longestValidParentheses(String s) {
        boolean pat[]=new boolean[s.length()];
        for(int i=0;i<pat.length;i++){
            pat[i]=false;
        }
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)==')'){
                for(int j=i-1;j>=0;j--){
                    if(!pat[j]&&s.charAt(j)=='('){
                        pat[i]=true;
                        pat[j]=true;
                        break;
                    }
                }
            }
        }
        int res=0;
        int tmp=0;
        for(int i=0;i<pat.length;i++){
            if(pat[i]){
                tmp++;
            }else{
                res=Math.max(tmp, res);
                tmp=0;
            }
        }
        res=Math.max(tmp, res);
        return res;
    }
}
/*
√ Accepted
  √ 230/230 cases passed (8 ms)
  √ Your runtime beats 63.18 % of java submissions
  √ Your memory usage beats 86.81 % of java submissions (36.8 MB)
*/

```

本题解被同步发布在[我的博客](https://www.ntutn.top/show/88)上，有空可以去踩踩。