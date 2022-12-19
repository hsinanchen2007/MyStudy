分成两种情况处理: 1）将word[i]转化为数字缩写；2）保留word[i]。
```java

class Solution {
    List<String>list;
    String word;
    public List<String> generateAbbreviations(String word) {
        this.word=word;
        list=new ArrayList<>();
        dfs(0,"",0);
        return list;
    }
    public void dfs(int length,String s,int now)
    {
        if(length==word.length())
        {
            //最后还有数字要加上
            if(now!=0)
            {
                s=s+now;
            }
            list.add(s);
            return;
        }
        
        //不保留word.charAt(length)
       dfs(length+1,s,now+1);
         //保留word.charAt(length)
        dfs(length+1,s+(now==0?"":now)+word.charAt(length),0);
       
    }
}
```