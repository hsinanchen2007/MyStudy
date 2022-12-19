题意:
将S中的字符串从后往前分组，长度为K，每组以'-'分隔；所以最终 1<=左边第一组长度<=K,中途将字符转为大 写即可。
代码实现:
首先StringBuilder对象res用于保存结果；count保存非'-'的字符数量；逆序遍历，遇到非'-'字符，将其转为大写，就加入res，并count+1,当count%K=0时，res添加'-'分隔符，如此直至结束；最后注意res保存的是结果的逆序，并且开头多一个'-',处理一下就ok了:)

```
class Solution {
    public String licenseKeyFormatting(String S, int K) {
        StringBuilder res=new StringBuilder("");
        int count=0;
        for(int i=S.length()-1;i>=0;i--){
            if(S.charAt(i)!='-'){
                if(count%K==0){
                    res.append('-');
                }
                res.append(Character.toUpperCase(S.charAt(i)));
                count++;
            }
        }
        if(res.length()>1)
            res.deleteCharAt(0);
        return res.reverse().toString();
    }
}
```
