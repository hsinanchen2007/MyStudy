关键点：
1. 存在字母的数量 > (S.length()+1)/2，则不可能实现；
2. 相同不相邻；

解决方法：统计每个字母数量后，先按照字母数量降序排列，然后按照先插满偶数号位置（0，2，4...）再插满奇数号位置的方法插入ans数组即可。最后将ans转化为String后返回
```
class Solution {
    public String reorganizeString(String S) {
        //同一字母出现的数量不能超过（len+1）/2（可以等于）
        int len = S.length();
        if(len == 1) return S;

        Differ[] curr = new Differ[26];
        for(char i='a'; i<='z'; i++) {    //初始化数组
            curr[i-'a'] = new Differ(i);
        }
        for(int i=0; i<len; i++) {
            curr[S.charAt(i)-'a'].amount++;   //赋值
        }
        Arrays.sort(curr);
        if(curr[0].amount > (len+1)/2) return "";
        
        char[] ans = new char[len];
        int temp = 0;
        int i = 0;
        while(i < len) {
            if(curr[temp].amount == 0) temp++;
            ans[i] = curr[temp].alp;
            curr[temp].amount--;
            i += 2;
        }
        
        i = 1;
        while(i < len) {
            if(curr[temp].amount == 0) temp++;
            ans[i] = curr[temp].alp;
            curr[temp].amount--;
            i += 2;
        }
        return String.valueOf(ans);
    }
}

class Differ implements Comparable<Differ>{
    public char alp;
    public int amount = 0;
    public Differ(char alp) {
        this.alp = alp;
    }
    @Override
    public int compareTo(Differ o) {
        return o.amount-this.amount;
    }
}
```

执行用时 :2 ms, 在所有 Java 提交中击败了70.41%的用户
内存消耗 :
34.3 MB, 在所有 Java 提交中击败了96.36%的用户


