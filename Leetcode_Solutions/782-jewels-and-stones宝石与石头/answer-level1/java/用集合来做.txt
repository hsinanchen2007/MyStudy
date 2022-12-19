
```
class Solution {
    public int numJewelsInStones(String J, String S) {
        int num=0;
        char[] ch=J.toCharArray();
        //将宝石种类存入集合
        Set<Character>set=new HashSet<>();
        for(char c:ch)set.add(c);
        char[] rock=S.toCharArray();
        for(char r:rock){
            //判断是否为宝石，是num加一
            if(set.contains(r))num++;
        }
        return num;
    }
}
```
