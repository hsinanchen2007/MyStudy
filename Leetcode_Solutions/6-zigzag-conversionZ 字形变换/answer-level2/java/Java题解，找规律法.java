**写完十分钟再看自己都看不懂了，代码可运行**![8@\]@BT~H9}{Y2)A{4P~14{C.png](https://pic.leetcode-cn.com/0a1f63a8935439cd580dc3546e24094f37a099855ff296a71b56db77655243d9-8@%5D@BT~H9%7D%7BY2\)A%7B4P~14%7BC.png)
欢迎广大网友来挑战————看懂我写的shi代码！
```
class Solution {
    public String convert(String s, int numRows) {
        if(numRows==1)
            return s;
        int len=s.length();//字符串长度
        int dValue=numRows+numRows-2;//每一个Z字的首字母差为numRows*2-2
        char[] str=s.toCharArray();
        StringBuilder sb=new StringBuilder("");
        
        for(int i=0;i<numRows;i++)//按排好z字形的顺序将字符依次添加到输出sb中
        {   
            int num=(len-1)/dValue+1;  //num是以dValue为单位的个数（向上取整）
            if(i==0||i==numRows-1)
                //处理第一行和最后一行
                for(int j=0;j<num&&(j*dValue+i)<len;j++)
                    sb.append(str[j*dValue+i]);
            else
                //处理剩余行
                for(int j=0,temp=j%2==0?i:dValue-i;j<num+num&&j/2*dValue+temp<len;temp=++j%2==0?i:dValue-i)
                    sb.append(str[j/2*dValue+temp]);
        }
        return sb.toString();
    }
}
```

