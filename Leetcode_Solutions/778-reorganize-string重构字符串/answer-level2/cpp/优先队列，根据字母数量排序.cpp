1. 记录每个字母在字符串中的数量（哈希表）
2. 根据字母数量降序排序（插入优先队列，以字母数量较大优先级较高，类似于大顶堆）
3. 若队列顶部字母的数量大于一半则无法构造，直接返回空字符串（奇偶有别）
4. 按照字母数量降序顺序，当队列不空时，依次按照对顶元素，隔着往原字符串插入当前字符，下标从 $0$ 开始，每次插入下标 $+2$，当超过数组大小时，变为 $1$。

```cpp
class Solution {
    struct elm{
        char alp;
        int cnt;
        friend bool operator <(elm a,elm b){
            return a.cnt<b.cnt;
        }
    };
public:
    string reorganizeString(string S) {
        priority_queue<elm> q;
        unordered_map<char,int> mp;

        for(auto s:S)mp[s]++;
        for(auto p:mp){
            elm t;
            t.alp=p.first;
            t.cnt=p.second;
            q.push(t);
        }

        int i=q.top().cnt;
        if(S.size()%2&&i>S.size()/2+1)return "";
        if(S.size()%2==0&&i>S.size()/2)return "";
        i=0;
        while(!q.empty()){
            char t=q.top().alp;
            int k=q.top().cnt;
            while(k--){
                if(i>=S.size())i=1;
                S[i]=t;
                i+=2;
            }
            q.pop();
        }
        return S;
    }
};
```
