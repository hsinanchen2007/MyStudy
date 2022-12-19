### 解题思路
就是常规的遍历字符串，用字符-'a'得它在数组里对应的大小，依次相加，若大于等于100则line加一，count变为这个最后加的数，最后看count是不是大于0，大于0就说明最后一行还有line再+1，count就是最后一行的个数啦，返回line和count即可

### 代码

```java
class Solution {
    public int[] numberOfLines(int[] widths, String S) {
        int l = S.length();
        int count = 0, line = 0;
        for(int i = 0; i < l; i++)
        {
            int charsize = widths[S.charAt(i) - 'a'];
            if(count + charsize <= 100)
                count += charsize;
            else
            {
                count = charsize;
                line++;
            }
        }
        if(count > 0)
            line++;
        int [] ans = new int [2];
        ans[0] = line;
        ans[1] = count;

        return ans;
    }
}
```