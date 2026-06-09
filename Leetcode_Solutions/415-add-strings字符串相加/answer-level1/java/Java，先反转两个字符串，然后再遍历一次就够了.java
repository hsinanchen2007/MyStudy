```
        StringBuffer resultSB = new StringBuffer("");
        String reveNum1 = new StringBuffer(num1).reverse().toString();
        String reveNum2 = new StringBuffer(num2).reverse().toString();
        char[] num1Char = reveNum1.toCharArray();
        char[] num2Char = reveNum2.toCharArray();
        int i = 0;
        int add = 0;

        while(i<=num1Char.length||i<=num2Char.length){
            int num1Add = 0;
            int num2Add = 0;

            if(i<num1Char.length){
                num1Add = num1Char[i] - '0';
            }

            if(i<num2Char.length) {
                num2Add = num2Char[i] - '0';
            }

            if(i<num1Char.length||i<num2Char.length){
                resultSB.append((add+num1Add+num2Add)%10+"");
            }else{
                if(add == 1){
                    resultSB.append("1");
                }
            }


            if(add+num1Add+num2Add>=10){
                add = 1;
            }else{
                add = 0;
            }
            i++;
        }
        return resultSB.reverse().toString();
```
