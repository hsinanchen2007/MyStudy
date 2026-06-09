### 解题思路
首先判断两个字符串是否分别为空，根据题意可知，如果needle为空返回0。其次，因为已经判断过needle不为空了，如果这时haystack为空，表明needle在haystack中不可能出现任何匹配情况，故直接返回-1。
接下来遍历haystack数组，数组遍历次数haystack长度减去needleChar长度，这个长度为有且有可能匹配到的最大下标值，超出无意义，然后遍历判断每个字符是否与needleChar首字符相等，如果不等，继续下次遍历。
接着判断，如果能走到判断needleCharArray.length长度地方表明，首字母是匹配的，这时如果判断到needleCharArray长度是1的话，表明可以直接返回当前haystackChar的下标了，因为只有一个字符，已经找到了。如果needleCharArray长度不为1，开始遍历needleChar，
首字母已经判断过相等了，直接从第二个下标开始判断，一旦遇到某个字符不相等，直接跳出needleChar循环，继续外层遍历。如果相等接着判断下标是否到达了needleCharArray的最大长度，是否匹配到了最后一个字符都是相等的，如果是直接返回当前haystackChar数组下标。没有到达needleCharArray的最大长度，则继续遍历。


### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        // 首先判断 如果 needle 为空 返回0
        if (needle.length() == 0) {
            return 0;
        }
        // 其次判断 如果haystack 为空  needle已经不为空了，所以肯定匹配不到 返回-1
        if (haystack.length() == 0) {
            return -1;
        }
        char[] haystackCharArray = haystack.toCharArray();//5
        char[] needleCharArray = needle.toCharArray();//2
        // 直接计算出有可能匹配到的最大下标，因为超过无意义
        for (int i = 0; i <= haystackCharArray.length - needleCharArray.length; i++) {
            // 判断首字母是否相同
            if (haystackCharArray[i] != needleCharArray[0]) {
                continue;
            }
            // 如果needle 长度是1代码 能走到现在表明通过了上面的判断 直接返回
            if (needleCharArray.length == 1) {
                return i;
            }
            for (int j = 1; j < needleCharArray.length; j++) {
                // 判断 如果连续字符串不相等 退出循环
                if (haystackCharArray[i + j] != needleCharArray[j]) {
                    break;
                }
                // 判断needle 是否循环完了，如果完了，能走到这一步说明没问题都匹配了
                if (j == needleCharArray.length - 1) {
                    return i;
                }
                // 继续循环
                continue;
            }
        }
        
        return -1;
    }
}
```