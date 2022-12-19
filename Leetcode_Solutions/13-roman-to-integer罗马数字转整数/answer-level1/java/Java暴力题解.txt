### 解题思路
暴力解法..
1.先将字符串全部转化为整数并存储到数组中
2.遍历数组,判断前一位数是否小于后一个位,如果小于就将后一位数减去前一位数,并加到结果中
否则就直接相加到结果中.
3.相加过程中要判断数组下一位是否越界.
4.最后进行返回就是最终的结果了

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        int toInt = 0;
        int[] toIntArray = new int[s.length()];
        toIntArray[0] = 3;
        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case 'I':
                    toIntArray[i] = 1;
                    break;
                case 'V':
                    toIntArray[i] = 5;
                    break;
                case 'X':
                    toIntArray[i] = 10;
                    break;
                case 'L':
                    toIntArray[i] = 50;
                    break;
                case 'C':
                    toIntArray[i] = 100;
                    break;
                case 'D':
                    toIntArray[i] = 500;
                    break;
                case 'M':
                    toIntArray[i] = 1000;
                    break;
            }
        }
        for(int i = 0; i < toIntArray.length;i++) {
            if(i+1 < toIntArray.length && toIntArray[i] < toIntArray[i + 1]) {
                toInt += toIntArray[i + 1] - toIntArray[i];
                i++;
            } else {
                toInt += toIntArray[i];
                System.out.println(toInt);
            }
        }
        return toInt;
    }
}
```