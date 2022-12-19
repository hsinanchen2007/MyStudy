### 解题思路
此处撰写解题思路
1.先对字符串按字符串长度进行降序排序；
2.使用一个字符串cur记录当前加入进来的字符；
3.对降序后的字符串逐一进行判断，看是否是某个已经加入的字符串后缀；
    3.1：若是后缀，则不做处理
    3.2：若不是后缀，则在cur字符串中加入当前判断的字符串并以#结尾；
4.返回处理后的cur长度即可；
### 代码

```cpp
class Solution {
public:
    static bool mysort(string a,string b)
    {
        return a.size()>b.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),mysort);
        string cur;
        for(int i=0;i<words.size();i++){ 
            size_t pos=cur.find(words[i]);
            if(pos==string::npos||cur[pos+words[i].size()]!='#')
                cur+=(words[i]+='#');
        }
            return cur.size();
    }
    
};
```