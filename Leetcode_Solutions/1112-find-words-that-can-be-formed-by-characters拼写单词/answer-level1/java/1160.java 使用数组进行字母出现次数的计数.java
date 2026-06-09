// ### 解法

// ```java
public int countCharacters(String[] words, String chars) {
        int res = 0;
        int[] countChars = getCount(chars);
        for(int i = 0; i < words.length; i++){
            int n = words[i].length();
            if(n > chars.length())
                continue;
            if(isValid(words[i],n , getCount(words[i]), countChars))
                res += n;
        }
        return res;
    }

    private int[] getCount(String s){
        int[] count = new int[26];
        for(int i = 0; i < s.length(); i++)
            count[s.charAt(i) - 'a'] += 1;
        return count;
    }

    private boolean isValid(String wordStr, int n, int[] word, int[] chars){
        for(int i = 0; i < n; i++){
            int index = wordStr.charAt(i) - 'a';
            if(word[index] > chars[index])
                return false;
        }
        return true;
    }
// ```

// 思路分析：

// * 对于每一个词汇，词汇中的每一个字母都要能在`chars`中找到，并且`chars`中的字母不能重用。所以不单要知道每个词汇中出现了哪些字母，还需要知道每个字母出项了多少次。对于`chars`也一样。
// * 所以写一个辅助函数`getCount(String s)`来统计字符串中各个字母出现了多少次。
//     * 一般来说统计出现次数使用HashMap，但是字符串中只出现小写字母，可以使用`int[]`来代替哈希表。以`s.charAt(i) - 'a'`为键，键与字母一一对应，以该字母出现的次数为值。
//     * 所以遍历字符串中的每个字符，然后`count[s.charAt(i) - 'a'] += 1;`，完成对字符串中字母出现次数的统计
// * 判断一个词汇是否能由`chars`中的字母构成的辅助函数为`boolean isValid(String wordStr, int n, int[] word, int[] chars)`
//     * 第一个参数是待判断的词汇，第二个参数是该词汇的长度，第三个参数是该词汇的字符统计结果数组，第四个参数是字母表字符统计结果数组。
//     * 对于`wordStr`中的每个字母，`int index = wordStr.charAt(i) - 'a'`得到该字母对应的键，通过键去查看出现次数。如果`word[index] > chars[index]`，该字母在字母表中不够，直接返回`false`。如果循环完都没有出现这样的情况，说明该词汇可以拼写出来。
// * 主函数中第三行先得到字母表字符统计结果数组，因为一直要用。然后对于每个词汇，如果词汇的长度大于字母表长度，那肯定不行，就跳过当此循环；否则调用`isValid`，满足题意就在结果中加上`n = words[i].length();`

// 运行结果：

// * 执行用时 :5 ms, 在所有 Java 提交中击败了93.25%的用户
// * 内存消耗 :42.2 MB, 在所有 Java 提交中击败了5.08%的用户

// 更多LeetCode题解请看我的[github](https://github.com/ustcyyw/yyw_algorithm)，地址https://github.com/ustcyyw/yyw_algorithm。还有别的小项目也很好玩~卑微求个小星星💖