### 解题思路
每次都除以相应的数字，然后取余，决定对应字母取多少个，其中要判断特殊条件。
时间4ms,战胜100%的用户，内存损耗40.8

### 代码

```java
class Solution {
    public String intToRoman(int num) {
        
        int reminder=num;
        StringBuilder sb = new StringBuilder();
        if(reminder>=1000){
            num = reminder/1000;
            reminder=reminder%1000;
            for(int i=0;i<num;i++){
                sb.append('M');
            }
        }
        if(reminder>=500){
            if(reminder>=900){
                sb.append('C');
                sb.append('M');
                reminder=reminder-900;
            }else{
                num = reminder/500;
                reminder=reminder%500;
                for(int i=0;i<num;i++){
                    sb.append('D');
                }
            }
        }
        if(reminder>=100){
            if(reminder>=400){
                sb.append('C');
                sb.append('D');
                reminder=reminder-400;
            }else{
                num = reminder/100;
                reminder=reminder%100;
                for(int i=0;i<num;i++){
                    sb.append('C');
                }
            }
        }
        if(reminder>=50){
            if(reminder>=90){
                sb.append('X');
                sb.append('C');
                reminder=reminder-90;
            }else{
                num = reminder/50;
                reminder=reminder%50;
                for(int i=0;i<num;i++){
                    sb.append('L');
                }
            }
        }
        if(reminder>=10){
           if(reminder>=40){
                sb.append('X');
                sb.append('L');
                reminder=reminder-40;
            }else{
                num = reminder/10;
                reminder=reminder%10;
                for(int i=0;i<num;i++){
                    sb.append('X');
                }
            }
        }
        if(reminder>=5){
            if(reminder>=9){
                sb.append('I');
                sb.append('X');
                reminder=reminder-9;
            }else{
                num = reminder/5;
                reminder=reminder%5;
                for(int i=0;i<num;i++){
                    sb.append('V');
                }
            }
            
        }
        if(reminder>=1){
            if(reminder>=4){
                sb.append('I');
                sb.append('V');
                reminder=reminder-4;
            }else{
                for(int i=0;i<reminder;i++){
                    sb.append('I');
                }
            }
        }
        return sb.toString();
    }
}
```