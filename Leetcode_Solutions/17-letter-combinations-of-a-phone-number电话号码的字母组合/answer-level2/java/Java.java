### 解题思路
首先复习map的初始化写法，一是static final初始化一个空对象后，用static包裹依此put。第二是匿名内部类方式，初始化时候直接put添加，但是注意是两层括号。
二是要多思考递归的写法

### 代码

```java
class Solution {

    // public static final Map<String,String> numStringMap = new HashMap();
    // static {
    //             numStringMap.put("2","abc");
    //             numStringMap.put("3","def");
    //             numStringMap.put("4","ghi");
    //             numStringMap.put("5","jkl");
    //             numStringMap.put("6","mno");
    //             numStringMap.put("7","pqrs");
    //             numStringMap.put("8","tuv");
    //             numStringMap.put("9","wxyz");}

        public static final Map<String,String> numStringMap = new HashMap(){{
                put("2","abc");
                put("3","def");
                put("4","ghi");
                put("5","jkl");
                put("6","mno");
                put("7","pqrs");
                put("8","tuv");
                put("9","wxyz");
        }};


        List<String> result = new ArrayList();
            public void combine(String combineBefore,String lastNumString){
                if(lastNumString.length() == 0){
                    result.add(combineBefore);
                }else{
                    String letters = numStringMap.get(lastNumString.substring(0,1));
                    for(int i =0;i<letters.length();i++){
                        String letter = letters.substring(i,i+1);
                        combine(combineBefore+letter,lastNumString.substring(1));
                    }

                }
            }
        public List<String> letterCombinations(String digits) {
                if(digits.length() != 0){
                    combine("",digits);
                }
                return result;
            }
    
}
```