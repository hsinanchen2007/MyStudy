
主要就是贴一下自己借鉴摸索的C++代码

破解密码的问题就像是一个树搜索的问题，把每一种一步变换的结果都放在该初状态的子节点里
（用deadends和visited进行剪枝，deadends用于去掉包含死路的解法，visited用于避免已经走过的路）
然后再去搜索这个target，搜索的深度就是最短的步数
可以用BFS来实现

好了，思路比较清晰了，接下来就是码代码了，为了挑战自己，采用了C++进行编程
惭愧C++确实不熟悉，导致我调代码调了很久，摔

主要学习的有以下几点：
- 一个unordered_set的用法，说是基于hash表，所以check是否在deadends里的速度会快一些（妈蛋，原来在其他语言里面类似not in的遍历就能搞定了）
- 字符和数字的转化（妈蛋，这里面得用个啥stream捣来捣去的，还不能直接强制转换）
- 字符0和9的跳转（妈蛋，其他语言里面-1%10 明明就能跳转成9的，C++偏偏不行）

我的代码应该是能通过任何测试的，主要修复了一个小问题，题目虽然没有说，但是从运行结果来看，是不允许target出现在deadends里的
然而，我认为在实际情况中这种情况也很有可能发生，所以考虑了别的代码中没有考虑的因素，在target被包括在deadends里的时候依然输出合理的结果

至于细节的解释，大家自己先看吧，有时间我再补上

```
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int step = 0;
        unordered_set<string> deadset(deadends.begin(), deadends.end());
        queue <string> tree;
        tree.push("0000");
        
        unordered_set<string> visited;
        visited.insert("0000");
        
        if(deadset.find("0000") != deadset.end() ){
            return -1;
        }
        
        while(!tree.empty()){
            int n = tree.size();
            
            for (int k = 0; k < n; k++) {   
                string cur = tree.front();
                tree.pop();
                
                if( cur == target){
                    return step;
                }
                
                for(int i =0; i<4; i++){
                    
                    stringstream stream;
                    stream.clear();
                    int nn = 0;
                    string candidate_1 = cur;
                    stream << candidate_1[i];
                    stream >> nn;
                    nn = (nn +1)%10;
                    
                    stream.clear();
                    stream << nn;
                    stream >> candidate_1[i];
                    
                    if( (deadset.find(candidate_1) == deadset.end() && visited.find(candidate_1) == visited.end()) 
                        || candidate_1 == target){
                        tree.push(candidate_1);
                        visited.insert(candidate_1);
                    }
                    
                    stream.clear();
                    string candidate_2 = cur;
                    stream << candidate_2[i];
                    stream >> nn;
                    nn = (nn - 1)%10;
                    if(nn < 0){
                        nn = 10 + nn;
                    }
                    
                    stream.clear();
                    stream << nn;
                    stream >> candidate_2[i];
        
                    if( (deadset.find(candidate_2) == deadset.end() && visited.find(candidate_2) == visited.end() )
                      || candidate_2 == target){
                        tree.push(candidate_2);
                        visited.insert(candidate_2);
                    }
                }
            }
            step += 1;
        }
        return -1;
    }
};


```
