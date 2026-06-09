### 解题思路

在之前到解题中， https://leetcode-cn.com/problems/word-ladder/solution/cpp-sui-ran-su-du-you-dian-man-dan-shi-bi-jiao-ron/

每次选择下一个节点的方法，是通过计算当前单词和wordList里每个单词的距离，从而得到下一步往哪里走，单词越多，单词长度越长，速度越慢。

在看了 https://leetcode.com/problems/word-ladder/discuss/513850/C%2B%2B-Simple-BFS-Solution-without-HashMaps 代码之后，发现原来可以不需要计算距离，我们直接写两层循环，

按个遍历当前单词的每个字母，然后对他进行替换'a'-'z'，如果单词替换之后，能够在我们的节点中找到下一个词，那么就将哪个词加入队列中，同时把该节点移除候选节点。

```cpp
            //寻找下一个单词了
            char ch;
            for (int i = 0; i < tmp.length(); i++){
                ch = tmp[i];
                for (char c = 'a'; c <= 'z'; c++){
                    //从'a'-'z'尝试一次
                    if ( ch == c) continue;
                    tmp[i] = c ;
                    //如果找到的到
                    if (  s.find(tmp) != s.end() ){
                        q.push({tmp, step+1});
                        s.erase(tmp) ; //删除该节点
                    }
                tmp[i] = ch; //复原
                }
               
            }
```

![image.png](https://pic.leetcode-cn.com/a49d6bdf6758d198a0f757bedf0f649228d12572bb81b9efe5ffac3dd0571987-image.png)

从原来计算距离，是O(M*N)(M是单词长度，N是单词数量，广度优先遍历最坏情况下遍历N次)， 感谢评论区@Code2qing的指正

而现在，就是O(n), 里面的a-z是一个常数项，不会像之前的距离计算那样，因为单词的字母增加而增加。

### 代码

```cpp
class Solution{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        //加入所有节点，访问过一次，删除一个。
        unordered_set<string> s;
        for (auto &i : wordList) s.insert(i);

        queue<pair<string, int>> q;
        //加入beginword
        q.push({beginWord, 1});

        string tmp; //每个节点的字符
        int step;    //抵达该节点的step

        while ( !q.empty() ){
            if ( q.front().first == endWord){
                return (q.front().second);
            }
            tmp = q.front().first;
            step = q.front().second;
            q.pop();

            //寻找下一个单词了
            char ch;
            for (int i = 0; i < tmp.length(); i++){
                ch = tmp[i];
                for (char c = 'a'; c <= 'z'; c++){
                    //从'a'-'z'尝试一次
                    if ( ch == c) continue;
                    tmp[i] = c ;
                    //如果找到的到
                    if (  s.find(tmp) != s.end() ){
                        q.push({tmp, step+1});
                        s.erase(tmp) ; //删除该节点
                    }
                tmp[i] = ch; //复原
                }
               
            }
        }
        return 0;
    }
};
```

![image.png](https://pic.leetcode-cn.com/317cbb164da1c2068cc3e3c47826b714fbaefbe7c313a6c9e3db11c28c1ad69f-image.png)


如下是双向BFS代码, 代码其实不复杂。相对于之前单向BFS，有如下改进

- 使用两个set，分别从start和end两头开始BFS
- 每次选择较小的set开始BFS, 也就是将小的作为start，大的作为end
- 如果end中能找到start，就结束
- 否则，在访问set中加入访问记录，并加入到tmp中，作为子节点。

```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end() ) return 0;
        // 初始化起始和终点
        unordered_set<string> beginSet, endSet, tmp, visited;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int len = 1;

        while (!beginSet.empty() && !endSet.empty()){
            if (beginSet.size() > endSet.size()){
                tmp = beginSet;
                beginSet = endSet;
                endSet = tmp;
            }
            tmp.clear();
            for ( string word : beginSet){
                for (int i = 0; i < word.size(); i++){
                    char old = word[i];
                    for ( char c = 'a'; c <= 'z'; c++){
                        if ( old == c) continue;
                        word[i] = c;
                        if (endSet.find(word) != endSet.end()){
                            return len+1;
                        }
                        if (visited.find(word) == visited.end() && dict.find(word) != dict.end()){
                            tmp.insert(word);
                            visited.insert(word);
                        }
                    }
                    word[i] = old;
                }
            }
            beginSet = tmp;
            len++;
            

        }
        return 0;
    }
};

```
