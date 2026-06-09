```
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int sz = words.size();
        int words_num_one_line = 0;
        int words_len_one_line = 0;
        int i = 0, start = 0;
        while(i < sz){
            words_num_one_line++;
            words_len_one_line += words[i].size();
            // 若第i个单词装不到这一行了 
            if(words_len_one_line + words_num_one_line - 1 > maxWidth){
                //把从start到i-1的单词打包装好
                vector<string> words_one_line;
                for(int j = start; j < i; j++){
                    words_one_line.push_back(words[j]);
                }
                string str = AddSpace(words_one_line, maxWidth, 0, 0);
                res.push_back(str);
                // cout<<str<<endl;
                //初始化计数量
                start = i;
                words_num_one_line = 0;
                words_len_one_line = 0;
            }
            //若第i个单词这一行可以装下
            else{
                //到最后一行了
                if(i == sz-1){
                    vector<string> words_one_line;
                    for(int j = start; j <= i; j++){
                        words_one_line.push_back(words[j]);
                    }
                    string str = AddSpace(words_one_line, maxWidth, 1, 0);
                    res.push_back(str);
                    // cout<<str<<endl;
                }
                i++;
            }
        }
        // 函数测试
        // words_one_line.push_back("example");
        // words_one_line.push_back("of");
        // words_one_line.push_back("test");
        // string str = AddSpace(words_one_line, maxWidth, 0, 1);
        // cout<<str<<endl;
        return res;
    }

    // 打包一行单词
    string AddSpace(vector<string>& words, int maxWidth, bool is_last, bool test){
        string res;
        // 非空格字符所占长度
        int word_len = 0;
        //若为最后一行，或该行只有一个单词
        if(is_last || words.size() == 1){
            for(int i = 0; i < words.size(); i++){
                res += words[i];
                if(res.size() < maxWidth) res += " ";
            }
            while(res.size() < maxWidth) res += " ";
            return res;
        }
        // 其他情况
        // 统计非空格字符数量
        for(int i = 0; i < words.size(); i++){
            word_len += words[i].size();
        }
        // cout<<"word_len "<<word_len<<endl;
        int space_len = maxWidth - word_len;
        int space_num = words.size() - 1;
        // 分配单词之间的空格数量
        vector<string> space(space_num, "");
        int j = 0;
        while(space_len--){
            space[j % space_num] += test? ".": " ";
            j++;
        }
        //组装单词和空格
        for(int i = 0; i < space_num; i++){
            res += words[i];
            res += space[i];
        }
        res += words[space_num];
        // cout<<"res size"<<res.size()<<endl;
        return res;
    }
};
```
