### 解题思路
此处撰写解题思路

### 代码

```java
//使用交换的方式，先排序，然后注意两种情况的排除
//（1）qqe，相同字母不能交换，如两个q
//（2）oss,o只能和s中的一个进行交换
class Solution {
    List<String> res = new ArrayList<>();
    public String[] permutation(String S) {
        char[] s = S.toCharArray();
        Arrays.sort(s);
        helper(s,0);
        String[] r = new String[res.size()];
        return res.toArray(r);
    }
    private void helper(char[] s, int first){
        if(first == s.length-1){
            res.add(new String(s));
            return;
        }
        for(int i=first;i<s.length;++i){
            if(first < i && s[first] == s[i]) continue;
            if(i>first && s[i]==s[i-1]) continue;
            swap(s,first,i);
            helper(s,first+1);
            swap(s,first,i);
        }
    }
    private void swap(char[] s, int first, int i){
        char tem = s[first];
        s[first] = s[i];
        s[i] = tem;
    }
}


```