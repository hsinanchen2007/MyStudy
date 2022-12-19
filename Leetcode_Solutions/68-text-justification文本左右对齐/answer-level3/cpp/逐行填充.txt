这道题看起来复杂，实际上并不太困难，读懂题目很重要。

按照题目要求，逐行填充的单词和空格即可。

几个要点：1. 每行的空格如何分配？2. 最后一行单独处理；3. 若一行内只能容纳一个单词，应该单独填充后面的空格。


代码：
```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for( int i = 0; i < words.size(); ){
            string record;//记录当前行的字符
            
            int j = i;
            //确定每行分配的单词数
            for( int count = 0 ; j < words.size(); j++){
                //count 表示加上空格后需要的最少字符
                count += words[j].size() + 1;
                if( count == maxWidth + 1)
                    break;
                else if( count > maxWidth + 1){
                    j--, count -= words[j].size() + 1;
                    break;
                }
                else
                    continue;
            }

            //头部第一个单词
            record += words[i++];
            //若已经到达了最后一行，则单独处理
            if( j == words.size()){
                for( i; i < j; i++)
                    record += ' ', record += words[i];
                while( record.size() < maxWidth)
                    record += ' ';
                    
                res.push_back( record);
                break;
            }
            
            //除了放置在头部的单词，还剩下 count_words 个单词
            int count_words = j - i + 1;

            //统计有效的空格数
            int count_space = 0;
            for( int k = i; k <= j && k < words.size(); k++)
                count_space += words[k].size();
            count_space = maxWidth - count_space - record.size();
            
            while( count_space && count_words){
                int temp; //每个单词最多分到的空格数字
                if( count_space % count_words == 0)
                    temp = count_space / count_words;
                else
                    temp = count_space / count_words + 1;
                
                for( int k = temp; k > 0; k--)
                    record += ' ';
                
                record += words[i++], count_space -= temp, count_words--;
            }
            //若每行只有一个单词，则需要在尾部进行填充空格
            while( record.size() < maxWidth)
                record += ' ';
            
            res.push_back( record);
        }
        
        return res;
    }
};
```