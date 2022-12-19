```
class Solution {
    public int lengthOfLastWord(String s) {
        int count = 0;                      //定义计数器
        for(int l = s.length()-1;l>=0;l-- ){//从末位开始循环
            if(' '!=s.charAt(l)){           //如果不是空格,计数器进行自增
                count++;
            }else if(count!=0){             //如果是空格,判断计数器是否不为零:
                return count;                   //不为零,表示已经遍历完最后一个单词;
            }                                   //为零,表示还未碰到最后一个单词.
        }
        return count;                       //空串直接返回零
    }
}
```
