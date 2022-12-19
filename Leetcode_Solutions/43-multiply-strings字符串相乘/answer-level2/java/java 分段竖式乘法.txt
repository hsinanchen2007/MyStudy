名字瞎起,写给自己.

我们在竖式乘法的时候是按分段一位来乘的,在进位的时候是两位数进前一位
那么照这个思路,我们可以多位乘多位进
因为int表达的范围十进制是残缺的十位数字
那么我们选择用4位数字为一组
这样会快点
即每次算两个"最多只有4位"的数的乘积
所得结果是8位,可以被int完全包括
进前4位,留后4位

下面是代码,没优化
我单独讨论有一个数为0的情况,
单独讨论我觉得最简单最快捷,
一个零改一片很气,干脆就单独讨论
```
    public static String multiply(String num1, String num2) {
        if(num1.length()==1){
            if (Integer.parseInt(num1)==0){
                return "0";
            }
        }
        if(num2.length()==1){
            if (Integer.parseInt(num2)==0){
                return "0";
            }
        }
        String rs = "";
        int a = num1.length()%4>0?1:0;//判断需不需要多一位
        String[] n1 = new String[num1.length()/4+a];
        a = num2.length()%4>0?1:0;
        String[] n2 = new String[num2.length()/4+a];
        //分段乘只能从后往前,不然会错位
        //System.out.println("length:"+num1.length());
        for(int i = 0;i<n1.length;i++){
            //选取字符串,从后向前选,但是从前往后记录
            //System.out.println((num1.length()-4*i)+" "+(num1.length()-5-4*i));
            if(num1.length()-4-4*i<0){
                n1[n1.length-1] = num1.substring(0,num1.length()-4*i);
                //substring是[a,b)
                break;
            }
            n1[i] = num1.substring(num1.length()-4-4*i,num1.length()-4*i);//4位
            //System.out.println(n1[i]);
        }
        for(int i = 0;i<n2.length;i++){
            //选取字符串,从后向前选,但是从前往后记录
            //System.out.println((num2.length()-4*i)+" "+(num2.length()-5-4*i));
            if(num2.length()-4-4*i<0){
                n2[n2.length-1] = num2.substring(0,num2.length()-4*i);
                //substring是[a,b)
                break;
            }
            n2[i] = num2.substring(num2.length()-4-4*i,num2.length()-4*i);//4位
            //System.out.println(n2[i]);
        }

        //ShowStringList(n1);
        //ShowStringList(n2);
        //已经获得两个可用列表了
        int[] med = new int[n1.length+n2.length-1];

        for(int i = 0;i < n1.length;i++){
            for(int j = 0;j < n2.length;j++){
                med[i+j] += Integer.parseInt(n1[i])*Integer.parseInt(n2[j]);
            }
        }
        //ShowIntList(med);
        //这里再次用到a
        //a = 0;//储存进位信息
        for(int i = 0;i<med.length-1;i++){
            //最后一位单独加上去
            String str = med[i]+"";
            rs = str.substring(str.length()-4,str.length())+ rs;
            //System.out.println(rs);
            med[i+1] = med[i+1]+med[i]/10000;
        }
        if(med.length==0){
            return "0";
        }
        rs = med[med.length-1]==0?"0":med[med.length-1]+rs;

        

        return rs;
    }
```
