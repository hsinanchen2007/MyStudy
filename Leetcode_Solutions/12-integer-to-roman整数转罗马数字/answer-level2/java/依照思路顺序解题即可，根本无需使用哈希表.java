### 解题思路
顺序处理即可，无需使用哈希map

### 代码

```java
class Solution {
    public String intToRoman(int num) {
        if(num <= 0 || num > 3999){
            return "";
        }
        StringBuilder sb = new StringBuilder();

        int incre = 1;
        while(num > 0){
            int value = num % 10;
            switch(incre) {
                case 1:
                    handleUnits(value,sb);
                    break;
                case 2:
                    handleTens(value,sb);
                    break;
                case 3:
                    handleHundreds(value,sb);
                    break;
                case 4:
                    handleThousands(value,sb);
                    break;
                default:
                    break;
            }
            incre++;
            num = num / 10;
        }
        return sb.toString();
    }

    private void handleUnits(int value, StringBuilder sb){
        if(value < 4){
            for(int i=0;i<value;i++){
                sb.insert(0,"I");
            }
        }else if(value == 4){
            sb.insert(0,"IV");
        }else if(value == 5){
            sb.insert(0,"V");
        }else if(value > 4 && value < 9){
            int cyc = value - 5;
            for(int i=0;i<cyc;i++){
                sb.insert(0,"I");
            }
            sb.insert(0,"V");
        }else if(value == 9){
            sb.insert(0,"IX");
        }
    }

    private void handleTens(int value, StringBuilder sb){
        if(value < 4){
            for(int i=0;i<value;i++){
                sb.insert(0,"X");
            }
        }else if(value == 4){
            sb.insert(0,"XL");
        }else if(value == 5){
            sb.insert(0,"L");
        }else if(value > 4 && value < 9){
            int cyc = value - 5;
            for(int i=0;i<cyc;i++){
                sb.insert(0,"X");
            }
            sb.insert(0,"L");
        }else if(value == 9){
            sb.insert(0,"XC");
        }
    }

    private void handleHundreds(int value, StringBuilder sb){
        if(value < 4){
            for(int i=0;i<value;i++){
                sb.insert(0,"C");
            }
        }else if(value == 4){
            sb.insert(0,"CD");
        }else if(value == 5){
            sb.insert(0,"D");
        }else if(value > 4 && value < 9){
            int cyc = value - 5;
            for(int i=0;i<cyc;i++){
                sb.insert(0,"C");
            }
            sb.insert(0,"D");
        }else if(value == 9){
            sb.insert(0,"CM");
        }
    }

    private void handleThousands(int value, StringBuilder sb){
        if(value < 4){
            for(int i=0;i<value;i++){
                sb.insert(0,"M");
            }
        }else{
            throw new RuntimeException("Error over flow size.");
        }
    }
}
```