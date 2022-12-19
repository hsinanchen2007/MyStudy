## 观察

#### 观察输入 `"23"` 时的结果（为了直观竖排显示）：
```
ad
ae
af
bd
be
bf
cd
ce
cf
```

#### 再观察一个 `"942"` 时的结果：
```
wga
wgb
wgc
wha
whb
whc
wia
wib
wic
xga
xgb
xgc
xha
xhb
xhc
xia
xib
xic
yga
ygb
ygc
yha
yhb
yhc
yia
yib
yic
zga
zgb
zgc
zha
zhb
zhc
zia
zib
zic
```

## 分析

#### 排列组合
根据排列组合的相关性质我们可以知道，最终的结果数为每个位置可选择数的乘积。  
如上面的例子 `"23"=3*3=9` 、`"942"=4*3*3=36`  
观察第一位号码，每个号码中的字符出现次数为 `结果总数÷当前号码字符数` （无论第几位都一样，不过这不是重点）  
目光看向第二位号码，根据组合，每个不同的前一位（第一位）号码字符后面都有相同的序列，`"942"` 有3位号码更为直观一点  
可以分析出2个关键点：  
1. 号码的重复次数  （以字典序排列来说，`a->b->c` 算一次。 对 `"23"` 来说，`"2"` 时没有重复次数，算做1， `"3"` 时重复了3次）
2. 单个字符的连续次数  （以字典序排列来说，单次中连续出现的次数，如字典序 `a->b->c` 中，`aabbcc` 算连续2次）


## 代码

```java
class Solution {

    private static final char[][] chars = new char[][]{
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
    };
    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty())
            return new ArrayList<>();
        char[] number = digits.toCharArray();
        //计算最终结果数量
        int resultCount = 1;
        for (char c : number) {
            resultCount *= chars[c - '2'].length;
        }
        char[][] result = new char[resultCount][number.length];
        int repeat = 1;
        for (int i = 0; i < number.length; i++) {
            //计算当前位号码的重复次数
            repeat *= i > 0 ? chars[number[i - 1] - '2'].length : 1;
            for (int j = 0; j < repeat; j++) {
                //字符数
                int numberChars = chars[number[i] - '2'].length;
                //计算每个字符连续次数
                int continueCount = resultCount / repeat / numberChars;
                //当前行起始下标
                int currentIndex = j * numberChars * continueCount;
                for (int k = 0; k < numberChars; k++) {
                    for (int l = 0; l < continueCount; l++) {
                        result[currentIndex + k * continueCount + l][i] = chars[number[i] - '2'][k];
                    }
                }
            }
        }
        List<String> list = new ArrayList<>(resultCount);
        for (char[] arr : result) {
            list.add(new String(arr));
        }
        return list;
    }
}
```

追求速度采用数组进行处理，避免拼接字符串与截取字符串的耗时。    
LeetCode执行结果：（以下因为平台测试用例过少，速度不是很明显，想对比速度可自行测试）    
执行用时 : 1 ms, 在Letter Combinations of a Phone Number的Java提交中击败了99.89% 的用户  
内存消耗 : 34.8 MB, 在Letter Combinations of a Phone Number的Java提交中击败了93.41% 的用户  