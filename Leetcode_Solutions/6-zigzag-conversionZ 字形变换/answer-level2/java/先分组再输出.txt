![Z型变换.png](https://pic.leetcode-cn.com/3d56cba98571724bf706dc9749ac882378303629e313ac1025f2b1d55d3fb6d1-Z%E5%9E%8B%E5%8F%98%E6%8D%A2.png)


### 解题思路

自己画一画就能看出来是分开组的，用123456789ACDEF举例
```
1        | 7        | D
2     6  | 8     C  | E
3  5     | 9  B     | F 
4        | A        |  


每组m个元素   6
一共K行      4
```
遍历行数 i到K
第一行就是  输出每组的第 i 个元素 和 第m-i 个元素

就是上面的 第0个元素和 第 6-0 个元素，第六个不存在就不输出了
第k-1 也就是终止条件  4这个元素  i = 3   m-i 也是 3  输出一次就可以了

代码有点乱，大体就是先分组，再遍历。边界条件有点多，if漫天飞...凑乎看吧

### 代码

```java
class Solution {
   public String convert(String s, int numRows) {

       if (s.isEmpty()) {
            return "";
        }

        //每组的个数
        int groupItemCount = 1;
        if(numRows != 1){
            groupItemCount = 2 * (numRows - 1);
        }

        //组数
        int groups = s.length() / groupItemCount;
        //剩余
        int sub = s.length() % groupItemCount;

        if (sub != 0) {
            groups++;
        }


        List<String> strs = new ArrayList<>();
        int start, end;
        for (int j = 0; j < groups; j++) {

            start = j * groupItemCount;
            end = groupItemCount * (j + 1) <= s.length() ? groupItemCount * (j + 1) : s.length();
            strs.add(s.substring(start, end));
            //System.out.println(s.substring(start, end));

        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < numRows; i++) {

            int lastIndex = groupItemCount - i;
            for (String info : strs) {
                if (i >= info.length()) {
                    break;
                }
                sb.append(info.charAt(i));
                if (lastIndex != i && lastIndex < info.length()) {
                    sb.append(info.charAt(lastIndex));
                }
            }
        }
        //System.out.println(sb.toString());
        return sb.toString();
    }
}
```