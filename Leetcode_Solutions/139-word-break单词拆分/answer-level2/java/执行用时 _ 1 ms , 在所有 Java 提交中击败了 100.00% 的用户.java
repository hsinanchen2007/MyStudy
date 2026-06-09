### 解题思路
此处撰写解题思路
整体的思路和动态规划相同吧 主要多用了几个变量来判断 用空间换时间


### 代码

```java
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int min = Integer.MAX_VALUE;
        int max =0;
       HashSet<String> hashword=new HashSet<>();
                      for(String word:wordDict){
                          hashword.add(word);
                          if(min>=word.length()) min=word.length();
                          if(max<=word.length()) max =word.length();
                      }
                      int check[] = new int [s.length()+1];


                      for(int i=min;i<=max;i++){
                          if(i<=s.length()){
                          if(hashword.contains(s.substring(0,i))){
                              check[i]=1;
                          }
                          }
                      }
                      
                      for(int i=min;i<s.length()+1-min;i++){
                            if(check[i]==1){
                            for(int j=min;j<=max;j++){
                                if(i+j<=s.length()){
                             if(hashword.contains(s.substring(i,i+j))){
                              check[i+j]=1;
                          }
                                }

                            }
                            }     
                      }
                     if(check[s.length()]==1) return true;
                     else return false;

    }
}
```