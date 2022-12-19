### 解题思路
1. 目的是构造一个新的字符串，它是原字符串的一个排列，那么这个新串何时构造好呢？很明显新串的长度和原串相同时，说明该字符串构造好了，关于重复选择某个字符的问题，使用一个标记数组即可解决。
2. 对于有重复字符的字符串的排列，常见做法是：
    a.先将原串排序
    b.假如出现`s[i]`和`s[i+1]`相等，且某次选择时`s[i]`**没有被选上**而`s[i+1]`**被选上**的情况,跳过！
3. 关于回溯法，有三个步骤：a. `choose` b. `explore`(递归) c. `unchoose`(递归回来)  ---- 见代码

### 代码

```cpp
class Solution {
public:
    vector<string> ans;
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<bool>visit;
        visit.assign(s.size(), false);
        helper(s, visit, 0, s);
        return ans;
    }

    void helper(string s, vector<bool>& visit, int index, string tmp){
        if(index == s.size()){
            ans.push_back(tmp);
            return ;
        }
        for(int i = 0; i < s.size(); ++i){
            if(visit[i] == true || (i - 1 >= 0 && s[i-1] == s[i] && visit[i-1] == false)) continue;
            else{
                //choose
                visit[i] = true;
                tmp[index] = s[i];
                //进入递归explore
                helper(s, visit, index+1, tmp);
                //递归回来，unchoose
                visit[i] = false;
            } 
        }
    }
};
```