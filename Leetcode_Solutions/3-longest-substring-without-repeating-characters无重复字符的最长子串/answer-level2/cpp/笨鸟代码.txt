 此处就以abcabcbb为例
代码思路过程
初始为：a
        abc  
        bca
        cab
        abc
        cb
        b

int lengthOfLongestSubstring(string s) {
  //自己尝试滑动窗口
  if(s.length()==0)//去除空字符串
  {
      return 0;
  }
    string str; 
    int pos=0;
    str=str+s[0];//初始窗口大小为1
    int max_size=1;//相应的此时的最大子列为1；
    for(int i=1;i<s.length();i++)
    {
        pos=str.find(s[i]);
        if(pos==-1)//增加窗口大小
        {
            str=str+s[i];
        max_size=max_size>str.length()?max_size:str.length();//得此时最大的子列
        }
        else
        {
            //out<<str<<"我不是啊 ";
            str.erase(0,pos+1);//删除重复元素之前的元素，减小窗口大小
            str=str+s[i];
        }
    }
    return max_size;
    }