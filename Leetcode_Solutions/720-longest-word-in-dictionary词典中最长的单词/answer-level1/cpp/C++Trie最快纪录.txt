![image.png](https://pic.leetcode-cn.com/77f273302118800241a05de37f0fca548977634f70763f632e196ff9fd2e69ab-image.png)
觉得我够快就点个赞吧！
首先读题可知本题是一道检索字符串的题，可采用字典树、无序字典这两种方法。我都尝试了，无序字典法用时48ms（也可能是因为我没有进一步优化？）不如字典树快。
那么在确定了字典树之后，进一步确定思路是先插入，再检索，不需要排序。检索过程中如果有节点断开（即下面代码中的word_here变量为false），则检索失败。另外，由于所有单词都插入过了，所以检索时不可能出现访问空指针的情况，故不予检查。另外实测发现本例中用vector比数组快。另外本来我的插入和检索函数均是递归函数，但同行审阅（误）后改为了静态函数，用循环代替递归，应该对提速也有帮助。
最后，这题只有简单难度再次降低了我对leetcode的难度标签的信任。
```c++
class Solution {
public:
    class Tree{
    public:
        bool word_here;
        vector<Tree*> v;
        Tree():word_here(false), v(26){};
        static void insert(Tree* t, const string &s){
            for(char c:s){
                if(!t->v[c-'a'])
                    t->v[c-'a'] = new Tree();
                t = t->v[c-'a'];
            }
            t->word_here = true;
        }
        static bool search(Tree* t, const string &s){
            for(char c:s){
                if(!t->v[c-'a']->word_here)
                    return false;
                t = t->v[c-'a'];
            }
            return true;
        }
    };
    string longestWord(vector<string>& words) {
        Tree* root = new Tree();
        for(string &s:words)
            Tree::insert(root, s);
        string longest;
        for(string &s:words)
            if(Tree::search(root, s)){
                if(s.size()>longest.size())
                    longest=s;
                else if(s.size()==longest.size()&&s<longest)
                    longest=s;
            }
        return longest;
    }
};
```