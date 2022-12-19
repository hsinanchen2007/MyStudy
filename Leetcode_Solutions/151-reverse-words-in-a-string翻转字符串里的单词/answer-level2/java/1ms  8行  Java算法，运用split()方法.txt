# 思路
通过s.split(" ") 将s拆分为数组（注意在迭代中跳过“”）

# 代码
```java
    public String reverseWords(String s) {
        String[] ss = s.split(" ");
        int n = ss.length;
        StringBuilder ans = new StringBuilder();
        for (int i = n - 1;i >= 0;i--){
            if (ss[i].length() == 0) continue;
            ans.append(ss[i]).append(" ");
        }
        if(ans.length() > 0) ans.deleteCharAt(ans.length() - 1);
        return ans.toString();
    }
```