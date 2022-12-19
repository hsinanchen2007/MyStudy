### 解题思路
此处撰写解题思路
确定周期T，然后循环执行，注意行数等于1的情况以及第一行与最后一行特殊处理
执行用时 :
3 ms, 在所有 Java 提交中击败了99.41%的用户
内存消耗 :
41.2 MB, 在所有 Java 提交中击败了6.94%的用户
### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        int num=s.length();
        int T=numRows*2-2;
        StringBuilder result=new StringBuilder();
        int i;
        if(numRows==1)//一行
        {
            return s;
        }
        for(int j=0;j<numRows;j++)  //numRows行
        {
            i=j;    //第一个字符出现的位置
            if(j==0)//第一行
            {
                for(;i<num;i+=T)
                {
                    result.append(s.charAt(i));
                }
            }
            else if(i==numRows-1)//最后一行
            {
                for(;i<num;i+=T)
                {
                    result.append(s.charAt(i));
                }
            }
            else{//中间行
                for(;i<num;i+=T)
                {
                    result.append(s.charAt(i));
                    if(i+2*(numRows-j-1)<num)
                    {
                        result.append(s.charAt(i+2*(numRows-j-1)));
                    }
                }
            }
        }
        return result.toString();

    }
}
```