### 解题思路
回溯法


### 代码

```java
import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.Map;
class Solution {

    Map<Character, String> phone = new HashMap<Character, String>() {{
    put('2', "abc");
    put('3', "def");
    put('4', "ghi");
    put('5', "jkl");
    put('6', "mno");
    put('7', "pqrs");
    put('8', "tuv");
    put('9', "wxyz");
    }};

  List<String> result = new ArrayList<String>();


    public void Combine(String digits,String str,int index){
        if(index==digits.length()){
            result.add(str);
        }
        else{
            String alph = phone.get(digits.charAt(index));
            for(int i=0;i<alph.length();i++){
                index++;
                Combine(digits,str+alph.substring(i,i+1),index);
                index--;
            }
        }
    }
    
    public List<String> letterCombinations(String digits) {
        if(digits.length()==0){
            return new ArrayList<String>();
        }
        String str = "";
        Combine(digits,str,0);
        return result;
    }
}
```