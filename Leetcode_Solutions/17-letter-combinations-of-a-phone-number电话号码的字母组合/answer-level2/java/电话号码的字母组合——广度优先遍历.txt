### 解题思路
此处撰写解题思路
可以把字符串组strs想象成一颗树，然后用广度优先遍历得出答案

### 代码

```java
class Solution {
    int len;
    List<String> list = new ArrayList<>();
    public List<String> letterCombinations(String digits) {
        if(digits.equals("")){
            return list;
        }

        Map<Integer,String> map = new HashMap<>();
        map.put(2,"abc");
        map.put(3,"def");
        map.put(4,"ghi");
        map.put(5,"jkl");
        map.put(6,"mno");
        map.put(7,"pqrs");
        map.put(8,"tuv");
        map.put(9,"wxyz");
        this.len = digits.length();
        String[] str;
        if(len==1){
            str = map.get(Integer.valueOf(digits)).split("");
            for(String s:str){
                list.add(s);
            }
            return list;
        }
        str = digits.split("");
        String[] strs = new String[len];
        for(int i=0;i<len;i++){
            strs[i] = map.get(Integer.valueOf(str[i]));
        }
        helper(strs,0,"");
        return list;
    }

    public void helper(String[] strs,int index,String ans){
        int str_len = strs[index].length();
        String temp = ans;
        for(int i=0;i<str_len;i++){
            ans = temp + strs[index].substring(i,i+1);
            if(index==len-1){
                list.add(ans);
            }else {
                helper(strs,index+1,ans);
            }
        }

    }
}
```