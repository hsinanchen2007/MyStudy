### 解题思路
和官方题解接近，关键在于，不要数字串中的单个字符数，要去数一个字符单独出现的子串数

### 代码

```java
class Solution {
    public int uniqueLetterString(String S) {
        int len = S.length();
        if(len==0) return 0;
        List<Integer>[] indexs = new ArrayList[26];
        //Arrays.fill(indexs,new ArrayList<>());
        
        for(int i=0 ; i<S.length() ; i++){
            char c = S.charAt(i);
            if(indexs[c-'A']==null){
                indexs[c-'A'] = new ArrayList<>();
            }
            indexs[c-'A'].add(i);
        }
        int res = 0;
        int mod = 1000000007;
        for(List<Integer> list : indexs){
            if(list==null || list.size()==0) continue;
            int pre = list.get(0)+1;
            for(int i=1 ; i<list.size() ; i++){
                res = res + (list.get(i)-list.get(i-1))*pre;
                pre = list.get(i)-list.get(i-1);
            }
            res += pre*(len-list.get(list.size()-1));
        }
        
        return res%mod;
    }
}
```