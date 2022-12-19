- 用并查集把同一类的名字按字典序并在一起，再把属于同一根节点的频率加到根节点

```cpp
class Solution {
public:
    unordered_map<string,string>father;
    unordered_map<string,int>hash;
    unordered_map<string,int>root;
    string find(string x){
        if(father.find(x)==father.end()){
            father[x]=x;
            hash[x]=0;
            return x;
        }
        return x==father[x] ? x : find(father[x]);
    }
    void merge(string &fx,string &fy){
        if(fx<fy)father[fy] = fx;
        else father[fx] = fy;
    }
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        int n = names.size(),m = synonyms.size(),j;
        vector<string>res;
        if(!n)return res;
        for(int i=0;i<n;++i){
            string str = names[i],name="",num="";
            j=0;
            while(str[j]!='(')name+=names[i][j++];
            j++;
            while(str[j]!=')')num+=str[j++];
            hash[name]=stoi(num);
            father[name] = name;  //初始化并查集
        }
        for(int i=0;i<m;++i){
            j=1;
            string name1="",name2="";
            while(synonyms[i][j]!=',')name1+=synonyms[i][j++];
            j++;
            while(synonyms[i][j]!=')')name2+=synonyms[i][j++];
            string fx = find(name1),fy = find(name2);
            if(fx != fy)
                merge(fx,fy);
        }
        for(auto c=father.begin();c!=father.end();c++){
            root[find(c->first)]+=hash[c->first];
        }
        for(auto c=root.begin();c!=root.end();c++){
            string ans = c->first + '(' + to_string(c->second) + ')';
            res.push_back(ans);
        }
        return res;
    }
};
```