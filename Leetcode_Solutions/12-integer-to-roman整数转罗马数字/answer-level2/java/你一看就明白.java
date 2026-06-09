原理很简单，按照数字从大到小，满足哪个罗马就在一个动态字符串中添加对应罗马字，
然后输入值减去罗马字对应的数，接着循环判断，直到输入值为0；
```
StringBuffer str = new StringBuffer();
        while (num >= 1){
            if (num>=1000){
            num-=1000;
            str.append("M");
            }else if (num>=900){
                num-=900;
                str.append("CM");
            }else if (num>=500){
                num-=500;
                str.append("D");
            }else if (num>=400){
                num-=400;
                str.append("CD");
            }else if (num>=100){
                num-=100;
                str.append("C");
            }else if (num>=90){
                num-=90;
                str.append("XC");
            }else if (num>=50){
                num-=50;
                str.append("L");
            }else if (num>=40){
                num-=40;
                str.append("XL");
            }else if (num>=10){
                num-=10;
                str.append("X");
            }else if (num>=9){
                num-=9;
                str.append("IX");
            }else if (num>=5){
                num-=5;
                str.append("V");
            }else if (num>=4){
                num-=4;
                str.append("IV");
            }else if (num>=1){
                num-=1;
                str.append("I");
            }else {
                return str.toString();
            }
        }
        return str.toString();

    }
```
