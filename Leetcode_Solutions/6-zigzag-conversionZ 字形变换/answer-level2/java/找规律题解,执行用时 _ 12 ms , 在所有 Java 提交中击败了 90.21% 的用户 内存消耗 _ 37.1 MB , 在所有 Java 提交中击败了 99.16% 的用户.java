
以例子中的“LEETCODEISHIRING”为例，分别画出为3行，4行，5行的图

![1d869741b2f0359708af690f061a052.png](https://pic.leetcode-cn.com/8f42fe4a625696d17668fbde69fa150356b6fed95ae82c8e79dd3f2dc922ee47-1d869741b2f0359708af690f061a052.png)
![4e3fbbefae5bde765ee42f0c8abc3fc.png](https://pic.leetcode-cn.com/a494f991b1091d68f5d8aac500262a33faaf3aa912e773a1f6e560d9090711b3-4e3fbbefae5bde765ee42f0c8abc3fc.png)
![d6c7f10a4562f6fa2951f9150ef0234.png](https://pic.leetcode-cn.com/162c221f946b684c811bcadef64af47c550f3244a41eb865e5f5c04aefb452f6-d6c7f10a4562f6fa2951f9150ef0234.png)
红字表示Z字形排序过后的位置，既字符串数组的下标，绿字表示字符之间间隔的数字之差。
由这三图可知，每张图第一行，最后一行两个字符之间的间隔分别为4,6,8，得出公式：interval（总间隔）=numRows X 2 - 2,中间行的间隔：奇数间隔为interval-(循环到了第几行-1) X 2,偶数间隔为(循环到了第几行-1) X 2,如：图二，总间隔数为interval = 4 X 2 - 2 = 6，第二行E与O之间相差6-（2 - 1）X 2 = 4，O与第二个E之间相差（2-1） * 2 = 2。
此时我通过一个a表示间隔之差，处理第一行最后一行时，直接a = interval，在处理2~numRows-1行时，
a = interval-a,最后得出结果。
代码如下：
` public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        StringBuffer sb = new StringBuffer();
        int interval = numRows * 2 - 2;
        int flag = 0;
        int a = 0;
        for (int i = 0; i < numRows; i++) {
            a = flag;
            for (int j = i; j < s.length(); j = j + a) {
                sb.append(s.charAt(j));
                if (i == 0 || i == numRows - 1) {
                    a = interval;
                } else {
                    a = interval - a;
                }
            }
            flag += 2;
        }
        return sb.toString();
    }`