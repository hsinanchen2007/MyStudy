### 解题思路
执行用时击败9.64%，效率略低。。。
用迭代方法解决问题，f(n)=f(f(n-1))=...=f(f(..f(1)));
f(1)="()";
f(2)="(())"、"()()";
...

规则f表示在一个串中，
1）每次遇到左括号，就在这个左括号的右边加入(),生成新的串放入下一个集合中；
2）在这个串的最右边加上()，生成新的串放入下一个集合中。

思路：
1、使用规则f，从n=1开始不断迭代，算出n=2, n=3......
2、采用集合来保存每次得到的新的串（不重复）。

看了大家的题解后，有了更高效的思路：
1、DFS搜索：想象是一棵左儿子为（，右儿子为）的树，不断DFS遍历这棵树到叶子节点；
2、DP动态规划。
### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
       //应该是可以用递归的(用迭代省空间)
       //不断把加的那个括号放到(的右边,以及最后一个）的右边
       set<string> last;
       last.insert("()");
       vector<string> re;
       if(n==0) return re;
       re.push_back("()");
       if (n==1) return re;
       n--;
       set<string> cur;
        while(n){
            cur.clear();
            for(set<string>::iterator it=last.begin(); it!=last.end(); it++){
                for (int j=0; j<(*it).size(); j++){
                    if((*it)[j]=='('){
                        cur.insert((*it).substr(0, j+1)+"()"+ (*it).substr(j+1, (*it).size() -j-1));
                    }
                }
                cur.insert((*it)+"()");
            }
            n--;
            last=cur;
        }
        re.pop_back();
        for(set<string>::iterator it=cur.begin(); it!=cur.end(); it++){
            re.push_back(*it);
        }
        return re;
    }
};
```