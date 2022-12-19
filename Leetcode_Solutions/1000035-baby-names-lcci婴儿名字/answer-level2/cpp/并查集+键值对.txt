显而易见，此题是并查集。在进行并查集代码书写之前，我们需要一些简单的字符串处理
1.根据第一个vector得到每个新生儿名字及其个数
2.根据第二个vector得到可以合并的名字
代码如下：
```
    pair<string,int>process(string str){
        string name;
        int num=0,idx=0;
        while(idx<str.size()){
            if(str[idx]=='('){
                break;
            }
            name+=str[idx];
            idx++;
        }
        idx++;
        while(idx<str.size()){
            if(str[idx]==')'){
                break;
            }
            num*=10;
            num+=str[idx]-'0';
            idx++;
        }
        return {name,num};
    }
```
```
    pair<string,string>processSyn(string str){
        int idx=1;
        string first,second;
        while(str[idx]!=','){
            first+=str[idx];
            idx++;
        }
        idx++;
        while(str[idx]!=')'){
            second+=str[idx];
            idx++;
        }
        return {first,second};
    }
```
OK，在完成了名字的处理后，我们需要进行并查集。这时候直接上板子，但是思考下，字典序最小的名字作为真实名字。我们将这些可以看做重名的名字在合并时，注意将字典序小的当爹，字典序大的当儿子。对两个名字比较时，先找他们的爹，再比较两个名字的爹谁大谁小，小的继续当爹，这样保证顺序。
```
    int getfa(int x){
        if(x!=fa[x]){
            fa[x]=getfa(fa[x]);
        }
        return fa[x];
    }
    void unionXY(string s1,string s2){
        int x=getfa(m1[s1]);
        int y=getfa(m1[s2]);
        if(m3[x]>m3[y]){//m3[y]小，则y当x的爹
            fa[x]=y;
        }
        else{
            fa[y]=x;
        }
    }
```
由于这里面是都是string，我用了三个键值对去保存信息：
```
    map<string,int>m1;      //根据名字获得序号
    map<int,int>m2;         //根据序号获得名字个数
    map<int,string>m3;      //根据序号获得名字
```
总体来说，本题不算难，但是比较麻烦，还要字符串处理，键值对保存杂七杂八的。优化空间还很大，大佬可以继续优化下：
总体代码如下：
```
//并查集
class Solution {
public:
    vector<int>fa;
    map<string,int>m1;//以str代表序列
    map<int,int>m2;//以str表示个数
    map<int,string>m3;//以序列寻找idx
    int getfa(int x){
        if(x!=fa[x]){
            fa[x]=getfa(fa[x]);
        }
        return fa[x];
    }
    void unionXY(string s1,string s2){
        int x=getfa(m1[s1]);
        int y=getfa(m1[s2]);
        if(m3[x]>m3[y]){
            fa[x]=y;
        }
        else{
            fa[y]=x;
        }
    }
    pair<string,int>process(string str){
        string name;
        int num=0,idx=0;
        while(idx<str.size()){
            if(str[idx]=='('){
                break;
            }
            name+=str[idx];
            idx++;
        }
        idx++;
        while(idx<str.size()){
            if(str[idx]==')'){
                break;
            }
            num*=10;
            num+=str[idx]-'0';
            idx++;
        }
        return {name,num};
    }
    pair<string,string>processSyn(string str){
        int idx=1;
        string first,second;
        while(str[idx]!=','){
            first+=str[idx];
            idx++;
        }
        idx++;
        while(str[idx]!=')'){
            second+=str[idx];
            idx++;
        }
        return {first,second};
    }
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        int n=names.size();
        int idx=0;
        for(auto str:names){
            pair<string,int>t=process(str);
            m1[t.first]=idx;
            m2[idx]=t.second;
            m3[idx]=t.first;
            idx++;
        }
        fa.resize(n);
        for(int i=0;i<n;i++){
            fa[i]=i;
        }
        for(auto str:synonyms){
            pair<string,string>p=processSyn(str);
            unionXY(p.first,p.second);
        }
        vector<string>res;
        map<int,int>nums;//表示个数
        for(int i=0;i<n;i++){
            nums[getfa(i)]+=m2[i];
        }
        for(auto p:nums){
            string tmp=m3[p.first];
            tmp+='(';
            tmp+=to_string(p.second);
            tmp+=')';
            res.push_back(tmp);
        }
        return res;
    }
};
```



