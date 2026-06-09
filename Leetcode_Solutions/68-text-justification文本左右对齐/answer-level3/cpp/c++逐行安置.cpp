#### 逐行安置
循环安置每一行，空格计数用ceil()向上取整
~~~c++ []
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        string tmp="";
        int i=0,j=0,n=words.size();//words索引i,行单词索引j
        while(1){
            //count行单词计数,len子串长,space剩余空白空间,span空格长
            int count=0,len=0,space=0,span=0;
            while(len<maxWidth && j<n)//尝试子串长度len,默认加1空格
               len += words[j++].size()+1;
            if(len-1>maxWidth)//矫正len长度
                len -= words[--j].size()+1;
            count = j-i;//行单词计数
            space = maxWidth-len+count;//空白空间计算           
            //填充一行
            for(int k=i;k<j;k++,count--,space-=span){
                if(j==n)//计算span长度，最后一行
                    span=count<2?space:1;//最后一行左对齐,空格长1
                else//其他行span//ceil(x)向上取整,参数x为float等级以上
                    span=count<2?space:ceil(space/(count-1.0)); //count-1,排除最后一个单词再相除           
                tmp = tmp + words[k]; //填充单词
                if(space>=0) //填充空格
                    tmp = tmp + string(span,' ');            
            }
            if(space>0)//处理最后一行填充不完的情况
                tmp = tmp + string(space,' ');
            res.push_back(tmp);//res
            //开始下一行
            if(j==n) //exit
                break;
            tmp="";//初始化tmp
            i=j;//一行处理完毕，更新i 
        }
        return res;
    }
~~~