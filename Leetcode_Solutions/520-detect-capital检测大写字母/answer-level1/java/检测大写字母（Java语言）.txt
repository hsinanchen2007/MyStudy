### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean detectCapitalUse(String word) {
        //Java语言版，统计所有的大小写字母数
        char [] cs=word.toCharArray();
        int upper=0;   //大写字母个数
        int lower=0;   //小写字母个数
        for(int i=0;i<cs.length;i++)
        {
            if(cs[i]>='a')  //a的ASCII码为97
                lower++;
            else
                upper++;
        }
        if(lower==cs.length)
            return true;
        if(upper==cs.length)
            return true;
        if(upper==1&&cs[0]<'a')  //如果只有一位字母大写，且是首字母
            return true;
        return false;
        
    }
}
```