


```
class Solution {
    public int findComplement(int num) {
        System.out.println(temp);
        StringBuilder ss=new StringBuilder(temp);//十进制转二进制
//      while(num != 0){     不用移位怎么解决2的倍数。这种转化方法碰到2的倍数就歇菜了
//          temp+=num%2;
//          num/=2;      
//      }



        for(int i=0;i<ss.length();i++){
            if(ss.charAt(i)=='1') 
            {ss.setCharAt(i,'0');}
            else if(ss.charAt(i)=='0') 
            {ss.setCharAt(i,'1');}
        };
        int tt=0;
        System.out.println(ss);
        for(int i=ss.length()-1,j=0;i>=0;i--,j++){
            System.out.println(tt);
            if(ss.charAt(i)=='1') {int kk=(int)Math.pow(2,j);tt=tt+kk;}   
        }
        return tt;
    }
}
```