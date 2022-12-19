简单易懂的java解法，具体两种处理方法见注释即可。
```java
class Solution {
    public String intToRoman(int num) {
         int values[]=new int[]{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String strs[]=new String[]{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        String str="";
        //从最大的开始算。
        for(int i=0; i<13; i++){
            //>=的意思就是使用多个values[i]
            //比如3999，要有3个1000。
            /*
            while(num>=values[i]){
                num -= values[i];
                str += strs[i];
            }
            */
            //这里还有一种方法，就是去用num/values[i]
            //这样就可以循环加上这个strs[i]
            if(num==0)
                break;
            int times=num/values[i];
            if(times==0)
                continue;
            for(int t=0;t<times;t++)
            {
                str+=strs[i];
            }
            num=num-(times*values[i]);
        }
        return str;
    }
}
```