### 解题思路
此处撰写解题思路
1、使用wo数组存储【字母表】中的各字母的个数
2、遍历字符串字符串数组，根据ascii表，使用 flag =words[i].charAt(j)-'a';  来确定要比较字符的存储位置。
### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int wo[] = new int[26];
        int final_wo[] =new int[26];
        int i,j,len=0;
        int flag=0;
        //使用wo数组存储【字母表】中的各字母的个数，完成  字母表为初始赋值
        for(i=0;i<chars.length();i++)
        {
             flag = chars.charAt(i)-'a';
            //System.out.println(flag);
            wo[flag]= wo[flag]+1;
        }
        final_wo = wo.clone();      //数组的拷贝

        for(i=0;i<words.length;i++)
        {

            for(j=0;j<words[i].length();j++)
            {
                flag =words[i].charAt(j)-'a';
         
                if(wo[flag]==0)
                {
                    wo= final_wo.clone();   //某个字符不存在，把已修改的字母表更正
                    break;  //如果字母表中不存在该字母，提出循环
                }
                else
                {
                      wo[flag]=wo[flag]-1;
                    if(j==(words[i].length()-1))      //整个字符串都在字母表
                    {

                        len =words[i].length()+len ;       //记录字符长度
                    }
                }
            }
              wo= final_wo.clone(); //重置 字母表为初始赋值
            
        }
        return len;
    }
}
```