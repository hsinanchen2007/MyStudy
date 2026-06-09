实现思路就是将原字符串打散成char[]（以下称为原数组)，然后重组这个数组的下标，最后根据重组的下标拼成新的字符串输出
我们可以按照上边给出的示例将整个输出拆成相同的单元，如下

```
L        D        R
E   O    E   I    I
E C      I H      N
T        S        G
```

题目中给出的最大行数是4
所以，每个单元的最大长度就是4 * 2 - 2，得到公式`` max = 2n - 2``
这时再按行来看，第一个单元的第一个字母对应原数组的``0``下标，第二个单元第一个字母对应``0 + max``，以此类推，直到下标与max的和大于原数组总长度，这时就该折行了
第二行第一个单元第一个字母对应原数组的的第二个下标，也就是``1``下标，但这时问题来了，第一个单元和第二个单元之间多存在了一个字母O，怎么办呢
其实逐行来看，除了第一行和最后一行，每一行的两个单元之间都存在一个字母，这时我们把这个字母左边的空间称为``leftSpace``
右边的空间称为``rightSpace``，而第一行，特殊的可以看成``leftSpace == max,  rightSpace == 0``,最后一行反之
而随着行号的不同，``leftSpace``以每行2个的速度递减，``rightSpace``以每行2的速度递增

这时，我们就找到了规律，从第二行开始，这行的所有下标就是从``1``开始，以``leftSpace``和``rightSpace``交替增加得到所有下标

当然第一行我们也可以写成``leftSpace``和``rightSpace``交替增加的样子，但是因为第一行``rightSpace``为0，所以会出现两次相同的结果，这时需要特殊处理下，只记一次


最后贴上代码
```
public static String convert(String s, int numRows) {

        //如果行数是1，不需要做转换
        if(numRows == 1){
            return s;
        }

        char[] ss = s.toCharArray();
        //字符串总长度
        int totalLength = ss.length;

        //经过转换后的下标顺序
        int[] formattedIndex = new int[totalLength];
        //每个单元之间间隔字母的左空间长度
        int leftSpace = 2 * numRows - 2;
        //每个单元之间间隔字母的右空间长度
        int rightSpace = 0;

        for(int i = 0, index = 0; i < numRows && index < totalLength; i++){
            int max = i;
            //用于控制左右空间交替相加的开关
            boolean flag = true;
            //用于比较前后添加的两个下标是否相同，用来处理第一行和最后一行没有间隔字母导致会添加两次相同下标的问题
            int lastAdd = i;
            //每行的开头固定的为（行号-1）
            formattedIndex[index] = i;
            index++;
            //控制每行最大的索引不要超
            while(totalLength - 1 >= (flag ? max + (leftSpace - i * 2) : max + (rightSpace + i * 2))){
                if(flag){
                    max = max + (leftSpace - i*2);
                    flag = false;
                }else{
                    max = max + (rightSpace + i*2);
                    flag = true;
                }
                if(max != lastAdd){
                    formattedIndex[index] = max;
                    index++;
                    lastAdd = max;
                }
            }
        }

        char[] newChars = new char[totalLength];
        for(int i = 0; i < formattedIndex.length; i++){
            int index = formattedIndex[i];
            newChars[i] = ss[index];
        }
        return new String(newChars);
    }
```