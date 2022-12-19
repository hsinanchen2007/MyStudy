### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        
        if(numRows < 2) return s;
        List<StringBuffer> rows=new ArrayList<StringBuffer>();
        for(int i=0;i<numRows;i++)
            rows.add(new StringBuffer());
        
        int i=0,flag=-1;
        for(char c:s.toCharArray())
        {
            rows.get(i).append(c);
            if(i==0 || i==numRows-1)
                flag=-flag;
            i+=flag;
        }

        StringBuffer res=new StringBuffer();
        for(StringBuffer item: rows)
            res.append(item);
        return res.toString();
    }
}
```
Jiejian