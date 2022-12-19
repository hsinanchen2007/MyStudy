- 这道题比较难，给出两种思路

1. 依次判断法。
- 这种思路很好理解，我们从s串中p.length位置，开始往回判断，每有一个成功匹配，则从备份p的stringbuilder内删去一个值，若全部成功匹配，则输出（起始下标-length+1）；
- 若中途有值未在从备份p的stringbuilder中找到，则继续循环，判断下一位，恢复备份p的stringbuilder

- 这种方法很好理解，但对于复用的串，多了很多次重复判断

代码后期补上！


2. 类KMP算法
- 类似于寻找字符串子串的KMP算法
- 我们从首到尾依次判断，每有一个成功匹配，则从备份p的stringbuilder内删去一个值，counter++

- ！！ 若： 某字符未匹配成功，且该字符不在p串内，重置备份p的stringbuilder，重置counter，继续判断
- ！！ 若： 某字符未匹配成功，但该字符在p串内，则将p.length长度内，第一位成功判断并删去的值重新恢复至stringbuilder内，重新判断这一位，counter--
- ！！ 若： counter==p.length 判断成功，写入输出列表。并：将p.length长度内，第一位成功判断并删去的值重新恢复至stringbuilder内，counter--

```
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int slength = s.length();
        int plength = p.length();
        int conter = 0;
        StringBuilder sb = new StringBuilder(p);
        
        List<Integer> result = new ArrayList();
               
        for(int i=0; i<slength; i++)
        {     
            if(sb.indexOf(Character.toString(s.charAt(i))) != -1)
            {
                conter++;
                sb.delete(sb.indexOf(Character.toString(s.charAt(i))), sb.indexOf(Character.toString(s.charAt(i)))+1);
            }
            else
            {
                if(p.indexOf(Character.toString(s.charAt(i))) != -1)
                {
                    conter--;
                    i--;
                    sb.append(s.charAt(i-conter));
                }
                else
                {
                    conter = 0;
                    sb =  new StringBuilder(p);
                }              
            }
            
            
            if(conter == plength)
            {
                result.add(i-plength+1);
                conter--;
                sb.append(s.charAt(i-plength+1));
            }        
        }
        return result;
        
        
    }
}
```
