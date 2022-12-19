执行结果：
通过
显示详情
执行用时 :
19 ms
, 在所有 Java 提交中击败了
94.90%
的用户
内存消耗 :
37.6 MB
, 在所有 Java 提交中击败了
98.93%
的用户
```
class Solution {
    public String intToRoman(int num) {
        StringBuilder sb = new StringBuilder();
        while(num>0){
            //System.out.println(num);
            if(num>=1000){
                int m = num/1000;
                 int k=m;
                while(m>0){
                    sb.append("M");
                       m--;
                }
                num = num-k*1000;
            }else if(num>=900){
                sb.append("CM");
                num = num-900;
            }else if(num>=500){
                sb.append("D");
                num = num-500;
            }else if(num>=400){
                sb.append("CD");
                num = num-400;
            }else if(num>=100){
                int m = num/100;
                 int k=m;
                while(m>0){
                    sb.append("C");
                       m--;
                }
                num = num-k*100;
            }else if(num>=90){
                sb.append("XC");
                num = num-90;
            }else if(num>=50){
                sb.append("L");
                num = num-50;
            }else if(num>=40){
                sb.append("XL");
                num = num-40;
            }else if(num>=10){
                int m = num/10;
                 int k=m;
                while(m>0){
                    sb.append("X");
                       m--;
                }
                num = num-k*10;
            }else if(num>=9){
                sb.append("IX");
                num = num-9;
            }else if(num>=5){
                sb.append("V");
                num = num-5;
            }else if(num>=4){
                sb.append("IV");
                num = num-4;
            }else if(num>=1){
                //System.out.println(num);
                int m = num/1;
                int k=m;
                while(m>0){
                    sb.append("I");
                    m--;
                }
                num = num-k*1;
            }
        }
        return sb.toString();
    }
}
```