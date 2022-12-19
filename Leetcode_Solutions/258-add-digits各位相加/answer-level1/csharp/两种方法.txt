参考高手写的，自己复制一个
```
理想的方法执行用时 :40 ms, 在所有 csharp 提交中击败了98.36%的用户
内存消耗 :13.6 MB, 在所有 csharp 提交中击败了16.28%的用户
public class Solution {
    public int AddDigits(int num) {
        if(num > 9){
            num %= 9;
            if(num == 0){
                return 9;
            }
        }
        return num;
    }
}
```

```
容易理解的方法
public class Solution {
    public int AddDigits(int num) {
        int m = num;//最终返回的值
        while(m > 9){
            m = 0;
            while(num > 0){
                m += num % 10;
                num /= 10;
            }
            num = m;
        }
        return m;
        return num;
    }
}
```