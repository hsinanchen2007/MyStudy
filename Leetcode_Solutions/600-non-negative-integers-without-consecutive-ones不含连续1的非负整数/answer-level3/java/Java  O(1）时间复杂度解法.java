```
/**
     * problem 600
     * @param num
     * @return
     * 观察以下数列： 可得规律：  4位二进制最大值的不含连续1的解 = 3位二进制最大值的不含连续1的解 + 2位二进制最大值的不含连续1的解；  为什么？    比如一个数 1010：最左位为1，那么要想符合要求，必须接下来一位为0；以此递归。
     *  0 1 10 11 100 101 110 111 1000 1001 1010 1011 1100 1101 1110 1111 10000
     *  1 2 3  3  4   5   5   5   6    7    8    8    8      8  8     8     9
     *  求num在 2^i ~ 2^i+1中哪个半区 (注：半区是指比(2^i + 2^(i+1))/2 大或小的区域)
     *  如果是比一半大的那个半区，那么直接返回 num所占二进制位数对应的解；
     *  否则则返回 num所占二进制位数-1对应的解 + num将最高位的1去除之后的值的递归解
     */
    public static int[] bits_problem_600 = new int[31];
    static {
        bits_problem_600[1] = 2;
        bits_problem_600[2] = 3;
        for (int i=3 ; i<=30 ;i++){
            bits_problem_600[i] = bits_problem_600[i-1] + bits_problem_600[i-2];
        }
    }
    public int findIntegers(int num) {
        if (num == 0)
            return 1;
        if (num == 1)
            return 2;

        int a = 1<<30;   //a = 2的30次方
        int count = 30;  //count代表1左移的次数，实际位数需要加1
        while (num/a ==0){  
            a = a>>1;
            count--;
        }
        int temp = num - a;   //用来计算num是否比 (2^i+2^(i+1))/2 大
        a = a>>1;
        if (temp == 0)  
            return bits_problem_600[count] + 1;
        else if (temp/a != 0)     //如果确实比(2^i+2^(i+1))/2 大，那么直接返回i位共有多少符合要求的结果就行了；
            return bits_problem_600[count+1];
        else{    
            return bits_problem_600[count]+ findIntegers(temp);
        }
    }
```
