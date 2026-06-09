解题方案。整体思路。将字符串转换为字符数组重后向前按位相加，记录是否进位。如果长度不一致。将字符赋值为0;使计算逻辑统计；如果计算完，进位依然存在结果前补0；
```
public String addBinary(String a, String b) {
        //转数组
        char[] aArray = a.toCharArray();
        char[] bArray = b.toCharArray();
        //取出结果数组长度
        int length = Math.max(aArray.length, bArray.length);
        //生成结果数组
        char[] rArray = new char[length];
        //进位标识符
        boolean jw = false;
        //按照最长数组循环
        for (int i = 1; i <= length; i++) {
            //重后往前获得数据。如果以到数组首位赋值为0保证计算逻辑统一
            char aChar = aArray.length - i >= 0 ? aArray[aArray.length - i] : '0';
            char bChar = bArray.length - i >= 0 ? bArray[bArray.length - i] : '0';
            char benChar = ' ';
            //计算逻辑
            if (aChar == '0' && bChar == '0') {
                benChar = jw ? '1' : '0';
                jw = false;
            } else if (aChar == '0' && bChar == '1') {
                benChar = jw ? '0' : '1';
            } else if (aChar == '1' && bChar == '0') {
                benChar = jw ? '0' : '1';
            } else if (aChar == '1' && bChar == '1') {
                benChar = jw ? '1' : '0';
                jw = true;
            }
            //赋值结果数组
            rArray[length - i] = benChar;
        }
        //返回最终结果
        return jw ? "1" + new String(rArray) : new String(rArray);
    }
```

