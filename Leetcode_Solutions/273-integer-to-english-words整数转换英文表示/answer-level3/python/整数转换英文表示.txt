#### 方法一：分治

我们将这个问题分解成一系列子问题。例如，对于数字 `1234567890`，我们将它从低位开始每三个分成一组，得到 `1,234,567,890`，它的英文表示为 `1 Billion 234 Million 567 Thousand 890`。这样我们就将原问题分解成若干个三位整数转换为英文表示的问题了。

接下来，我们可以继续将三位整数分解，例如数字 `234` 可以分别成百位 `2` 和十位个位 `34`，它的英文表示为 `2 Hundred 34`。这样我们继续将原问题分解成一位整数和两位整数的英文表示。其中一位整数的表示是很容易的，而两位整数中除了 `10` 到 `19` 以外，其余整数的的表示可以分解成两个一位整数的表示，这样问题就被圆满地解决了。下面的幻灯片中给出了 `1234567890` 得到英文表示的例子。

<![1200](https://pic.leetcode-cn.com/Figures/273/273_slide_3.png),![1200](https://pic.leetcode-cn.com/Figures/273/273_slide_4.png),![1200](https://pic.leetcode-cn.com/Figures/273/273_slide_5.png),![1200](https://pic.leetcode-cn.com/Figures/273/273_slide_6.png),![1200](https://pic.leetcode-cn.com/Figures/273/273_slide_7.png),![1200](https://pic.leetcode-cn.com/Figures/273/273_slide_8.png),![1200](https://pic.leetcode-cn.com/Figures/273/273_slide_9.png),![1200](https://pic.leetcode-cn.com/Figures/273/273_slide_10.png),![1200](https://pic.leetcode-cn.com/Figures/273/273_slide_11.png),![1200](https://pic.leetcode-cn.com/Figures/273/273_slide_12.png),![1200](https://pic.leetcode-cn.com/Figures/273/273_slide_13.png)>

```Java []
class Solution {
    public String one(int num) {
        switch(num) {
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
        }
        return "";
    }

    public String twoLessThan20(int num) {
        switch(num) {
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
        }
        return "";
    }

    public String ten(int num) {
        switch(num) {
            case 2: return "Twenty";
            case 3: return "Thirty";
            case 4: return "Forty";
            case 5: return "Fifty";
            case 6: return "Sixty";
            case 7: return "Seventy";
            case 8: return "Eighty";
            case 9: return "Ninety";
        }
        return "";
    }

    public String two(int num) {
        if (num == 0)
            return "";
        else if (num < 10)
            return one(num);
        else if (num < 20)
            return twoLessThan20(num);
        else {
            int tenner = num / 10;
            int rest = num - tenner * 10;
            if (rest != 0)
              return ten(tenner) + " " + one(rest);
            else
              return ten(tenner);
        }
    }

    public String three(int num) {
        int hundred = num / 100;
        int rest = num - hundred * 100;
        String res = "";
        if (hundred * rest != 0)
            res = one(hundred) + " Hundred " + two(rest);
        else if ((hundred == 0) && (rest != 0))
            res = two(rest);
        else if ((hundred != 0) && (rest == 0))
            res = one(hundred) + " Hundred";
        return res;
    }

    public String numberToWords(int num) {
        if (num == 0)
            return "Zero";

        int billion = num / 1000000000;
        int million = (num - billion * 1000000000) / 1000000;
        int thousand = (num - billion * 1000000000 - million * 1000000) / 1000;
        int rest = num - billion * 1000000000 - million * 1000000 - thousand * 1000;

        String result = "";
        if (billion != 0)
            result = three(billion) + " Billion";
        if (million != 0) {
            if (! result.isEmpty())
                result += " ";
            result += three(million) + " Million";
        }
        if (thousand != 0) {
            if (! result.isEmpty())
                result += " ";
            result += three(thousand) + " Thousand";
        }
        if (rest != 0) {
            if (! result.isEmpty())
                result += " ";
            result += three(rest);
        }
        return result;
    }
}
```

```Python []
class Solution:
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        def one(num):
            switcher = {
                1: 'One',
                2: 'Two',
                3: 'Three',
                4: 'Four',
                5: 'Five',
                6: 'Six',
                7: 'Seven',
                8: 'Eight',
                9: 'Nine'
            }
            return switcher.get(num)

        def two_less_20(num):
            switcher = {
                10: 'Ten',
                11: 'Eleven',
                12: 'Twelve',
                13: 'Thirteen',
                14: 'Fourteen',
                15: 'Fifteen',
                16: 'Sixteen',
                17: 'Seventeen',
                18: 'Eighteen',
                19: 'Nineteen'
            }
            return switcher.get(num)

        def ten(num):
            switcher = {
                2: 'Twenty',
                3: 'Thirty',
                4: 'Forty',
                5: 'Fifty',
                6: 'Sixty',
                7: 'Seventy',
                8: 'Eighty',
                9: 'Ninety'
            }
            return switcher.get(num)

        def two(num):
            if not num:
                return ''
            elif num < 10:
                return one(num)
            elif num < 20:
                return two_less_20(num)
            else:
                tenner = num // 10
                rest = num - tenner * 10
                return ten(tenner) + ' ' + one(rest) if rest else ten(tenner)

        def three(num):
            hundred = num // 100
            rest = num - hundred * 100
            if hundred and rest:
                return one(hundred) + ' Hundred ' + two(rest) 
            elif not hundred and rest: 
                return two(rest)
            elif hundred and not rest:
                return one(hundred) + ' Hundred'

        billion = num // 1000000000
        million = (num - billion * 1000000000) // 1000000
        thousand = (num - billion * 1000000000 - million * 1000000) // 1000
        rest = num - billion * 1000000000 - million * 1000000 - thousand * 1000

        if not num:
            return 'Zero'

        result = ''
        if billion:
            result = three(billion) + ' Billion'
        if million:
            result += ' ' if result else ''
            result += three(million) + ' Million'
        if thousand:
            result += ' ' if result else ''
            result += three(thousand) + ' Thousand'
        if rest:
            result += ' ' if result else ''
            result += three(rest)
        return result
```

**复杂度分析**

* 时间复杂度：$O(N)$。其中 $N$ 是输入整数的长度。由于输出的英文表示长度和输入整数的长度是成正比的，因此时间复杂度为 $O(N)$。
* 空间复杂度：$O(1)$。