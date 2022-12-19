1. 按照字符出现顺序排序，所以要先遍历一遍统计字符出现次数，之后再按次数重新生成字符串
2. 第一次遍历，用map存储字符和次数的关系
3. 第二次遍历，map中的每一个元素是一个pair，把pair的first和second对调，就是把map的key和value对调
4. 对于对调后的每一个pair，存入一个新的vector，vector的结构是vector<pair<int,char>>
5. 对vector进行sort，此时sort会按照pair中第一个元素进行排序，这时就完成了出现频率排序的目的
6. 最后遍历vector，生成新的字符串
```
string frequencySort(string s) 
    {
        map<char,int> time;
        for(int i=0;i<s.length();i++)
            time[s[i]]++;
        map<char,int>::iterator it;
        vector<pair<int,char>> char_list = {};
        for(it=time.begin();it!=time.end();it++)
        {
            pair<int,char> resave;
            pair<char,int> temp = *it;
            resave.first = temp.second;
            resave.second = temp.first;
            char_list.push_back(resave);
        }
        sort(char_list.begin(),char_list.end());
        reverse(char_list.begin(),char_list.end());
        s = "";
        for(int i=0;i<char_list.size();i++)
            for(int j=0;j<char_list[i].first;j++)
                s += char_list[i].second;
        return s;
    }
```
1. 本来觉得使用了map，vector两个存储结构，会占用很多的内存
2. 但是结果显示内存超过100%，这就很奇怪了
3. 时间复杂度只超过了20%，应该是不断的转换存储结构消耗了太多的时间
