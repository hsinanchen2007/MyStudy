
第一步：
模式串当前位置p1为大写字母时，查询项位置p2如果与模式串p1位置相同，p1,p2均向后移动。
模式串当前位置p1为大写字母时，查询项位置p2如果与模式串p1位置不同，分为两种情况：
    1、查询项p2位置为大写字母，匹配失败返回false
    2、查询项p2位置为小写字母，跳过该位置，即p2向后移动。


模式串当前位置p1为小写字母时，查询项位置p2如果与模式串p1位置相同，p1,p2均向后移动。
模式串当前位置p1为小写字母时，查询项位置p2如果与模式串p1位置不同，分为两种情况：
    1、查询项p2位置为大写字母，匹配失败返回false
    2、查询项p2位置为小写字母，跳过该位置，即p2向后移动。

第二步：
若模式串匹配完成,而查询项没匹配完成，即p1==pattern.length() p2<query.length()
如果查询项剩下部分都是小写字母则返回true
否则返回false

若模式串没有匹配完成,而查询项匹配完成，即p1<pattern.length() p2==query.length()
返回false
```
class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> res=new ArrayList(queries.length);
        char[] pat=pattern.toCharArray();
        for(String temp:queries)
            res.add(judge(temp,pat));
        return res;
    }
    private boolean judge(String temp,char[] pat){
        int p1=0,p2=0;
        while(p1<temp.length()&&p2<pat.length){
            if(pat[p2]<='z'&&pat[p2]>='a'){//都为小写
                if(temp.charAt(p1)==pat[p2]){
                    p1++;
                    p2++;
                }else if(temp.charAt(p1)<='z'&&temp.charAt(p1)>='a')
                    p1++;
                else
                    return false;
            }else{//都为大写
                if(temp.charAt(p1)==pat[p2]){
                    p1++;
                    p2++;
                }else if(temp.charAt(p1)>='A'&&temp.charAt(p1)<='Z')
                    return false;
                else
                    p1++;
            }
        }
        if(p2!=pat.length)
            return false;
        while(p1<temp.length())
            if(temp.charAt(p1)>='A'&&temp.charAt(p1)<='Z')
                return false;
            else
                p1++;
        return true;
    }
}
```
可以给上面代码化简一下
```
class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> res=new ArrayList(queries.length);
        char[] pat=pattern.toCharArray();
        for(String temp:queries)
            res.add(judge(temp,pat));
        return res;
    }
    private boolean judge(String temp,char[] pat){
        int p1=0,p2=0;
        while(p1<temp.length()&&p2<pat.length)
            if(temp.charAt(p1)==pat[p2]){
                p1++;
                p2++;
            }else if(temp.charAt(p1)<='z'&&temp.charAt(p1)>='a'){
                p1++;
            }else{
                return false;
            }
        
        if(p2!=pat.length)
            return false;
        
        while(p1<temp.length())
            if(temp.charAt(p1)>='A'&&temp.charAt(p1)<='Z')
                return false;
            else
                p1++;
        return true;
    }
}
```

