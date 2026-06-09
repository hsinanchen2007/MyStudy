### 解题思路
1.特殊情况排除： S存在空串情况，所以首先检测S的长度，如果为0，直接输出S。

2.检测每次字符变化的点，并附带计数器，统计相同字符的个数，字符更换，计数器归0。

3.边界条件：像下面的判断中，最后一次变化之后的字符是不能被直接加入到`result`中的，所以我们记录最后一次变化的地方并把下标存储在`result`中，然后我们再从`index`开始，加入剩下的所有字符。

这个地方也可以在判断中如此写,从而避免判断空串和最后的修补。但是这样好像耗费的时间会多1ms。

```java
for(int i = 0; i < chars.length; i++)
{
    count++;
    if(i == chars.length-1 || chars[i] != chars[i+1])
    {
        sb.append(chars[i]).append(count);
        count = 0;
    }
}
```


### 代码

```java
class Solution {
    public String compressString(String S) {
        if(S.length() == 0)
            return "";
        StringBuilder sb = new StringBuilder();
        char[] chars = S.toCharArray();
        int index = 0;
        int count = 0;
        for(int i = 0; i < chars.length-1; i++)
        {
            count++;
            if(chars[i] != chars[i+1])
            {
                sb.append(chars[i]).append(count);
                count = 0;
                index = i+1;
            }
        }
        sb.append(chars[index]).append(chars.length - index);
        String result = sb.toString();

       return  result.length() < S.length() ? result : S;
    }
}
```