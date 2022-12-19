/**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/10/16
 *
 * 解题思路: 枚举法解决
 *
 */
```
public String intToRoman(int num) {
    int num_c = num;
    StringBuilder sb = new StringBuilder();
    while(num_c != 0){
        if(num_c >= 1000){
            sb.append("M");
            num_c -= 1000;
        } else if(num_c >= 900){
            sb.append("CM");
            num_c -= 900;
        }else if(num_c >= 500){
            sb.append("D");
            num_c -= 500;
        }else if(num_c >= 400){
            sb.append("CD");
            num_c -= 400;
        } else if(num_c >= 100){
            sb.append("C");
            num_c -= 100;
        }else if(num_c >= 90){
            sb.append("XC");
            num_c -= 90;
        }else if(num_c >= 50){
            sb.append("L");
            num_c -= 50;
        }else if(num_c >= 40){
            sb.append("XL");
            num_c -= 40;
        }else if(num_c >= 10){
            sb.append("X");
            num_c -= 10;
        }else if(num_c >= 9){
            sb.append("IX");
            num_c -= 9;
        }else if(num_c >= 5){
            sb.append("V");
            num_c -= 5;
        }else if(num_c >= 4){
            sb.append("IV");
            num_c -= 4;
        }else{
            if(num_c == 1){
                sb.append("I");
            }else if(num_c == 2){
                sb.append("II");
            }else if(num_c == 3){
                sb.append("III");
            }
            num_c = 0;
        }
    }

    return sb.toString();

}
```