```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        //设str1的公因数是lenx
        String lenx ="";
        //公因数:n个或者m个lenx能组成str1和str2,满足这条件lenx才是两者的公因数
        //题目说是最大公因子,即可以采用让str1和str2中最小长度的数,从大到小进行枚举,判断是不是公             因数
        int len1=str1.length();
        int len2=str2.length();
        for(int i=Math.min(len1,len2);i>0;i--){ 
            //排除掉长度不能被str1和str2整除的
            if(len1%i==0&&len2%i==0){
                //这里截取str1或者str2都是一样的,最后都需要比较
                lenx=str1.substring(0,i);
                if(gcd(lenx,str1)&&gcd(lenx,str2)) 
                    return lenx;
            }
        }
        return "";   
        
    }
    
    //判断lenx是不是str的公因数
    private Boolean gcd(String lenx,String str){
        //算出str由几个lenx组成
        int num = str.length()/lenx.length();
        //此处必须设置新的值用于保存lenx
        String x="";
        //让num个lenx组合成一个新的字符串
        for(int i=0;i<num;i++){
            x +=lenx;
        }
        
        return x.equals(str);
    }

}
```