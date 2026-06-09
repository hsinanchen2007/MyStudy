```
class Solution {
    public String countAndSay(int n) {
        String result = "11";
        if (n == 1) {
            return "1";
        } else if (n == 2) {
            return result;
        }
        while (n > 2) {
            n--;
            //转换为char数组处理字符
            char[] array = result.toCharArray();
            result = "";
            int j = 0;
            for (int i = 1; i < array.length; i++) {
                //双指针判断慢指针和快指针元素不同时，计数并”读出来“
                if (array[i] != array[j]) {
                    result += (i - j) + "" + array[i - 1];
                    j = i;
                }
                //对于末尾的元素特特殊处理
                if (i == array.length - 1 && array[i] == array[j]) {
                    result += (i - j + 1) + "" + array[i];
                }
            }
        }
        return result;
    }
}
```
