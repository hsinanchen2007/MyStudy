/*
    想要实现三个相同的数字相加会变为0。
    则用00 01 10这三个状态实现
    加1 00->01
    加1 01->10
    加1 10->00
    就达到了加三次变为0的效果

    则需要两位，也就是用两个数字表示
        one two number newone newtwo
         0   0    1       0      1
         0   1    1       1      0
         1   0    1       0      0
     /---------------------------------    
         0   0    0       0      0
         0   1    0       0      1
         1   0    0       1      0

    newone甘特图：
            one/two      
    number   00    01    11    10    
       0      0    0     {x     1}
       1      0    {1     x}     0

    则推出 newone = (~number & one) | (number & two)
    同理得出 newTwo = (~one & ~two & num) | (two & ~num)

    即newone和newtwo符合该状态方程，就可以达到从00状态加三个相同的number变为0的目的。
    测试：
        one和two均初始为00状态，使number为3
        第一次加三
        newone = (~3 & 0) | (3 & 0) = 0
        newtwo = (~0 & ~0 & 3) | (0 & ~3) = 3

        第二次加三
        newone = (~3 & 0) | (3 & 3) = 3
        newtwo = (~0 & ~3 & 3) | (3 & ~3) = 0

        第三次加三
        newone = (~3 & 3) | (3 & 0) = 0
        newtwo = (~3 & ~0 & 3) | (0 & ~3) = 0

        则达到了三次加相同的数变为00

    解释：
        有一种整体的思想，就像数学中的将一个函数看作一个变量。
        这里的one和two只是一个符号，0代表数值意义上的0，1代表的不是数值1，而是一个标记。
        这个标记是一个整体的意思。
        这个标记在本例中就是3。
        所以最后返回的是two，因为one是0。
*/




class Solution {
    public int singleNumber(int[] nums) {
        int one = 0,two = 0,temp = 0;
        for(int number:nums){
            temp = (~number & one) | (number & two);
            two = (~one & ~two & number) | (two & ~number);
            one = temp;
        }
        return two;
    }
}