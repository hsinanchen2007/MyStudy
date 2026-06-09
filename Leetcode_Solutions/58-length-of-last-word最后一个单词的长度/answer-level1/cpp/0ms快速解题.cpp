    int lengthOfLastWord(string s) {
        
        //bool first=false;
        int num=0;
        char sp(' ');
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=sp)
            {
                num++;
                //first=true;
            }
            else
            {
                if(num/*first*/)
                    break;
                continue;
                
            };
        }
        return num;
    }
要点：
1.从后往前判断
2.<1>若不是空格，计数；
  <2>若是空格
     1）计数还未开始（num=0），说明是第一段空格，continue;（如[a   ]）
     2) 已经计过数了（num!=0），说明是第二段空格,break;(如[a  b  ])
    