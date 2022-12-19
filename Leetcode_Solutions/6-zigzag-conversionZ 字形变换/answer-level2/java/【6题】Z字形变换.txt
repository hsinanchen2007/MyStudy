**方法一：按行统计**
```
class Solution {
    /**
    * 思路：
    * 由题最后输出是按行顺序拼接每行，所以可以根据每行的排列规律来统计。
    * (1) 创建容器list来存储所有行，用StringBuilder来记录每一行。
    * (2) 遍历字符串字符，依次从字符串中取出字符放到Z字形排列对应的行中。
    * (3) 依次拼接list每行。
    */
    public String convert(String s, int numRows) {
        if(numRows <= 0){
            return "";
        }else if(numRows == 1 || numRows >= s.length()){
            return s;
        }
        List<StringBuilder> rows = new ArrayList<>();
        for (int i = 0; i < numRows; i++){
			rows.add(new StringBuilder());
		}
        // 排列中每行在list中的角标。
        int curRow = 0;
        // 控制list中角标是递增还是递减.
        boolean goingDown = false;

        for (char c : s.toCharArray()) {
            rows.get(curRow).append(c);
            // list中0和numRows-1是Z字形排列上下两个边界，也就是排列的拐点。
            if (curRow == 0 || curRow == numRows - 1){
				goingDown = !goingDown;
			}
            curRow += goingDown ? 1 : -1;
        }

        StringBuilder ret = new StringBuilder();
        for (StringBuilder row : rows){
			ret.append(row);
		}
        return ret.toString();
    }
}
```

**方法二：按Z字形排列每一组统计**
```
class Solution {
    /**
    * 思路：
    * 由题第一行的每个字符开始排列到下一个第一行字符的前一个字符可以记为一组，
    * 也就是Z字形排列的一个周期。
    * (1) 创建一个StringBuilder存最终输出的字符串，记录字符串长度和每一组的长度。
    * (2) 由于每行相邻两个字符在原字符串中都是相差一组的长度，所以依次遍历每行，
    *       从每行的第一个字符开始拼接当前行的所有字符。
    * (3) 遍历完所有行，返回最终字符串。
    */
    public String convert(String s, int numRows) {
        if (numRows == 1){
			return s;
		}

        StringBuilder ret = new StringBuilder();
        int n = s.length();
        // 每组长度等于竖直部分numRows加上斜的部分numRows-2，2为上下两个边界点。
        int cycleLen = 2 * numRows - 2;
        // 依次遍历每行，i为行角标。
        for (int i = 0; i < numRows; i++) {
            // 依次遍历字符串中在当前行的字符，j为字符在原字符串中的角标。
            for (int j = 0; j + i < n; j += cycleLen) {
                ret.append(s.charAt(j + i));
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n){
					ret.append(s.charAt(j + cycleLen - i));
				}
            }
        }
        return ret.toString();
    }
}
```
