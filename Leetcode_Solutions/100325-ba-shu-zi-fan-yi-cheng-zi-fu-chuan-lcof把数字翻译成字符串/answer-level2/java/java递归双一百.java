```
public int translateNum(int num) {
        return translateNum(String.valueOf(num).toCharArray(), 0);
    }
    private int translateNum(char[] chars, int k) {
        if (k == chars.length) return 1;
        int ans = 0, sum = 0;
        for (int i = k, n = 1; i < chars.length; i++, n *= 10) {
            sum = sum * n + (chars[i] - '0');
            if (sum > 25) break;
            ans += translateNum(chars, i + 1);
            if (chars[i] - '0' == 0) break;
        }
        return ans;
    }
```
按照12258为例
1. 试探 1 开始后边2258能组合的合法数量
2. 试探 12 开始 后面 258 能组合的合法数量
3. 试探 122 因为122大于25，所以直接break
按照5016为例
中间遇到0了怎么办？
如果遇到了0，0也是合法的一种，先将0计算在内，第二次会到这一层递归的时候，0之后的情况已经被算过一次，如果再次计算
会出现干扰结果，因为01 和 1 是等效的所以直接break
