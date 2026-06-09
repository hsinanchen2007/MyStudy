### 解题思路
写的很垃圾所以击败很低，只是一种思路
遍历每一个word，与1st和2nd对应的则把3rd取出来
当然结尾的时候就没有了，注意不要过界

### 代码

```java
class Solution 
{
    public String[] findOcurrences(String text, String first, String second) 
    {
        List<String>list = new ArrayList<>();
        String [] words = text.split("\\s+");
        for(int i=0;i<words.length-1;i++)
        {
            if(words[i].equals(first)&&words[i+1].equals(second))
            {
                if(i==words.length-2)
                    break;
                list.add(words[i+2]);   
            }
        }
        return list.toArray(new String[list.size()]);
    }
}
```