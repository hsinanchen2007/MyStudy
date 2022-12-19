解法：枚举所有的可行解，记录可行解的最大长度。

对于第n个字符串，假设我们知道由前n-1个字符串的所有可行解A。 那么第n个就是由包括第n个字符串的可行解 和 不包括第n个字符串的可行解(A)两部分构成。包括第n个字符串 strn 的可行解，由strn 及A中的解与 strn 进行拼接而成。

因为都是小写字母，所以可行解的最大长度<=26,因此所有的可行解都可以用一个int 值来表示，将可行解的比较和拼接都转换为位操作。
两个字符串是否有重复字母：(num1&num2)==0
拼接两个字符串：num1|num2


```
class MyStr {
// 定义 可行解的数据结构 包括值和字符串
    int size;
    int num;

    MyStr(int num, int size) {
        this.num = num;
        this.size = size;
    }
}
```

```
class Solution {
    public int maxLength(List<String> arr) {
        List<MyStr> myStrs = new ArrayList<>();
        for (String str : arr) {
            int value = str2int(str);
            if (value != -1)
                myStrs.add(new MyStr(value, str.length()));
        }
        int max = 0;
        List<MyStr> answers = new ArrayList<>();
        for (int i = 0; i < myStrs.size(); i++) {
            List<MyStr> plus = new ArrayList<>();
            MyStr cur = myStrs.get(i);
            plus.add(cur);
            max = Math.max(max, cur.size);
            for (int j = 0; j < answers.size(); j++) {
                MyStr pre = answers.get(j);
                if ((cur.num & pre.num) == 0) {
                    int size = cur.size + pre.size;
                    max = Math.max(max, size);
                    plus.add(new MyStr((cur.num | pre.num), size));
                }
            }
            answers.addAll(plus);
        }
        return max;
    }

    // 如果字符串内部有重复 return -1
    private int str2int(String s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            int k = s.charAt(i) - 'a';
            if (getBit(num, k)) return -1;
            num = setBit(num, k);
        }
        return num;
    }

    private boolean getBit(int num, int k) {
        return (num & (1 << k)) != 0;
    }

    private int setBit(int num, int k) {
        return num | (1 << k);
    }
」
```

