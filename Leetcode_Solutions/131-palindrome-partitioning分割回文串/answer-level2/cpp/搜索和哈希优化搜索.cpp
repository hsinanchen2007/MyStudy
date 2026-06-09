## 回溯搜索
```c++
class Solution {
    vector<string> path;
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }
    void dfs(string& s, int pos){
        if(pos == s.length()){
            res.push_back(path);
            return;
        }
        for(int i = pos; i < s.length(); i++){
            string a = s.substr(pos, i - pos + 1);
            string rev_a(a.rbegin(), a.rend());
            if(a == rev_a){
                path.push_back(a);
                dfs(s, i + 1);
                path.pop_back();
            }
        }
    }
};
```
很简单的回溯，每次切出一个字符串，如果是回文则继续搜索。
## 哈希优化回溯搜索
上面的方法中，最耗时的部分为取子串和判断字串是否为回文，我们可以用哈希来进行优化。for循环中，我们每次将该次搜索子串的长度+1，因此我们可以利用到上一次搜索的结果。

首先说明如何将一个字符串hash到一个整数。简单来说我们可以将一个字符串看成一个26进制的数，$a\rightarrow 0,b\rightarrow 1,...,z\rightarrow 26$。但是存在a开头的字符串，所以将映射改为$a\rightarrow 1,b\rightarrow 2,...,z\rightarrow 27$，看成27进制。一个字符串'abc'就可以看成'1,2,3'，根据进制转换，转换为十进制为$1*27^2+2*27+3$。我们能找到一个递推关系：当字符串'abc'的10进制值知道以后，在'abc'末尾加一个字母的10进制数也可以轻易得到:$hash("abcd") = hash("abc") * 27 + hash("d")$。

同样的，我们检验一个字符串是否为回文是通过将其倒过来和原字符串比较，因此一个字符串'abc'的翻转为'cba'，当字符串长度+1后例如：'abcd'，其翻转变为了'dcba'，相当于在上一个字符串的头部加了一个字母，此时有:$hash("dcba") = hash("cba") + hash("d") * 27 ^ 3$

贴上代码:
```c++
class Solution {
    vector<string> path;
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }
    void dfs(string& s, int pos){
        if(pos == s.length()){
            res.push_back(path);
            return;
        }
        unsigned int hash = 0, hash_r = 0, seed = 27, base = 1;
        for(int i = pos; i < s.length(); i++){
            hash = hash * seed + s[i] - 'a' + 1; // 计算正向字符串的哈希值
            hash_r += base * (s[i] - 'a' + 1); // 计算翻转字符串的哈希值
            base *= seed;
            if(hash == hash_r){
                path.push_back(s.substr(pos, i - pos + 1));
                dfs(s, i + 1);
                path.pop_back();
            }
        }
    }
};
```
和回溯搜索比较，唯一的差距就在于用hash值代替了字符串，将复杂度降低了许多。
![image.png](https://pic.leetcode-cn.com/82f44a291c1b9751bfa60e0c5b062a6f11d727902de4efa3e00e508c4d85ad5e-image.png)

当然，存在问题为，当样例足够多时，可能会出现碰撞，即哈希值相同但字符串不相同，但是概率很小。