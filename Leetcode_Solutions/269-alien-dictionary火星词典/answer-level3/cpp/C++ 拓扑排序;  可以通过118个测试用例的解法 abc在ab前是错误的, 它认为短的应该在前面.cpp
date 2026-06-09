``` c++
class Solution {
public:
    string alienOrder(vector<string>& words) {
        // 整体的思想就是拓扑排序
            // 我们抽象出来的关系是大于关系, 我们最后要看根据这个大于关系, 我们能不能生成一个合理的顺序
            // 特别坑爹地是, abc 和 ab是错误的直接返回", 因为abc的长度是3, 比ab的长度大, 所以必须在abc的后面

        int indegree[26], len=0; // 记录入度, 单词表涉及多少个字符
        for(int i=0;i<26; ++i)
            indegree[i]=-1; // 入度为-1 表示这个字符没有出现过
        
        for(int i=0;i<words.size(); ++i){ // 把出现的字符入度设为0
            for(int j=0; j<words[i].size(); ++j){
                indegree[words[i][j]-'a']=0;
            }              
        }
        
        for(int i=0;i<26; ++i) // 统计一共有多少个字符
            if(indegree[i]==0)
                ++len;

        vector<unordered_set<char>>  m(26,unordered_set<char>()); // 有向图的邻接表, 我们比较前后相邻的两个单词, 来获得字符之间的关系
            // 之所以用unordered_set<char>是因为可能多次出现比如a>b, 要防止反复地插入
        for(int i=0;i<words.size()-1; ++i){
            int j;
            for(j=0; j<words[i].size() && j<words[i+1].size(); ++j){
                if(words[i][j]==words[i+1][j]){ // 字符相等, 继续看
                    continue;
                }    
                else{ // 字符不等, 说明出现了大于的关系, 记录下来
                    m[words[i][j]-'a'].insert(words[i+1][j]);
                    break; // 后面不用看了
                }
            }
            // 这个就是为了克服abc和ab的问题, 也就是两个字符串前面的部分完全相等(所以在上面的循环结束后j==words[i+1].size()), 但是长的在前面, 短的在后面, 这样是错误的. 直接返回""
            if(j==words[i+1].size() && words[i].size()>words[i+1].size())
                return ""; 
        }

   
        // 接下来就是统计入度
        for(int i=0;i<26;++i){
            for(auto& c:m[i]){
                ++indegree[c-'a'];
            }          
        }


        queue<char> que;
        string res="";
        for(int i=0;i<26;++i){ // 把入度为0的结点加入到队列里
            if(indegree[i]==0){
                char c='a'+i;
                que.push(c);
            }    
        }

        while(!que.empty()){
            char c=que.front();
            res+=c; // 添加到字符串
            que.pop();
            for(auto s: m[c-'a']){ 
                --indegree[s-'a'];
                if(indegree[s-'a']==0) // 如果这个字符变成0了, 添加到队列里
                    que.push(s);
            }
        }

        
        if(res.size()!=len) // 如果拓扑排序遍历了所有的字符, 说明有可行解; 否则的话说明不是有向无环图, 有环, 没有可行解
            return "";
        else 
            return res;
       
        
    }
};
```
