### 解题思路
常规的滑动窗口，但优化做的还不是很好，
如果能把哈希表换成数组可能会好一些，但窗口移动的优化，应该就到这了。
注意intValue()的使用

### 代码

```java
class Solution {
    public boolean checkInclusion(String s1, String s2) {
      //首先要求取的s2部分是连续的，那么可以用窗口来表达
      //先要统计，s1的字符出现的情况，用哈希表存储起来
      //再来一个哈希表用来存储窗口的情况，当窗口长度等于s1长度并且窗口中出现单词数目和目标窗口一样的时候，就return true；再用一个标识符flag来表现这种情况
     //当窗口长度等于s1长度，但是不满足频率条件的时候，将窗口右移动
     //
      boolean flag=false;
      Map<Character,Integer> word=new HashMap<Character,Integer>();
      Map<Character,Integer> window=new HashMap<Character,Integer>();
      int well=s1.length();
      int form=0;
      for(int i=0;i<well;i++)
      {
          int count=word.getOrDefault(s1.charAt(i),0);
            word.put(s1.charAt(i),count+1);//记录下所有的字符出现的频率
      }
      int left=0;
      int right;
      for(right=0;right<s2.length();right++)
      {
        //当一个新字符，word有的时候，才进入窗口，否则跳过当前窗口
        //记录下这个新的字符到window中
        if(word.containsKey(s2.charAt(right)))
        {
            int count=window.getOrDefault(s2.charAt(right),0);
            window.put(s2.charAt(right),count+1);
            //使用intValue转化，这时候目前right所指字符出现频率相等，form++；
            if(word.get(s2.charAt(right)).intValue()==window.get(s2.charAt(right)).intValue())
            {
                form++;
            }
             //当满足条件的字符集合数目和word的数目相等并且窗口长度等于s1的长度时候，找到满足条件的子串
            if(right-left+1==well&&form==word.size())
            { 
                flag=true;
            }
            else if(right-left+1==well&&form!=word.size())
            {
                 //如果不满足，就要将窗口右移，这里只需要处理left，right会在下一次循环中自动后移
                 //如果被移掉的字符正好为使得form++时，再删除form--
                count=window.get(s2.charAt(left)).intValue();
                if(count==word.get(s2.charAt(left)).intValue())
                {
                    form--;
                }
                window.put(s2.charAt(left),count-1);//更新频率
                left++;
            }
           
        }
        else//发现不一样的单词，整体移动窗口，清空window表，
        {
         left=right+1;
         form=0;
         window.clear();
        }
      }

      return flag;  
    }
}
```