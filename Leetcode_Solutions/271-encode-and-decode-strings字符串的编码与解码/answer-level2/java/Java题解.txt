思路：编码时除了分隔符外还要把长度带上，否则输入的字符串也可能是你选择的分隔符。解码时从左往右找，先找第一个分隔符，找到长度信息，截出来第一个string。之后以此类推，代码如下：
```
package com.company;

import java.util.ArrayList;
import java.util.List;

public class Codec1 {
    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for (String item : strs) {
            int length = item.length();
            sb.append(length).append("/").append(item);
        }
        return sb.toString();
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        List<String> result = new ArrayList<>();
        int i = 0;
        while (i < s.length()) {
            int pos = s.indexOf('/', i);
            int itemSize = Integer.parseInt(s.substring(i, pos));
            int start = pos + 1;
            int end = pos + itemSize + 1;
            if (end <= s.length()) {
                String item = s.substring(start, end);
                result.add(item);
            }
            i = end;
        }
        return result;
    }
}

```