![1.png](https://pic.leetcode-cn.com/84afc06d8baf2e90964279e116404d2a92d0887fdfb163bae469958d05e9715f-1.png)
估计没人提交C#。。。

public static IList<string> FullJustify(string[] words, int maxWidth)
        {
            List<string> list = new List<string>();
            int lastselect=0;//记录上次选到哪一个位置
            int i = 0;
            while (i < words.Length)
            {
                string foradd = "";
                for (i = lastselect; i < words.Length; i++)
                {
                    //题意要求单词间要有空格
                    if (foradd.Length + words[i].Length + 1 <= maxWidth)
                    {
                        foradd += words[i] + " ";
                    }
                    else if (foradd.Length + words[i].Length == maxWidth)
                    {//最后一个单词可以不加空格组成正好max个也是符合要求的
                        foradd += words[i];
                    }
                    else
                    {//加不了当前这个单词的话就记录没加的这个位置
                        list.Add(MaketoMaxWidth(foradd, false, maxWidth));
                        lastselect = i;
                        break;
                    }
                    if (i == words.Length - 1)
                    {
                        list.Add(MaketoMaxWidth(foradd, true, maxWidth)); 
                    }
                }
            }
            return list;
        }
        //重新编排这行，使得达到max个字符
        private static string MaketoMaxWidth(string foradd,bool islast,int maxWidth)
        {
            //正好max个且最后一个不是空格那就不需要处理
          if(foradd.Length==maxWidth && Char.IsWhiteSpace(foradd,maxWidth-1)==false)  return foradd;
          else if (foradd.Length == maxWidth && Char.IsWhiteSpace(foradd, maxWidth-1))
          {//正好max个字符且最后一个字符是空格
              if(islast==false)//如果是最后一行那么就左对齐不需要处理,其他行不止一个单词的需要变成左右对齐
              {
                  string[] strarr = foradd.Split(new string[] { " " }, StringSplitOptions.RemoveEmptyEntries);
                  if (strarr.Length>1)//一个单词的不需要处理
                        foradd = foradd.Insert(foradd.IndexOf(" "), " ").TrimEnd(new char[] { ' ' });
              }
          }
          else
          {
              if(islast)//直接在最后面补齐空格,因为最后一行左对齐
              {
                  int templength = foradd.Length;
                  for (int i = 0; i < maxWidth - templength; i++)
                      foradd += " ";
              }
              else
              {
                  string[] strarr = foradd.Split(new string[] {" "}, StringSplitOptions.RemoveEmptyEntries);
                  if (strarr.Length > 1)
                  {     //计算字符数，空格数，做出一个尽量平均的空格数组，然后添加到字符中
                      int letterlen = strarr.Sum(p => p.Length);
                      string[] spacearr = GenerateSpaceArr(maxWidth-letterlen, strarr.Length - 1);
                      foradd = "";
                      for(int i=0;i<strarr.Length;i++)
                      {
                          if (i != strarr.Length - 1)
                              foradd += strarr[i] + spacearr[i];
                          else
                              foradd += strarr[i];
                      }
                  }
                  else//不是最后一行且只有一个单词的也是直接在后面补齐
                  {
                      int templength = foradd.Length;
                      for (int i = 0; i < maxWidth - templength; i++)
                          foradd += " ";
                  }
              }
          }
          return foradd;
        }

        private static string[] GenerateSpaceArr(int spacelen, int arrlen)
        {
           string[] spacearr = new string[arrlen];
           int yushu = spacelen % arrlen;
           for (int i = 0; i < arrlen;i++)
           {
               for (int j = 0; j < spacelen / arrlen; j++)
                   spacearr[i] += " ";
               if(yushu>0)
               {
                   spacearr[i] += " ";
                   yushu--;
               }
           }
           return spacearr;
        }