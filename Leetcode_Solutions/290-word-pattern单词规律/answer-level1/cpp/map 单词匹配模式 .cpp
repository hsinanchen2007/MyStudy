### 解题思路
大神的代码 自己加上注释和理解
abba
dog cat dog dog
1、通过找到空格的位置，来确定单词大小，str.substr读取字符串
2、第一次读入pattern时建立字典匹配模式，如a->dog,b-cat;
3、第二次读入相同的pattern时（dog），发现与之前的匹配模式不相等时，返回false；
4、通过set去重；

### 代码

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> lis1;
        int pos;
        int i=0; //i表示单词的位置
        while(pos!=-1)//读取str中的单词
        {
            pos=str.find_first_of(' ',i); //单词后出现空格的位置
            string temp=str.substr(i,pos-i); //pos-i 为单词大小，
            lis1.push_back(temp);
            i=pos+1;  //更新单词的位置
        }

        if(pattern.size()!=lis1.size()) 
            return false;
        map<char,string> h;
        for(int i=0;i<lis1.size();i++)
        {
            if(h.count(pattern[i])) //已出现的键值
            {
                if(h[pattern[i]]!=lis1[i]) //如果与之前的模式不匹配，返回false
                    return false;
            }
            else  
            {
                h.insert(map<char,string>::value_type(pattern[i],lis1[i])); //第一次出现键值就直接插入，建立匹配关系
            }
        }

        set<char> p(pattern.begin(),pattern.end());
        set<string> l(lis1.begin(),lis1.end()); 
        if(p.size()!=l.size())  //通过set去除重复，避免一对多的情况
            return false;
        return true;
    }
};


```