       //遍历单词，记录遇到单词的id号码，更新两个单词之间的距离，返回最小的一个 
        int count=0,res=words.size();
        int i=0,j=0;
        for(auto str:words){
            if(str==word1) i=count;
            if(str==word2) j=count;
            count++;
            if(i!=0&&j!=0){
                res=abs(i-j)<res?abs(i-j):res;
                
            }

        }
        return res;