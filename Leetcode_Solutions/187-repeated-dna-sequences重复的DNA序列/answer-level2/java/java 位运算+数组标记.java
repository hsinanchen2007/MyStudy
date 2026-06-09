思路：字符串中只存在四个字符 A，C，G ，T,那么可以用两位的二进制（00，01，10，11）来表示这四个字符，
那么十个字符就对应二十位的二进制，可以转换成对应的二进制表示，

又由于每个字符有四种可能，那么就定义1<<20大小的isExist数组来表示所有的字符是否已存在过，
再定义1<<20大小的isAdd数组来表示所有的字符是否已经添加到结果里面。

1.定义k表示二进制18位都为1的数字，与转换的数字key与运算，可以保留对应数字的后十八位，
也就是对应9个字符，然后再加上下一个字符，就是对应的十个字符的二进制数字，

2.然后根据sExist来判断是否已经存在
若false，则将状态为置为true
若true，则根据isAdd来判断是否已经添加，若false则添加到结果中并置为true。

```
public List<String> findRepeatedDnaSequences(String s) {
        List<String> list = new ArrayList<String>();
        boolean[] isExist = new boolean[1 << 20];
        boolean[] isAdd = new boolean[1 << 20];
        int k = (1 << 18) - 1, key = 0;
        for (int i = 0; i < s.length(); i++) {
            key <<= 2;
            key += getValue(s.charAt(i));
            if (i >= 9) {
                if (isExist[key]) {
                    if (!isAdd[key]) {
                        isAdd[key] = true;
                        list.add(s.substring(i - 9, i + 1));
                    }
                } else {
                    isExist[key] = true;
                }
                key &= k;
            }
        }
        return list;
    }


    private int getValue(char c) {
        switch (c) {
            case 'A':
                return 0;
            case 'C':
                return 1;
            case 'G':
                return 2;
            case 'T':
                return 3;
            default:
                throw new IllegalArgumentException("Illegal character");
        }
    }

```
复杂度分析

时间复杂度：O(n)
只循环一次，并且使用到数组进行判断，所以时间复杂度为O(n)

空间复杂度：O(1)
定义了两个常量的数组，所以空间复杂度为O(1)