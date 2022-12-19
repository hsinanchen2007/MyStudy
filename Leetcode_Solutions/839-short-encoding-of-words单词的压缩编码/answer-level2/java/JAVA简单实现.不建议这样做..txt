### 解题思路
根据题意。
1.字母之间用“#”分离
2.当有重复字母可以合用（***字母必须是结尾时匹配才有效**）
3.有两种情况，第一种：先"time"再"me",这时可以忽略"me"
             第二种: 先"me"再"time",这时则需要将之前保存的"me"更替为"time"
所以就根据传入数组遍历，判断是否有满足的要求的，将满足要求的进行过滤
不建议这样做，性能不行.只能说达到效果了

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        if(words.length <1 || words.length > 2000) return 0;
        StringBuilder sbuider = new StringBuilder();
        List<Integer> indexes = new ArrayList<Integer>();
        indexes.add(0);
        List<String> arrWords = new ArrayList();
        for(String word : words){
            if(arrWords.size() == 0 ){
                arrWords.add(0,word);
            }else{
                boolean isHas = false;
                for(int i=0;i<arrWords.size();i++){
                    String currentWord = arrWords.get(i);
                    if(currentWord.length() - word.length() >0){
                        if(currentWord.indexOf(word) >=0 && currentWord.substring(currentWord.indexOf(word)).equals(word)){
                            isHas = true;
                            break;
                        }
                    }else{
                        if(word.indexOf(currentWord) >= 0 && word.substring(word.indexOf(currentWord)).equals(currentWord)){
                            isHas = true;
                               arrWords.remove(i);
                            arrWords.add(i,word);
                            break;
                        }
                    }
                }
                if(!isHas){
                    arrWords.add(word);
                }
            }
        }

         for(int i=0;i<arrWords.size();i++){
                    sbuider.append(arrWords.get(i)).append("#");
                }
       
        return sbuider.toString().length();
    }
   
}
```