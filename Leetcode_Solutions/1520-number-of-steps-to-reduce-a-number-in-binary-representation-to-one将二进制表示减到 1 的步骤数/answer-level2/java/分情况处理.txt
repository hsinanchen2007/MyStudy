二进制位数小于500位，所以转换成数字会溢出，分析一下就可以看出
每一位处理的时候分四种情况：
1. 末尾是0，进位是0 ：直接移位，进位为0 需要1步
2. 末尾是1，进位是0 ：先加1，再移位，进位为1 需要2步
3. 末尾是0，进位是1：先加1，再移位，进位为1 需要2步
4. 末尾是1，进位是1:直接移位，进位是1 需要1步

到最后一个字符的时候，由于题目已经限定为1，所以如果进位是1，则需要再移位一次，步数加一

`class Solution {
    public int numSteps(String s) {
        int step = 0;
        int dig = 0;

        while (s.length() > 1){
            char last = s.charAt(s.length() - 1);
            if(last == '0' && dig == 0){
                step++;
            }else if(last == '1' && dig == 0){
                step += 2;
                dig = 1;
            }else if(last == '0' && dig == 1){
                step += 2;
            }else if(last == '1' && dig == 1){
                step++;
                dig = 1;
            }
            s = s.substring(0,s.length() - 1);
        }
        
        if(dig == 1){
            step++;
        }

        return step;
    }
}`