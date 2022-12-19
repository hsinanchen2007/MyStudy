依次比对每一个单词相对于位置字母是否相同，与首单词相应位置比对，外循环是字符位置，内循环是每个单词
一旦发生不匹配跳出，记录最后匹配的字符位置，前几个放入一个字符串输出即可

最开始提交忘记了空串的情况，补上就好了
![QQ截图20200318224349.png](https://pic.leetcode-cn.com/40dc54530581a90366536c29e6a536892af7e56e927ad5f01b9c6186ee92872b-QQ%E6%88%AA%E5%9B%BE20200318224349.png)




char * longestCommonPrefix(char ** strs, int strsSize){
    // 依次提取每个单词的第i个字母，如果全部相同，加入字符串数组。
    //如果有不同 加入“\0”
    if (strsSize==1)    // only one word
    {
        return strs[0];
    }
    if (strsSize==0)
    {
        char *s1 = "";
        return s1;
    }
    
    int judge=0;  //用于判断是否到达前缀结束
    int i=0;
    for(i=0;strs[0][i]!='\0';i++)  // 前缀长度,i 记录前缀长度 i=1 即 前一个字符为最长前缀
    {
        char c ;
        c= strs[0][i];   //首单词第i个字母（0开始）

        for(int j=1;j<strsSize;j++)  //遍历其后每个单词
        {
            if(c!=strs[j][i])
            {
                judge =1;         //一旦不匹配，跳出
                break;
            }
        }
        if(judge==1) 
        {   
            break;         //利用判断是否已经不匹配，跳出大循环
        }

    }
    
    char *s = (char*)malloc(sizeof(char)*(i+1));
    for(int q=0;q<i;q++)
    {
        s[q]=strs[0][q];         //复制前i个字符到s
    }
    s[i]='\0';         //结尾
    return s;
  

}