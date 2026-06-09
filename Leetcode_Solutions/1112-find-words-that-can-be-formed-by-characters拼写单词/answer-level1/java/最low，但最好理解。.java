### 解题思路
用*替换可能重复出现的值

### 代码

```java
class Solution {
  public int countCharacters(String[] words, String chars) {
        
        int count =0;
        for(int i=0;i<words.length;i++){
            String array=chars;
            String word = words[i];
            boolean result=true;
            for(int j=0;j<word.length();j++){
                char tmp= word.charAt(j);
                if(array.contains(tmp+"")){
                    array=array.replaceFirst(tmp+"","*");
                }else{
                    result= false;
                }
            }
            if(result){
                count=count+word.length();
            }
        }
        return count;
    }

    

}
```