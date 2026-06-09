### 解题思路
注意我这个S不是引用，执行速度略有逊色，如果加了引用就会改变很多东西，在加一些代码就可以解决引用带来的影响，
但是这个是我做出的第一道回溯的题目，代码不希望太过冗余，希望简短一下。故采用直接拷贝传参，不用引用传参。
如果要引用传参参见用户Neo的题解
-----------------------------------------------------------------------------------
思路很简单，和递归一样，有一个出口，就是n>=size(),其次判断改字符是否是字母，不是就继续递归，是的话在次进行递归，好让他进入出口里，
然后在修改字符，在进入出口，在修改字符，在进入出口，直到全部进完为止。
### 代码

```cpp
class Solution {
public:

    void backtracking(vector<string>&vec,string S,int n){//从n下标开始找,end为结束标志
        if(n>=S.size()){
            vec.emplace_back(S);
            return ;
        } 
        if(isalpha(S[n])){
            backtracking(vec,S,n+1);
           if(islower(S[n])){
               S[n]=toupper(S[n]);
               /*backtracking(vec,S,n+1);
               来回变得，S[n]=tolower(S[n]);
               */
           }
           else{
               S[n]=tolower(S[n]);
               //backtracking(vec,S,n+1);
           }
              
        }
            backtracking(vec,S,n+1);

    }

    vector<string> letterCasePermutation(string S) {
        vector<string>vec;
        backtracking(vec,S,0);
        return vec;
    }
};
```