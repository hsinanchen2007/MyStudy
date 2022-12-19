1. 先将数字日志和字母日志分离，数字日志存入新的vector顺序不变
2. 对于字母日志使用map存储，key的类型使用pair<string,string>（或自定义类型info）,分别为pair<标识符，剩余字符>，value=整条日志
3. 若key使用自定义类型info则必须重载info的operator<;若key使用了pair则必须自定义比较规则，采用仿函数。
4. 按倒序（map已排序）将字幕日志前插入数字日志
```
class PointCmp{
public:
    bool operator()(pair<string,string const &s1,pair<string,string> const &s2)const
    {
        if(s1.first==s2.first)
            return s1.second<s2.second;
        return s1.first<s2.first;
    }
};
class info{
public:
        info(string x,string y)
        {
            s1=x,s2=y;
        }
        bool operator<(info const& _A)const
        {
            if(s1==_A.s1)
                return s2<_A.s2;
            return s1<_A.s1;
        }
        string s1;
        string s2;
};
class Solution{
public:
    vector<string> reorderLogFiles(vector<string>& logs){
        vector<string> temp;
      //map<info,string> com;
        map<pair<string,string>,string,PointCmp> com;
        for(auto i:logs)
        {
            int pos=i.find(" ")+1;
            string tag;
            string tag2;
            if(i[pos]<'a')
                temp.push_back(i);
            else
            {
                tag=i.substr(pos,i.size()-pos);
                tag2=i.substr(0,pos-1);
              //info in(tag,tag2);
                pair<string,string> in(tag,tag2);
                com[in]=i;
            }
        }
        for(auto it=com.rbegin();it!=com.rend();it++)
            temp.insert(temp.begin(),it->second);
        return temp;
    }
};
```
