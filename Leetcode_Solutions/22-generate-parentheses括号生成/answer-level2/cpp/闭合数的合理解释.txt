## 闭合数
```C++ []
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0)  ans.push_back("");
        else{
            for(int c = 0; c < n; c++)
                for(string left: generateParenthesis(c))
                    for(string right: generateParenthesis(n - 1 - c))
                        ans.push_back("(" + left + ")" + right);
        }
        return ans;
    }
};

```
对于任意的一个序列S[n]


                S[n] = '(' + S[c] + ')' + S[n - c - 1];

其实相当于在之前的基础上做的运算，这里需要注意的是，当n=0的时候，必须要有一个空的字符串
""因为

                S[n] = '(' + S[n - 1] + ')' + S[0];

显然这里的S[0]必须要是空串。   


其实仔细一想貌似利用动态规划的思想也可以，只是子问题不需要再比较，因为每一个序列本身就是一个最优解。

用一个数据结构将之前的子问题保存下来就不必每次都递归子问题，但是这样可能需要更多的空间，但是细想一下，如果递归的栈很深的话，可能会需要更多的内存，因为相对于n来说它需要将前面的所有都保存下来，好像并不会比直接用数据结构保存来的更省，并且数据结构还能够带来更快的速度，**说试就试**

## 闭合数改进    

```C++ []
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        map<int, vector<string>> map;
        map[0].push_back("");
        for(int i = 1; i <= n; i++)
            for(int c = 0; c < i; c++)
                for(string left: map[c])
                    for(string right: map[i - 1 - c])
                        map[i].push_back("(" + left + ")" + right);
        return map[n];
    }
};

```
![image.png](https://pic.leetcode-cn.com/55213d167346a61bab477934f97e4796acac61f68c7b75b470926117c3bc66f4-image.png)

**果然，通过Map将之前的字问题全部存起来，真的带来了更快的速度和更小的内存！**

## 回溯法

```C++ []
class Solution {
public: 
    void back(vector<string> &ans, string curr, int left, int right, int max){
        if(curr.length() == 2*max){
            ans.push_back(curr);
            return ;
        }
        if(left < max)
            back(ans, curr + "(", left + 1, right, max);
        if(right < left)
            back(ans, curr + ")", left, right + 1, max);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        back(ans, "", 0, 0, n);
        return ans;
    }
};

```
**注意这里传入ans的是地址**