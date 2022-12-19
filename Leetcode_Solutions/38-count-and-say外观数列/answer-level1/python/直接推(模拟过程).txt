## 思路:

一句话解释: 不断由前一个数推下一个数. 

## 代码:

```python [1]
class Solution:
    def countAndSay(self, n: int) -> str:
        def next_num(tmp):
            res = ""
            i = 0
            tmp_n = len(tmp)
            while i < tmp_n:
                count = 1
                while i < tmp_n - 1 and tmp[i] == tmp[i+1]:
                    count += 1
                    i += 1
                res += (str(count) + tmp[i])
                i += 1
            return res
        res = "1"
        for i in range(1, n):
            res = next_num(res)
        return res
```



```java [1]
public class CountandSay {
    public String countAndSay(int n) {
        String res = "1";

        for (int i = 1; i < n; i++) {
            res = next_time(res);
        }
        return res;


    }

    private String next_time(String res) {
        int i = 0;
        int n = res.length();
        String ans = "";
        while (i < n) {
            int count = 1;
            while ((i < n - 1) && (res.charAt(i) == res.charAt(i + 1))) {
                i++;
                count++;
            }
            ans += (count + "" + res.charAt(i));
            i++;

        }
        return ans;
    }
}
```

