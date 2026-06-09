### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        //将传进来的字符串以空格拆分
        String[] strings=s.trim().split(" ");
        StringBuffer stringBuffer =new StringBuffer();
        //从后向前遍历
        for(int i=strings.length-1;i>=0;i--)
        {
            if(strings[i].equals(""))
               continue;
            //到头的话最后就不增加空格
            if(i==0)
                stringBuffer.append(strings[i].trim());
            else
            {
                stringBuffer.append(strings[i].trim()).append(" ");
            }
        }
        //输出就行了
        return stringBuffer.toString();
    }
}
```