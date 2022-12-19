### 解题思路
该方法13ms  把判断布尔值的函数提取出来的方法6ms 事实证明写在一起即慢又看不清楚

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] charnum = new int[26];
        for(char c:chars.toCharArray()){
            charnum[c-'a']++;
        }
        int length=0;
        for(int i = 0;i<words.length;i++){
            char[] w = words[i].toCharArray();
            int[] charnumtwo = charnum.clone();

            boolean breakornot = false;
            for(int n = 0;n<w.length;n++){
                if(charnumtwo[w[n]-'a']!=0){
                    charnumtwo[w[n]-'a']--;
                }
                else{
                    breakornot=true;
                    break;
                }
            }
            if(breakornot==false){
                length+=w.length;
            }
        }
        return length;
    }
}
```