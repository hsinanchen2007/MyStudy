### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<String> list = new ArrayList<String>();
    private static final Map<Integer, String> num2StringArray = new HashMap<Integer, String>();
    static{
        num2StringArray.put(2, "abc");
        num2StringArray.put(3, "def");
        num2StringArray.put(4, "ghi");
        num2StringArray.put(5, "jkl");
        num2StringArray.put(6, "mno");
        num2StringArray.put(7, "pqrs");
        num2StringArray.put(8, "tuv");
        num2StringArray.put(9, "wxyz");
    }
    public List<String> letterCombinations(String digits) {
       if(null == digits || digits.length()==0 ){
           return list;
       }
       findLetters(digits.toCharArray(), 0, "");
       return list;
    }

    //s 表示digitsArray[0......index-1]转换得到的一个字符串
    //方法表示寻找digitsArray[index]匹配的字符串
    public void findLetters(char[] digitsArray, int index, String s){
        if(index == digitsArray.length){
            list.add(s);
            return;
        }
        char[]  strArr = num2StringArray.get(digitsArray[index]-'0').toCharArray();
        for(int i =0; i< strArr.length; i++){
            findLetters(digitsArray, index+1, s+strArr[i]);
        }
        
    }
}
```