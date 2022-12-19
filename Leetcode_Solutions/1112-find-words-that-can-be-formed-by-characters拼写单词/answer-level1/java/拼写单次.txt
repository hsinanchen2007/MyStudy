### 解题思路
####对c单次表进行计数，每个单词的字母计数与单次中 相应字母的对比。

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {

        //方法1：使用哈希map计数
        // int ans=0;
        // Map <Character,Integer>charcnt=new HashMap<>();
        // char[] schar=chars.toCharArray();
        // for(char ch:schar){
        //     if(!charcnt.containsKey(ch)){
        //         charcnt.put(ch,1);
        //     }
        //     else{
        //          charcnt.put(ch,charcnt.get(ch)+1);
        //     }
        // }

        // for(String word:words){
        //     Map <Character,Integer>wordcnt=new HashMap<>();
        //     boolean flag=true;
        //     char[] sword=word.toCharArray();
        //     for(char ch:sword){
        //         if(!wordcnt.containsKey(ch)){
        //         wordcnt.put(ch,1);
        //          }
        //         else{
        //             wordcnt.put(ch,wordcnt.get(ch)+1);
        //         }
        //     }
        //      for(char ch:sword){
        //          if(wordcnt.containsKey(ch)&&charcnt.containsKey(ch)&&wordcnt.get(ch)<=charcnt.get(ch)){
        //            continue;
        //          }
        //          else{
        //            flag=false;
        //            break;
        //          }
        //      }
        //      if(flag){
        //          ans+=word.length();
        //      }

        // }
        // return ans;
       //方法2：使用26的数组，来计数 ,并字串--加以改进
    //    int ans=0;
    //    int []charcnt=new int[26];
    //    char[] schar=chars.toCharArray();
    //    for(char ch:schar){
    //        charcnt[ch -'a']++;
    //    }
    //    for(String word:words){
    //       boolean flag=true;
    //       int[] temp=Arrays.copyOf(charcnt,charcnt.length); //复制一份单词表
    //       for(char ch:word.toCharArray()){
    //            if(temp[ch-'a']==0){
    //              flag=false;
    //              break;
    //           }
    //           temp[ch-'a']--;
             
    //       }
    //       if(flag){
    //           ans+=word.length();
    //       }
    //    }
    //    return ans;
   
   //方法3： g改进，字串统计—++
    int ans=0;
       int []charcnt=new int[26];
       char[] schar=chars.toCharArray();
       for(char ch:schar){
           charcnt[ch -'a']++;
       }
       for(String word:words){
          boolean flag=true;
          int[] temp=new int [26]; //定义每个单次的单词表
          for(char ch:word.toCharArray()){
              temp[ch-'a']++;
               if(temp[ch-'a']>charcnt[ch -'a']){
                 flag=false;
                 break;
              } 
          }
          if(flag){
              ans+=word.length();
          }
       }
       return ans;
    }
}
```