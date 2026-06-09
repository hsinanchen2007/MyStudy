其实这道题没有特别的算法难度，主要读懂题，理清了条件分支就OK

根据题意这道题的标签触发条件就'<'，就帮助排除了"A < B"这种特殊情况出现。

然后除了CDATA以外的标签，必须是有闭合结尾，也简化掉了HTML标签中自闭和的问题。

所以单向逐字符遍历即可

遇到'<'字符后有三个状态分支
1. 后面是'!',那么判断是否是CDATA标签开头
   + 如果不是，直接返回false
   + 如果是，将遍历游标直接去寻找结尾标记
      - 如果找到了，则继续后续判断
      - 如果找不到，则返回false
2. 后面是其他字符
   + 如果是'/'，且满足条件的则是闭合标签
      - 将堆栈顶部标记出栈，然后于找到的闭合TagName比较，不一样则直接返回false
   + 如果其他满足条件的是开始标签
      - 将找到的TagName压入堆栈


```C#
public class Solution {
    
    private const string CDATA_START = "<![CDATA[";
    private const string CDATA_END = "]]>";
    
    public bool IsValid(string code) {
        if(code.Length < 3 || code[0] != '<' || code[1] == '!') return false;
        
        Stack<string> TagStack = new Stack<string>();
        var pointer = 0;
        
        bool FindTag(out string TagName, out bool isClose)
        {
            isClose = false;
            TagName = string.Empty;
            StringBuilder tagname = new StringBuilder();
            if(code[pointer] == '/'){ isClose = true; ++pointer; }
            
            while (code[pointer] != '>')
            {
                int chr = (int)code[pointer++];
                if(65 > chr || chr > 90 || tagname.Length >= 9 || pointer >= code.Length)
                    return false;
                tagname.Append((char)chr);
            }
            ++pointer;
            TagName = tagname.ToString();
            return TagName.Length > 0;
        }
        
        while(pointer < code.Length)
        {
            if(code[pointer] == '<')
            {
                //发现标签开头
                if(code[pointer + 1] == '!')
                {
                    if(pointer >= code.Length - CDATA_START.Length || code.Substring(pointer, CDATA_START.Length) != CDATA_START) return false;
                    pointer += CDATA_START.Length;
                    while(pointer < code.Length - 3)
                    {
                        if(code[pointer] == ']' && code.Substring(pointer, CDATA_END.Length) == CDATA_END)
                        {
                            pointer += CDATA_END.Length; break;
                        }
                        ++pointer;
                    }
                }
                else
                {
                    //尝试抓取标签
                    ++pointer;
                    
                    var isFound = true;
                    var isClose = false;
                    StringBuilder tagname = new StringBuilder();
                    if(code[pointer] == '/'){ isClose = true; ++pointer; }

                    while (code[pointer] != '>')
                    {
                        int chr = (int)code[pointer++];
                        if(65 > chr || chr > 90 || tagname.Length >= 9 || pointer >= code.Length)
                        {
                            isFound = false;
                            break;
                        }
                        tagname.Append((char)chr);
                    }
                    ++pointer;
                    var TagName = tagname.ToString();
                    
                    if(TagName.Length == 0) isFound = false;
                    
                    if(isFound)
                    {
                        if(isClose)
                        {
                            if(TagStack.Count == 0 || TagStack.Pop() != TagName) return false;
                            if(TagStack.Count == 0 && code.Length > pointer) return false;
                        }
                        else
                           TagStack.Push(TagName); 
                    }
                    else
                    {
                         //无法正常找到标签
                        return false;
                    }
                }
            }
            else
                ++pointer;
        }
        
        return TagStack.Count == 0;
    }
}
```

耗时 84 ms
内存消耗 21.4 MB