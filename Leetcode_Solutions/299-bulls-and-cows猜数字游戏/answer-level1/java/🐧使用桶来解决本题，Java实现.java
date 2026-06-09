首先简化题干，分析什么是A，什么是B。

其实A就是两个字符串中对应位置完全相等的情况的个数，例如：

```json
"1807"和"7801"中，只有8在俩字符串中完全一样，因此A=1
```

其实B就是两个字符串的一个交集，我的计算思路是这样的。例如字符串1有3个'0'，字符串2有4个'0'，那么B就累加上3，以此类推。需要注意的是，由于A情况其实是包含在B情况之内的，因此还需要再最后减去A的值。

最后总体上我是使用了桶来计数，当然使用哈希表也OK。可能代码有点繁琐，没有去仔细想想还能怎么简化了哈哈，主要提供一个思路。

```java
class Solution {
    public String getHint(String secret, String guess) {
        int[] b1 = new int[10];
        int[] b2 = new int[10];
        int bulls = 0, cows = 0;
        //统计俩字符串各个数字的频次，顺带统计bulls的个数
        for(int i = 0, j = 0; i < secret.length() || j < guess.length(); i++, j++){
            if(i < secret.length() && j < guess.length()) {
                b1[secret.charAt(i) - '0']++;
                b2[guess.charAt(j) - '0']++;
                bulls += secret.charAt(i) == guess.charAt(j) ? 1 : 0;
            }else if(i == secret.length()) {
                b2[guess.charAt(j) - '0']++;
            }else if(j == guess.length()) {
                b1[secret.charAt(i) - '0']++;
            }
        }
        //统计cows的个数
        for(int i = 0; i < b1.length; i++) {
            cows += Math.min(b1[i], b2[i]);
        }
        cows -= bulls;
        String res = String.format("%dA%dB", bulls, cows);
        return res;
    }
}
```

