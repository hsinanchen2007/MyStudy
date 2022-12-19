### 解题思路
其实当开始在想直接暴力：遍历所有的可能，发现是n个循环，n为digits的长度
回溯法：其实就是利用递归，因为发现直接循环的话，其实每次的操作都是一样的，只是每次循环的数字不一样，所以这种情况就可以写一个通用的方法，然后递归调用，直到把所有的数字都遍历完； 
    1. 用一个Map存储每个数字代表的字母；
    2. 用一个字符串combination记录每次递归后暂时结果的字符串；nextDigits表示每次递归后的输入值（相当于每次递归都割去最前面的数字）；
    3. 每次递归时，从map中取出对应数字的字母，利用循环依次遍历数字代表的几个（3个或4个）字母，每次把当前字母加到combination之后，在进行递归；当nextDigits的长度为空时，把combination加到result中，表示一种组合情况的完成；
    4. 初次递归把，combination置空传入

### 代码

```java
class Solution {
    public Map<String,String> phone=new HashMap<>(){{
        put("2","abc");
        put("3","def");
        put("4","ghi");
        put("5","jkl");
        put("6","mno");
        put("7","pqrs");
        put("8","tuv");
        put("9","wxyz");
    }};
    public List<String> result=new ArrayList<>();

    public void backtrack(String combination,String nextDigits){
        if(nextDigits.length()==0){
            result.add(combination);
        }else{
            String digit=nextDigits.substring(0,1);
            String letters=phone.get(digit);
            for(int i=0;i<letters.length();i++){
                String letter=letters.substring(i,i+1);
                backtrack(combination+letter,nextDigits.substring(1));
            }
        }
    }
    public List<String> letterCombinations(String digits) {
        if(digits.length()!=0){
            backtrack("",digits);
        }
        return result;
    }
}
```