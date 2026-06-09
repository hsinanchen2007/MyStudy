### 解题思路
这道题目其实需要我们构建关系映射：
我们可以只看一个单词，就拿样例来举例吧：

```
words = ccc , pattern = abb;
```
然后，进行判断，判断的标准如下：
- words中相同的字符对应的pattern中的字符必须相同
- pattern中相同的字符对应的words中的字符必须相同

这样的话，就可以构建关系了。以样例为准：
```
            words->pattern: 
[abc,abb]:  [c->a],[c->b],        false;
[deq,abb]:  [d->a],[e->b],[q->b], true;  [a->d],[b->e],[b->q], false;
[mee,abb]:  [m->a],[e->b],[e->b], true;  [a->m],[b->e],[b->e], true;
[aqq,abb]:  [a->a],[q->b],[q->b], true;  [a->a],[b->q],[b->q], true;
[dkd,abb]:  [d->a],[k->b],[d->b], true;  [a->d],[b->k],[b->d], false; 
[ccc,abb]:  [c->a],[c->b],        false;
```
所以，最终只有[mee,aqq]是两个条件都满足的，因此返回这两个条件。
### 代码

```cpp
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        //需要构建一种框架，使得这些单词和排列可以互相映射。
        vector<string> res;
        for(int i=0;i<words.size();i++){
            // cout << is_match(words[i],pattern) << endl;
            if(is_match(words[i],pattern)) res.push_back(words[i]);
        }
        return res;
    }
    //判断两个单词是否相等
    bool is_match(string a, string b){
        //a->b
        map<char,char> main_to_domain;
        //b->a
        map<char,char> domain_to_main;
        if(a.size() != b.size()) return false;
        for(int i=0;i<a.size();i++){
            if(!main_to_domain[a[i]]) main_to_domain[a[i]] = b[i];
            else if(main_to_domain[a[i]] != b[i]) return false;
            if(!domain_to_main[b[i]]) domain_to_main[b[i]] = a[i]; 
            else if(domain_to_main[b[i]] != a[i]) return false;
        }
        return true;
    }
};
```