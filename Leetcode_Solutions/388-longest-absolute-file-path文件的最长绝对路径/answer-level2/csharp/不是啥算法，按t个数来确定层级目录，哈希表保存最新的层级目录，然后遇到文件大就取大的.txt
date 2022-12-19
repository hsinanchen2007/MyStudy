![1.png](https://pic.leetcode-cn.com/1f25ccd66226238ce36358c483ff317618bca8a3da605a12019d489dda499091-1.png)



public static int LengthLongestPath(string input)
        {
            int maxreturn = 0;
            string tempstr = ""; int level = 0;
            Dictionary<int, string> diclastdir = new Dictionary<int, string>();//追踪上一层目录
            input += "\n";//好处理
            for (int i = 0; i < input.Length;i++)
            {
                if(input[i]=='\n')
                {
                    if (tempstr.Contains(".")==false) //dir
                    {
                        if (diclastdir.ContainsKey(level) == false)
                            diclastdir.Add(level, tempstr);
                        else
                            diclastdir[level] = tempstr;
                        tempstr = "";
                        level = 0;
                    }
                    else //file
                    {
                        string filename = "";
                        foreach(var item in diclastdir)
                        {
                            if (item.Key < level)
                                filename += diclastdir[item.Key] + "/";
                            else
                                break;
                        }
                        filename += tempstr;
                        tempstr = "";
                        level = 0;
                        maxreturn = Math.Max(maxreturn, filename.Length);
                    }
                }
                else
                {
                    if (input[i] == '\t')
                        level += 1;
                    else
                        tempstr += input[i];
                }
            }
            return maxreturn;
        }