### 解题思路
１、将数字转换为字符串；
２、按照字符串长度从高到低（左到位逐位处理）
３、需要注意百位，十位、个位的处理

### 代码

```java
class Solution {
    public static String numberToWords(int num) {
        if (num < 0) {
            return "Num is less than Zero.";
        }
        HashMap<Integer, String> dictForNumVsWord = setDictForNumberVsWords();
        if (num == 0) {
            return dictForNumVsWord.get(0);
        }

        StringBuilder resultSb = new StringBuilder();
        String numStr = Integer.toString(num);
        int lengthOfNum = numStr.length();
        int tmpNum = 0;
        while (lengthOfNum >= 1) {
            switch (lengthOfNum) {
                case 10 : { // 十位数的数字， 先处理第10位
                    tmpNum = Integer.parseInt(numStr.substring(0,1)); // 取第10位数字
                    resultSb.append(dictForNumVsWord.get(tmpNum)).append(" Billion ");
                    numStr = Integer.toString(Integer.parseInt(numStr.substring(1))); // 先转换为整数，去掉前面的0
                    lengthOfNum = numStr.length();
                    break;
                }
                case 9: { // 九位数的数字， 先处理第9位
                    tmpNum = Integer.parseInt(numStr.substring(0,1)); // 取第9位数字
                    resultSb.append(dictForNumVsWord.get(tmpNum)).append(" Hundred ");
                    if (Integer.parseInt(numStr.substring(1, 3)) == 0) {
                        // 如果后面两位都是“0”，增加Million
                        resultSb.append("Million ");
                    }
                    numStr = Integer.toString(Integer.parseInt(numStr.substring(1))); // 先转换为整数，去掉前面的0
                    lengthOfNum = numStr.length();
                    break;
                }
                case 8: { // 取第8和第7位数字处理
                    tmpNum = Integer.parseInt(numStr.substring(0, 2));
                    if (tmpNum >= 20) {
                        resultSb.append(dictForNumVsWord.get(tmpNum - tmpNum % 10)).append(" ");
                        if (tmpNum % 10 != 0) {
                            // 还有个位
                            resultSb.append(dictForNumVsWord.get(tmpNum % 10)).append(" Million ");
                        } else {
                            resultSb.append("Million ");
                        }
                    } else {
                        resultSb.append(dictForNumVsWord.get(tmpNum)).append(" Million ");
                    }
                    numStr = Integer.toString(Integer.parseInt(numStr.substring(2))); // 先转换为整数，去掉前面的0
                    lengthOfNum = numStr.length();
                    break;
                }
                case 7: { // 取第7位数字处理，第8位为零，这是第7位
                    tmpNum = Integer.parseInt(numStr.substring(0, 1));
                    resultSb.append(dictForNumVsWord.get(tmpNum)).append(" Million ");
                    numStr = Integer.toString(Integer.parseInt(numStr.substring(1))); // 先转换为整数，去掉前面的0
                    lengthOfNum = numStr.length();
                    break;
                }
                case 6: { // 取第6位处理
                    tmpNum = Integer.parseInt(numStr.substring(0,1)); // 取第6位数字
                    resultSb.append(dictForNumVsWord.get(tmpNum)).append(" Hundred ");
                    if (Integer.parseInt(numStr.substring(1, 3)) == 0) {
                        // 如果后面两位都是“0”，增加MThousand
                        resultSb.append("Thousand ");
                    }
                    numStr = Integer.toString(Integer.parseInt(numStr.substring(1))); // 先转换为整数，去掉前面的0
                    lengthOfNum = numStr.length();
                    break;
                }
                case 5: { // 取第5，4位数字处理
                    tmpNum = Integer.parseInt(numStr.substring(0, 2));
                    if (tmpNum >= 20) {
                        resultSb.append(dictForNumVsWord.get(tmpNum - tmpNum % 10)).append(" ");
                        if (tmpNum % 10 != 0) {
                            // 还有个位
                            resultSb.append(dictForNumVsWord.get(tmpNum % 10)).append(" Thousand ");
                        } else {
                            resultSb.append("Thousand ");
                        }
                    } else {
                        resultSb.append(dictForNumVsWord.get(tmpNum)).append(" Thousand ");
                    }

                    numStr = Integer.toString(Integer.parseInt(numStr.substring(2))); // 先转换为整数，去掉前面的0
                    lengthOfNum = numStr.length();
                    break;
                }
                case 4: { // 取第4位数字处理
                    tmpNum = Integer.parseInt(numStr.substring(0, 1));
                    resultSb.append(dictForNumVsWord.get(tmpNum)).append(" Thousand ");
                    numStr = Integer.toString(Integer.parseInt(numStr.substring(1))); // 先转换为整数，去掉前面的0
                    lengthOfNum = numStr.length();
                    break;
                }
                case 3: { // 取第3位数字处理
                    tmpNum = Integer.parseInt(numStr.substring(0,1)); // 取第3位数字
                    resultSb.append(dictForNumVsWord.get(tmpNum)).append(" Hundred ");
                    numStr = Integer.toString(Integer.parseInt(numStr.substring(1))); // 先转换为整数，去掉前面的0
                    lengthOfNum = numStr.length();
                    break;
                }
                case 2: { // 取第2，1位数字处理
                    tmpNum = Integer.parseInt(numStr);
                    if (tmpNum >= 20) {
                        resultSb.append(dictForNumVsWord.get(tmpNum - tmpNum % 10)).append(" ");
                        if (tmpNum % 10 != 0) {
                            // 还有个位
                            resultSb.append(dictForNumVsWord.get(tmpNum % 10)).append(" ");
                        }
                    } else {
                        resultSb.append(dictForNumVsWord.get(tmpNum)).append(" ");
                    }
                    lengthOfNum = 0;
                    break;
                }
                case 1: { // 最后一位数字
                    tmpNum = Integer.parseInt(numStr); // 取第3位数字
                    if (tmpNum != 0) {
                        resultSb.append(dictForNumVsWord.get(tmpNum));
                    }
                    lengthOfNum = 0;
                    break;
                }
            }
        }
        return resultSb.toString().trim(); // 返回结果， 去掉首尾空格
    }

    /**
     * 建立数字到英文单词在对照字典；
     * @return
     */
    public static HashMap<Integer, String> setDictForNumberVsWords() {
        HashMap<Integer, String> dictForNumberVsWord = new HashMap<>();
        dictForNumberVsWord.put(0, "Zero");
        dictForNumberVsWord.put(1, "One");
        dictForNumberVsWord.put(2, "Two");
        dictForNumberVsWord.put(3, "Three");
        dictForNumberVsWord.put(4, "Four");
        dictForNumberVsWord.put(5, "Five");
        dictForNumberVsWord.put(6, "Six");
        dictForNumberVsWord.put(7, "Seven");
        dictForNumberVsWord.put(8, "Eight");
        dictForNumberVsWord.put(9, "Nine");
        dictForNumberVsWord.put(10, "Ten");
        dictForNumberVsWord.put(11, "Eleven");
        dictForNumberVsWord.put(12, "Twelve");
        dictForNumberVsWord.put(13, "Thirteen");
        dictForNumberVsWord.put(14, "Fourteen");
        dictForNumberVsWord.put(15, "Fifteen");
        dictForNumberVsWord.put(16, "Sixteen");
        dictForNumberVsWord.put(17, "Seventeen");
        dictForNumberVsWord.put(18, "Eighteen");
        dictForNumberVsWord.put(19, "Nineteen");
        dictForNumberVsWord.put(20, "Twenty");
        dictForNumberVsWord.put(30, "Thirty");
        dictForNumberVsWord.put(40, "Forty");
        dictForNumberVsWord.put(50, "Fifty");
        dictForNumberVsWord.put(60, "Sixty");
        dictForNumberVsWord.put(70, "Seventy");
        dictForNumberVsWord.put(80, "Eighty");
        dictForNumberVsWord.put(90, "Ninety");
        dictForNumberVsWord.put(100, "Hundred");
        return dictForNumberVsWord;
    }
}
```