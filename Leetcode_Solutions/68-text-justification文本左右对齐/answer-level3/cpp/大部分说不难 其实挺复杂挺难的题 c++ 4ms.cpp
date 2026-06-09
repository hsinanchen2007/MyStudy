第一步： 确定一行能放多少的单词  如果放进去超出了 那么就再把这个单词弹出来
        有兴趣的观众可以尝试用回朔的方式往里面添加单词
第二步： 插入空格 按照 “ ”+单词 的队列顺序往里面插入 空格的数量用到了 % 和 / （注意0的情况） 
        请注意 如果是最后一行 那么插入的规则和上面是不一样的
        请注意 如果每行只有一个单词 那么插入的规则也是和上面不一样的 
        单独讨论两种情况就好了 
小提示：我们可以用* # @来代替空格方便调试～
```     
/*文本对齐 */
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string>res;
    string::size_type i=0;
    while(i<words.size()){
        string::size_type wordRowNums=0,wordRowSpace=0,numsize=1;
/*确定了一行有多少个单词*/
        while(true){
            auto buf = wordRowNums;
            wordRowNums+=words[i].size();
            wordRowSpace = wordRowSpace+words[i].size()+1;
            if(wordRowSpace==maxWidth||wordRowSpace-1==maxWidth) break;
            else if(wordRowSpace>maxWidth){
                wordRowNums=buf;
                --i;--numsize;
                break;
            }
            else if(i==words.size()-1) break;
            ++i;++numsize;
        }
/*确定了当前行的单词书 numsize 当前最后一个单词 i  插入空格 */
        auto left = i-numsize+1;    //当前行的第一个单词的位置
        auto space = maxWidth-wordRowNums;      //当前行需要的空格数量
        cout<<space<<endl;
        int n=0,j=0;
        if(numsize==1)
            n=space;
        else{
            n=space/(numsize-1);
            j=space%(numsize-1);
        }
        if(i!=words.size()-1){      //如果不是最后一行的话
            string buf(words[left]);    //放入行的第一个单词
            if(numsize==1)  for(int g=0;g<n;++g) buf+=" ";
            for(int l=1;l<numsize;++l,--j){    //放入l对  “ ”+单词
                if(j>0)                     //先插入空格 j>0代表插入n+1个空格
                     for(int g=0;g<n+1;++g)  buf+=" ";
                else for(int g=0;g<n  ;++g)    buf+=" ";
                buf+=words[left+l];         //插入后缀单词
            }
            res.push_back(buf);             //buf行构造完毕以后 插入y这一行
        }
        else{                     //如果是最后一行的哈
            string buf(words[left]);
            auto sumsEnd=words[left].size();
            for(int l=1;l<numsize;++l) {
                buf=buf+" "+words[left+l];
                sumsEnd=sumsEnd+1+words[left+l].size();
            }
            for(auto i=0;i<maxWidth-sumsEnd;++i)
                buf+=" ";
            res.push_back(buf);
        }
/**/
        ++i;
    }
    return res;
}
```
