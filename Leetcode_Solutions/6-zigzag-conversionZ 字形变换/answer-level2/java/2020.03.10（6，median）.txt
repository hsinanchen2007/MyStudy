### 解题思路
本题通过排列规律，划分为**周期间隔**

第一行两个元素之间即为一个周期，所以先计算周期数cycleLen，通过StringBuilder可以修改字符串长度，使用append将每行元素依次添加到新的字符串数组ret中

这里将第一行和最后一行作为一类，其他行作为一类，分别append到ret中

时间复杂度：O（n），虽然是两层循环，但第二次循环每次加的是 cycleLen ，无非是把每个字符遍历了 1 次，所以两层循环内执行的次数肯定是字符串的长度。

空间复杂度：O（n），保存字符串。

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1){
            return s;
        }
        StringBuilder ret = new StringBuilder();//可修改字符串长度
        int n = s.length();
        int cycleLen = 2 * numRows - 2;//周期大小

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) { //每次加一个周期
                ret.append(s.charAt(j + i));//将1行和最后一行加进去
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n){ //除去第 0 行和最后一行
                    ret.append(s.charAt(j + cycleLen - i));//加入其他行元素
                }
            }
        }
        return ret.toString();//返回字符串格式
    }
}


```