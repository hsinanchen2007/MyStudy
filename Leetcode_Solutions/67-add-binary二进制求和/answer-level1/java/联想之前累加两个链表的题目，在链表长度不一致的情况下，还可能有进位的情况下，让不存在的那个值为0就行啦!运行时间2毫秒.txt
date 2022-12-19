```
class Solution {
    public String addBinary(String a, String b) {
        if(a==null || b==null) return null;
        int len1=a.length(),len2=b.length();
        int index=0;
        int count=0;//进位
        int achar=0,bchar=0,cal=0;//各位上的值以及和
        StringBuilder s=new StringBuilder();
        while(len1-1-index >=0 || len2-1-index>=0){//从后往前访问，只要有一个没有访问结束
            if(len1-1-index<0){
                 achar=0;//如果访问到头了，直接用0相加
            }else{
                achar=a.charAt(len1-1-index)-'0';//否则取出这个数
            }
            if(len2-1-index<0){
                bchar=0;
            }else{
                bchar=b.charAt(len2-1-index)-'0';
            }
            cal=achar+bchar+count;//计算和
            count=cal/2;//新的进位
            s.append(cal%2+"");//当前位结果
            index++;//往前一位
        }
        if(count !=0){//l判断最高位的累加之后是否产生了进位
            s.append("1");
        }
        s=s.reverse();//反转，因为我们是把低位写在前面，依次往后添加的
        return s.toString();

    }
}
```
