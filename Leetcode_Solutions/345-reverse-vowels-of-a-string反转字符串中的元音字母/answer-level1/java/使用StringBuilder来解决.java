### 解题思路
如果包含元音则加入StringBuider，然后再使用StringBuilder原生api来reverse反转。

### 代码

```java
class Solution {
    public String reverseVowels(String s) {
        StringBuilder res=new StringBuilder();
        StringBuilder vowelStr=new StringBuilder();
        List<String> vowel=new ArrayList<>();
        vowel.add("a");
        vowel.add("e");
        vowel.add("i");
        vowel.add("o");
        vowel.add("u");
        vowel.add("A");
        vowel.add("E");
        vowel.add("I");
        vowel.add("O");
        vowel.add("U");
        for(int i=0;i<s.length();i++){
            String tem=s.substring(i,i+1);
            if(vowel.contains(tem)){
                vowelStr.append(tem);
            }
        }
        vowelStr.reverse();
        for(int i=0;i<s.length();i++){
            String tem=s.substring(i,i+1);
            if(vowel.contains(tem)){
                res.append(vowelStr.substring(0,1));
                vowelStr.delete(0,1);
            }else{
                res.append(tem);
            }
        }

        
        return res.toString();


    }
}
```