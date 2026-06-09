### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findClosest(String[] words, String word1, String word2) {
        // 无论指针遇到了word1、word2，都更新一次距离。。
        int minLength = 100000;
        int word1_index = -1;
        int word2_index = -1;

        for(int i=0; i<words.length; i++  ){
            if( words[i].equals(word1) ){
                word1_index = i;
                if( word2_index!=-1 )
                    minLength = Math.min( minLength, Math.abs(word1_index-word2_index) );
            } 
            if( words[i].equals(word2) ) {
                word2_index = i;
                if( word1_index!=-1 )
                    minLength = Math.min( minLength, Math.abs(word1_index-word2_index) );
            }
        }
        if( minLength!= 100000){
            return minLength;
        } 
        return -1;
    }
}
```