这题的难点我觉得还是读懂题意，题目糊里糊涂描述了半天，其实所谓的**特殊序列**，有两个成立条件：

- 没有与其相等的序列，比如`["aa", "aa"]`，这种情况下便不存在特殊序列。
- 该序列不能是任意序列的子序列，子序列定义见题目描述。

满足这两个条件的最长序列便是**最长特殊序列**。所以只需要判断一个序列是不是特殊序列，再逐次更新长度即可。

步骤和题解中好多人发的步骤相同：

1. 对数组按照字符串长度排序。
2. 依次循环更新即可。
 
代码如下：

```java
class Solution {
    public int findLUSlength(String[] strs) {
        Arrays.sort(strs, (a, b)->Integer.compare(a.length(), b.length())); 
        int j, ret = 0;
        for (int i = 0; i < strs.length; i++) {
            if (ret >= strs[i].length())    continue;
            for (j = 0; j < strs.length; j++) {
                if (i != j && isSubString(strs[i], strs[j]))    break;
            }
            if (j == strs.length) ret = strs[i].length();
        }
        return ret == 0 ? -1:ret;
    }
    
    private boolean isSubString(String s1, String s2) {
        if (s1.length() > s2.length())  return false;
        
        int i = 0, j = 0;
        while (j < s2.length()) {
            if (i == s1.length())   return true;
            if (s1.charAt(i) == s2.charAt(j))   i++;
            j++;
        }
        return i == s1.length();
    }
}
```

用时 `3ms`.

**说明：**

- 由于要寻找的是最长序列，所以从后往前找应该更加省时间一点，只需要将上述代码的循环改反，并改变特判 `if (ret >= strs[i].length())    continue;` 为 `if(ret != 0)  break;` 即可。
- 经过验证，上述改变可将用时变为 `2ms`.