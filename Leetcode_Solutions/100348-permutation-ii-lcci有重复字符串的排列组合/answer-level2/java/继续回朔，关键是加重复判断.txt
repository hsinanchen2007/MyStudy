### 解题思路
思路；可以和0807即上一道求无重复字符串的排列组合作为对比
 因为有重复的字符，所以可以先选择将数组排序，然后再进行回朔
关键点是需要判断重复字符问题,那么就需要每次保存上一位判断,因为是排序过的S，所以当前位字符作根节点
时与上一位相同，就跳过

### 代码

```java
class Solution {
     public String[] permutation(String S) {
        if(S.length()==0){
            return new String[0];
        }
        //需要先对S进行排序
        char[] chars=S.toCharArray();
        Arrays.sort(chars);

        List<String> list=new ArrayList<>();
        boolean[] userd=new boolean[chars.length];
        StringBuilder sb=new StringBuilder();
        backTrank(list,userd,sb,chars,0);
        return list.stream().toArray(String[]::new);
    }
     public void backTrank(List<String> list,boolean[] userd,StringBuilder sb,char [] s,int start){
        if (start==s.length){
            list.add(sb.toString());
        }
         char lastChar=' ';//上一位的字符
         for (int i = 0; i <s.length ; i++) {
             if(!userd[i] && (s[i]!=lastChar)){
                sb.append(s[i]);
                userd[i]=true;
                backTrank(list,userd,sb,s,start+1);
                lastChar=s[i];   //在回朔时保存上一位的字符
                userd[i]=false;
                sb.deleteCharAt(sb.length()-1);
             }
         }
     }
}
```