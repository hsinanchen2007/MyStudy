## 解题思路
定义双指针分别遍历query和pattern，看是否满足要求
## 代码
```
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res(queries.size());
        for(int i=0;i<queries.size();i++){
            string query = queries[i];
            int qidx=0,pidx=0;
            // 标志下面的while循环有没有得出结论
            bool visited=false;
            while(qidx<query.size()){
                // 去除当前pattern之前query中符合要求的字符
                while(query[qidx]>='a' && query[qidx]<='z' && pidx<pattern.size() && query[qidx]!=pattern[pidx]){
                    qidx++;
                }
                // 若存在不等于pattern的大写字母，则为false
                if(query[qidx]!=pattern[pidx]){
                    res[i]=false;
                    visited=true;
                    break;
                }else{
                    // 否则，自增
                    pidx++;
                    qidx++;
                }
                // 若pattern遍历完，则跳出循环
                if(pidx==pattern.size()){
                    break;
                }
            }
            // 若上述while中已得出结果，则遍历下一个query
            if(visited){
                continue;
            }
            // 若切合pattern所有元素后query中仍有部分字符串，则遍历完看是否都是小写字母
            while(qidx < query.size() && query[qidx]>='a' && query[qidx]<='z'){
                qidx++;
            }
            // 若qidx遍历完，则可匹配
            if(qidx==query.size()){
                res[i]=true;
            }else{
                // 否则，不可匹配
                res[i]=false;
            }
        }
        return res;
    }
};
```
