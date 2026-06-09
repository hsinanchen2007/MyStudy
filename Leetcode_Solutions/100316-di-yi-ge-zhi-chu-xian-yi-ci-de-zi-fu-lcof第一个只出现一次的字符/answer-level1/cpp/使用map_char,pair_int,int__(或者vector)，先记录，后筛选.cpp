1、 记录pair<char,pair<数量，位置>>
2、 遍历map找到满足条件的pair<char,位置>

之前想过一些骚方法，比如怎么把map改造成按char来查找而按位置来排序，但是没有实现，希望大佬们多多指教

class Solution {
public:
    
    char firstUniqChar(string s) {
        //char 为索引，pair.first为出现次数，second为出现位置
        map<char,pair<int,int>> m;
        
        for(int i = 0;i<s.size();i++)
        {
            if(m.find(s[i])==m.end())
            {
                m.insert({s[i],{1,i}});
                continue;
            }
            m[s[i]].first++;
        }
        //用于记录位置最小的出现一次的字符
        pair<char,int> result({' ',INT_MAX});
        for(auto iter = m.begin();iter!=m.end();iter++)
        {
            if(iter->second.first == 1&&iter->second.second<result.second)
            {
                cout << "here"<<endl;
                result = {iter->first,iter->second.second};
            }
        }
        return result.first;
    }
};
