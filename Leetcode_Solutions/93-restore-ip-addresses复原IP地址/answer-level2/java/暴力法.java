暴力法核心：检验三个点位置是否有效，在将字符串取出来进行判断之前，大可根据三个点的相对位置跳过很多明显无效的选项，降低一点运算量。
如下图，我们优先处理左右两个点point1和point3的位置，
（1）由于subString操作是左开右闭的，因此p1可取值为下标[1,3]；p3可取值为[s.length()-3,s.length()-1]；
（2）为了给p2有字符串可截取，p1应满足 p1 < p3 - 1；
（3）现在开始约束p2，既不能离开p1太远，也不能离开p3太远；既要大于p1又要小于p3；
![长字符串.png](https://pic.leetcode-cn.com/6117ca7cabd0aed7a6d5a675dacd9f6a3063a9e6b5e1bf129d4ded955af704b7-%E9%95%BF%E5%AD%97%E7%AC%A6%E4%B8%B2.png)
![短字符串.png](https://pic.leetcode-cn.com/eac62027d419aaed5153c561be6e8373086b1b058e2f8562d6dc1f0ed25dfdcb-%E7%9F%AD%E5%AD%97%E7%AC%A6%E4%B8%B2.png)
因此得到如下判别式
![判别式.png](https://pic.leetcode-cn.com/69b4fc74e80783de84d0275bea786cca71de3618247ed21e3e984188c53dfcb9-%E5%88%A4%E5%88%AB%E5%BC%8F.png)
这时再消耗资源将字符截取出来判别值是否符合要求，并选择加入到结果集中。
注意：以**0开头只有0是符合要求**的:即**010 false； 0 true！**

```
class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        if (s.length() < 4 || s.length() > 12) {
            return res;
        }
        String str0;
        String str1;
        String str2;
        String str3;
        //1 - 3
        for (int point1 = 3; point1 >= 1; point1--) {
            //-3 - -1
            for (int point3 = s.length() - 3; point3 <= s.length() - 1; point3++) {
                if (point1 < point3 - 1) {
                    for (int point2 = point1 + 1; point2 < point3; point2++) {
                        if (point2 <= point1 + 3 && point2 >= point3 - 3) {
                            str0 = s.substring(0, point1);
                            str1 = s.substring(point1, point2);
                            str2 = s.substring(point2, point3);
                            str3 = s.substring(point3);
                            if (valid(str0) && valid(str1) && valid(str2) && valid(str3)) {
                                res.add(str0 + "." + str1 + "." + str2 + "." + str3);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }

    private boolean valid(String str) {
        return Integer.parseInt(str) <= 255 && (!str.startsWith("0") || str.equals("0"));
    }
}
```
