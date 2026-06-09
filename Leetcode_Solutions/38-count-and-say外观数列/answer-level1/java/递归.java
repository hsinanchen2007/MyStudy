```
    public String countAndSay(int n) {
        if (n == 1) return 1 + "";
        String pre = countAndSay(n - 1);
        int count = 0;
        char num = 0;
        StringBuilder result = new StringBuilder();
        for (int i = 0; i <= pre.length(); i++) {
            // num改变了或者遍历到了末尾需要拼接str并重置
            if (i == pre.length() || num != pre.charAt(i)) {
                if (count > 0) result.append(count).append(num);
                if (i != pre.length()) num = pre.charAt(i);
                count = 0;
            }
            count++;
        }
        return result.toString();
    }
```

1. 先找到n-1的串，然后再对此串遍历计算。
2. 遍历注意遍历到最后这个case, 可以和num发生变化这个case写在一起
3. num发生变化后记得拼接字符串后重置num与count
