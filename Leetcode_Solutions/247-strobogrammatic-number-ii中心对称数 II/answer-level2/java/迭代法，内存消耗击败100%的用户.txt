### 解题思路
1. 确定边界条件
2. 迭代递归减少时间规模为n-2
3. 添加11,69,88,98

### 代码

```java
class Solution {
     public List<String> findStrobogrammatic(int n) {


        return strbo(n, n);
    }

    private List<String> strbo(int n, int m) {

        if (n <= 0 || m <=0 || n > m) {
            List<String> ret = new ArrayList<>();
            ret.add("");
            return ret;
        }
        if (n == 0) {
            return new ArrayList<String>(Arrays.asList(""));
        }
        if (n == 1) {
           return new ArrayList<String>(Arrays.asList("0","1","8"));
        }

        List<String> list = strbo(n - 2, m);

        List<String> res = new ArrayList<>();
        for (int i = 0; i < list.size(); i ++) {
            String s = list.get(i);
            if (n != m) {
                res.add("0" + s + "0");
            }
            res.add("1" + s + "1");
            res.add("6" + s + "9");
            res.add("8" + s + "8");
            res.add("9" + s + "6");
        }
        return res;
    }
}
```