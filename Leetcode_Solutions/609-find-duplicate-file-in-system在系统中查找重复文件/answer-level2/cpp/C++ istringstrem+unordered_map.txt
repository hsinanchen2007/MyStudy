### 解题思路
思路很简单，使用HASH表进行储存。注意的一点是istringstream的用法：当重复使用同一个istringstream对象时，要注意每次读取操作完之后，需要调用clear对stream的流状态进行清空，这是因为：当到达字符串的结尾处时（while循环），eofbit和failbit都会被置位，表示流的状为失败。一旦流发生失败，其上后续的IO操作都会失败。当前替代方案是，在每次while循环内构造一个新的istringstream对象。
参考：[https://stackoverflow.com/questions/2767298/c-repeatedly-using-istringstream]( https://stackoverflow.com/questions/2767298/c-repeatedly-using-istringstream)

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ret;
        if(paths.size() == 0) return ret;

        typedef vector<string> dirs;
        unordered_map<string, dirs> maps;
        
        string base_path;
        string file;
        string ab_path;
        string content;
        string::size_type pos = 0;
        istringstream record;

        for( auto path : paths) {
            record.clear();
            record.str(path);
            record >> base_path;
            while( record >> file) {
                pos = file.find('(');
                content = file.substr(pos);
                ab_path = base_path + "/" + file.substr(0, pos);
                maps[content].push_back(ab_path);
            }
        }

        for(auto map : maps) {
            if(map.second.size() > 1) {
                ret.push_back(map.second);
            }
        }

        return ret;
    }
};
```

### 关于思考题
1. 假设您有一个真正的文件系统，您将如何搜索文件？广度搜索还是宽度搜索？

广度搜索。
> 我们常用的文件通常不会放在太深的文件夹，我们应该一层一层下去搜索，放在浅层目录先被搜索，如果实时显示结果，得到想要的结果即停止，用广度优先搜索的优势就更能体现出来了。

> BFS 常用于找单一的最短路线，它的特点是 "搜到就是最优解"，而 DFS 用于找所有解的问题，它的空间效率高，而且找到的不一定是最优解，必须记录并完成整个搜索，故一般情况下，深搜需要非常高效的剪枝

参考：
- [Java用广度优先搜索快速搜索文件](https://blog.csdn.net/e_one/article/details/62237153?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)
- [一文读懂 BFS 和 DFS 区别 ](https://mp.weixin.qq.com/s?src=11&timestamp=1583076306&ver=2190&signature=tJznDqTDdqufYGuLu729wHCZa-7I-QBy3G2AuHU76Islid5UeGxjST0en4KEz4alsCvtSXaBahsLTunsVseq8XGrdWsbXcJMnCiAZDg6zCdS7xZIl450nkBcLfVR8JUc&new=1)

2. 如果文件内容非常大（GB级别），您将如何修改您的解决方案？
计算文件的MD5,将其MD5作为key,用于判断两个文件内容是否重复。当然，文件很大时，计算MD5也很耗时，此时可以选取文件的一些属性，如文件修改时间、文件大小来生成MD5。

3. 如果每次只能读取 1 kb 的文件，您将如何修改解决方案？
将文件分为固定块，大小为1KB，对每个数据分块计算HASH值。

参考：
- [数据去重技术原理分析](https://www.cnblogs.com/xinzhao/p/4729416.html)