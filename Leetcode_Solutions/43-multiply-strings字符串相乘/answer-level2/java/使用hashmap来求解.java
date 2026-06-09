```
class Solution {
    //就是将数值的数位分割后单独相乘
    public String multiply(String num1, String num2) {
        if(num1.equals("0") ||num2.equals("0")){return "0";}
        int len1=num1.length();
        int len2=num2.length();
        String res="";
        //key为jinwei，也就是数位，如果为0代表个位，为1代表十位；value为该数位对应的各值的相加和
         Map<Integer,Integer> calmap=new HashMap<Integer,Integer>();
        //先循环num2 然后循环num1,跟我们手算两数相乘习惯一致
        for(int j=len2-1;j>=0;j--){   //num2
            for(int i=len1-1;i>=0;i--){  //num1
                int prod=Integer.parseInt(num2.substring(j,j+1))* Integer.parseInt(num1.substring(i,i+1));
                // System.out.println("prod为"+prod+"对应i:"+i+"对应j:"+j);
                int jinwei=len1-1-i+(len2-1-j);  //就是指得出的数后面要加几个0；
                if(calmap.containsKey(jinwei)){
                    int value=calmap.get(jinwei);
                    value+=prod;
                    calmap.put(jinwei,value);
                    // System.out.println("calmap包含key:"+jinwei+"计算完value："+value);
                }else{
                    calmap.put(jinwei,prod);
                    // System.out.println("calmap不包含key:"+jinwei+"计算完value："+prod);
                }
            }
        }
        // System.out.println("calmap为："+calmap);
        //得出MaxJinwei,也就是最大位数
        // Set<Integer>  calmapKeys=new HashSet<Integer>();
        // calmapKeys=calmap.keySet();
        // Integer[]  calmapKeysArr=new Integer[calmapKeys.size()];
        // calmapKeys.toArray(calmapKeysArr);
        // Arrays.sort(calmapKeysArr);
        // int MaxJinwei=calmapKeysArr[calmapKeysArr.length-1];
        
        int MaxJinwei=len1+len2-2;
        int shang=0;
        int remainder=0;
        int v=0;
        //接着针对calmap进行计算，得出最后的出参 从最小开始往大走
        for(int k=0;k<=MaxJinwei;k++){  //k<=MaxJinwei
            v=calmap.get(k)+shang;
            remainder=v%10;
            shang=v/10;
            res=remainder+res;
        }
        if(shang!=0){res=shang+res;}
        return res;
    }
    
   
}
```


另外一种使用list来求解
```
class Solution {
    //就是将数值的数位分割后单独相乘
    public String multiply(String num1, String num2) {
        if(num1.equals("0") ||num2.equals("0")){return "0";}
        int len1=num1.length();
        int len2=num2.length();
        String res="";
        int[] callist=new int[len1+len2-1];
        //先循环num2 然后循环num1,跟我们手算两数相乘习惯一致
        int shang=0;
        for(int j=len2-1;j>=0;j--){   //num2
            for(int i=len1-1;i>=0;i--){  //num1
                int value;
                int prod=Integer.parseInt(num2.substring(j,j+1))* Integer.parseInt(num1.substring(i,i+1));
                // System.out.println("prod为"+prod+"对应i:"+i+"对应j:"+j); //如果超时，有可能是日志的原因
                int jinwei=len1-1-i+(len2-1-j);  //就是指得出的数后面要加几个0；
                int temp=callist[jinwei]+prod;              
                int remainder=temp%10;
                shang=temp/10;             
                if(jinwei<len1+len2-2){
                    int v2;
                    if(shang>0){    //注意点，当jinwei<len1+len2-2，则jinwei+1肯定有对应元素
                        v2=callist[jinwei+1]; 
                        v2+=shang;
                        callist[jinwei+1]=v2;   
                    }
                    callist[jinwei]=remainder; //注意点，是等号=，而不是+=
                }else if(jinwei==len1+len2-2){
                    callist[jinwei]=temp;   //注意点，是等号=，而不是+=
                }                 
            }
        }

        for(int item:callist){ 
            res=item+res;
        }
        return res;
    }

}
```
