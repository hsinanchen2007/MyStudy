#### 解题思路：
直接按照题意，逐个单词去匹配是否满足条件即可。

问题：有的人可能会直接写三重嵌套循环判断条件是否满足，但是那样写阅读性太差了，并且可能自己的逻辑也理不清楚。导致写完过后，算法是错误的，一直不能 AC，查错的时候会觉得逻辑有点乱七八糟的，不方便找到错误所在，耽误很多时间。

建议：理不清楚逻辑的时候，不要写那么多重的嵌套，拆分一下，可能事半功倍，阅读性也好，而且可以很清晰的理清楚自己的逻辑，遇到错误也可以很方便的找出来。

为什么有上面两段看上去毫无营养的问题和建议？因为以前我就特别喜欢写嵌套，深受其害，所以给大家一个友好的提示。By the way，我刚开始就是写了三重循环，然后没有 AC，找了半天，没找到错误，然后拆分了一下代码和逻辑，直接就过了，有时候就是这么的神奇。（ε=(´ο｀*)))唉）。

#### 代码：
```Java [-Java]
class Solution {
    public String[] findWords(String[] words) {
        if (words == null) {
            return null;
        }
        
        List<String> ans = new ArrayList<>();

        // 字典行
        String lines[] = new String[] {
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };
        
        // 挨个单词匹配是否满足条件
        for (String word : words) {
            if(judge(word.toLowerCase(),lines)) {
                ans.add(word);
            }
        }
        
        // 刚看到的时候有点疑惑返回值为什么不是List<String>而是String[]
        // list可直接利用API转换为String数组即可
        return ans.toArray(new String[ans.size()]);
    }
    
    private boolean judge(String word,String[] lines) {
        boolean ok = true;
        String find = null;
        
        // 先用word首字符确定属于哪一行
        for (String line : lines) {
            if (line.indexOf(word.charAt(0)) > -1) {
                find = line;
                break;
            }
        }
        
        if (find == null) {
            ok = false;
            return ok;
        }
        
        // 判断word字符串所有字符是否都属于同一行
        for (int i = 1;i < word.length();i++) {
            if (find.indexOf(word.charAt(i)) < 0) {
                ok = false;
                break;
            }
        }
        
        return ok;
    }
}
```

![image.png](https://pic.leetcode-cn.com/c95bc629f9c7d2f554d3bb8061d3404b7930444f3ce520ad7596a7fe64f852ff-image.png){:width=500}