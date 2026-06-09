# 解答
这道题与字符串匹配类似，但也有不同点。

其不同点在于：需要匹配的长度不一样。字符串匹配的单位为字符，而该题需要匹配的是一个字符串。

给出我的方法：

首先为了匹配方便，将 words 中字符串用 map<string, int> 保存。

接着思考关于匹配的问题：什么情况下才算是串联完成了呢？答案：map 中的字符串均被匹配过一次。

有了上述考虑，我们开始遍历数组，对于每一个元素均考察其是否能被串联完成。

代码：
```cpp
class Solution {
public:
    vector<int> res;
    
    void match( string& s, map<string, int>& temp, int& begin, const int& word_len){

        for( int i = begin; i < s.size(); ){
            
            if( temp.size() == 0){
                res.push_back( begin);
                begin++;
                return ;
            }

            string now = s.substr( i, word_len);
           
            if( temp.find( now) != temp.end()){
                temp[now]--, i += word_len;
                if( temp[now] == 0)
                    temp.erase(now);
            }
            else{
                begin++;
                return ;
            }
        }
    
        if( temp.size() == 0){
            res.push_back( begin);
            begin++;
        }

        return ;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        if( words.size() == 0)
            return res;

        //为了方便查询, 将所有的单词放到一个字典中
        map<string, int> record, temp;
        for( auto it : words)
            record[it]++;

        int word_len = (*record.begin()).first.size();   //长度均相同

        for( int i = 0; i <= int(s.size() - words.size() * word_len); ){
            temp = record;	//此处可以通过双指针的方法进行优化
            match( s, temp, i, word_len);
        }

        return res;
    }
};
```

以上代码确实可以 AC, 但运行时间并不理想，因此可以存在优化方案。
