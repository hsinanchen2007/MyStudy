### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    static Map<String,String> map = new HashMap<String,String>();
    static {
        map.put("2","abc");
        map.put("3","def");
        map.put("4","ghi");
        map.put("5","jkl");
        map.put("6","mno");
        map.put("7","pqrs");
        map.put("8","tuv");
        map.put("9","wxyz");
    }
    public  void letterCombinations(List<String> list,String fix,String digits) {
        if(digits.length()==0){
            list.add(fix);
            return ;
        }
        String mark = map.get(String.valueOf(digits.charAt(0)));
        for(int i =0 ;i <mark.length();i++){
            letterCombinations(list,fix+String.valueOf(mark.charAt(i)),digits.substring(1,digits.length()));
        }
    }

    public  List<String> letterCombinations(String digits) {
        List<String> list  = new ArrayList<>();
        if(digits!=null && digits.length()!=0){
          letterCombinations(list,"",digits);
        }
        System.out.println(list);
        return list;

    }
}
```