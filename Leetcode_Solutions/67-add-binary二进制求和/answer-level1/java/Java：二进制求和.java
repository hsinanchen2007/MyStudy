### 解题思路
用java提供的StringBuilder，将计算结果1或0 append加入，最后reverse反转toString()返回结果
考虑上一次计算是否有进位
1. 分别从字符串a和字符串b的末尾开始遍历 [注：0+0表示分别遍历字符串a当前遍历到0和b遍历到0，刚好对应0+0，下同]
0+0  若有进位，则计算为1，否则为0，本次计算必然不会产生进位（<=1）
0+1 1+0   若有进位，则计算为0，有进位(1+0+1)，否则计算为1，无进位(1+0)
1+1 若有进位（1+1+1），则计算为1，否则为0，本次计算必然有进位(2或3)
2. 遍历字符串a或字符串b的剩余部分（当两串长度不一，则较长的有剩余）
 以a为例
ca=0 若有进位,则计算为1，否则为0，无进位(0+1或0+0)
ca=1 若有进位,则计算为0，有进位（1+1），否则为1，无进位(1+0)
3. 计算完，检测是否还有进位，若有，加入1，否则返回执行结果


### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
        //0+0  0+1 1+0   -->1
        //1+1 ->10
        int ai=a.length()-1,bi=b.length()-1;
        boolean add=false;//进位
        char ca,cb;
        StringBuilder sb=new StringBuilder();
        while(ai>=0&&bi>=0){
            ca=a.charAt(ai);
            cb=b.charAt(bi);
            if(ca=='0'&&cb=='0'){
                if(add){//有进位
                    sb.append('1');
                } else {
                    sb.append('0');
                }
                add=false;
            }
            else if(ca=='0'&&cb=='1'|| ca=='1'&&cb=='0'){
                if(add){
                    sb.append('0');
                    add=true;
                } else {
                    sb.append('1');
                }
            }

            else if(ca=='1'&&cb=='1'){
                if(add){
                    sb.append('1');
                } else {
                    sb.append('0');
                }
                add=true;
            }
            ai--;
            bi--;
        }

        while(ai>=0){
            ca=a.charAt(ai);
            if(ca=='1'){
                if(add){
                    sb.append('0');
                } else {
                    sb.append('1');
                }
            } else {
                if(add){
                    sb.append('1');
                } else {
                    sb.append('0');
                }
                add=false;
            }
            ai--;
        }
        
        while(bi>=0){
            cb=b.charAt(bi);
            if(cb=='1'){
                if(add){
                    sb.append('0');
                } else {
                    sb.append('1');
                }
            } else {
                if(add){
                    sb.append('1');
                } else {
                    sb.append('0');
                }
                add=false;
            }
            bi--;
        }

        if(add){
            sb.append('1');
        }

        return sb.reverse().toString();
    }
}
```