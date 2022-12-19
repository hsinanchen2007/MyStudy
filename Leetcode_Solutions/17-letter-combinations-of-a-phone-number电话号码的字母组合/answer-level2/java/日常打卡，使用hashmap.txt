### 解题思路
此题不难，没有涉及到全排序。
用list存储每个数字对应字母的组装。
### 代码

```java
class Solution {
    public static List<String> letterCombinations(String digits) {
        List<String> list = new ArrayList<String> ();
        ArrayList<String> digitsList = new ArrayList<>();
        Map<Character,String> wordMap = new HashMap(8);
        wordMap.put('2',"abc");
        wordMap.put('3',"def");
        wordMap.put('4',"ghi");
        wordMap.put('5',"jkl");
        wordMap.put('6',"mno");
        wordMap.put('7',"pqrs");
        wordMap.put('8',"tuv");
        wordMap.put('9',"wxyz");
        for (int i = 0;i < digits.length();i++){
            if (wordMap.containsKey(digits.charAt(i))){
                list = combineList(list, wordMap.get(digits.charAt(i)));
            }
        }

        return list;
    }

    static ArrayList<String> combineList(List<String> firstList,String s2){
        ArrayList<String> com = new ArrayList<>();
        if (firstList.isEmpty()){
            for (int i = 0;i<s2.length();i++){
                com.add(s2.substring(i,i+1));
            }
        }else {
            for (int i = 0;i<firstList.size();i++){
                for (int j = 0;j<s2.length();j++){
                    com.add(firstList.get(i).concat(s2.substring(j,j+1)));
                }
            }
        }
        return com;
    }
}
```