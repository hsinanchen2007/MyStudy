
首先把数组看做整数的话，个位就是从数组最右边开始起第一位，也就是arr[].length-1。
开始运算时，我们需要分3中情况考虑，从个位往高位开始：
1.当前位不是9，做累加
2.当前位是9，且当前位不是最高位
3.当前位是9，且当前位是最高位

对于1，我们直接加一结束。2我们需要当前位设为0，然后继续判断高位情况。3最复杂，我们需要加1后，进位。

public int[] plusOne(int[] digits) {
        for(int i=digits.length-1; i>=0 ;i--){
            //当前位是9的话+1
            if(digits[i] == 9){
                digits[i]=0;
                //如果当前位是9，且已经是数组最左边一位了，需要进1位
                if(i==0){
                    int [] digits0= new int[digits.length+1];
                    digits0[0] = 1;
                    System.arraycopy(digits,0,digits0,1,digits.length);
                    digits = digits0;
                    break;
                }
            }else{
                digits[i] += 1;
                break;
            }
        }
        return digits;
    }