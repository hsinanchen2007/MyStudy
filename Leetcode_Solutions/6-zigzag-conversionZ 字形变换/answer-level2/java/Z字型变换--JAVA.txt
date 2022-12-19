# 思路1：
      二维数组，根据规律把字符串的char数组，放入char二维数组，然后遍历输出
```
class Solution {
    public String convert(String s, int numRows) {
         if (numRows == 1) {
            return s;
        }
        int columns = calculateColumn(s.length(), numRows);
        Character[][] newCharArr = new Character[numRows][columns];
        char[] chars = s.toCharArray();
        int row = 0;
        int column = 0;
        boolean add = false;

        for (int i = 0; i < chars.length; i++) {
            newCharArr[row][column] = chars[i];
            if (i % (numRows - 1) == 0) {
                add = !add;
            }
            if (add) {
                row++;
            } else {
                row--;
                column++;
            }
        }
        char[] result = new char[s.length()];
        int index = 0;
        for (int i = 0; i < newCharArr.length; i++) {
            for (int j = 0; j < newCharArr[i].length; j++) {
                Character c = newCharArr[i][j];
                if (c != null) {
                    result[index] = c;
                    index++;
                }
            }
        }
        return new String(result);
    }
    
    public static int calculateColumn(int length, int line) {
        if (length <= line) {
            return 1;
        }
        int item = 2 * (line - 1);
        int column = length / item;
        int mod = length % item;
        int add = 0;
        if (mod > 0 && mod <= line) {
            add = 1;
        } else if (mod > line) {
            add = mod % line + 1;
        }
        return column + column * (line - 2) + add;
    }
}
```
# 思路2：
        根据行，用StringBuffer依次添加char，最后合并输出
```
public static String convert2(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        StringBuffer[] sbs=new StringBuffer[numRows];
        for (int i = 0; i < sbs.length; i++) {
            sbs[i]=new StringBuffer();
        }
        char[] chars = s.toCharArray();
        int row = 0;
        boolean add = false;
        for (int i = 0; i < chars.length; i++) {
            sbs[row].append(chars[i]);
            if (i % (numRows - 1) == 0) {
                add = !add;
            }
            if (add) {
                row++;
            } else {
                row--;
            }
        }
        for (int i = 1; i < sbs.length; i++) {
            sbs[0].append(sbs[i]);
        }
        return sbs[0].toString();
    }
```
# 总结：
    主要是行变换规律，对于行号变化：index % (numRows -1)==0 时，行号递进关系发生反转变化： 从+1变-1
例如： 行数为4，行号变化  0- >1->2->3->2->1->0->.....



