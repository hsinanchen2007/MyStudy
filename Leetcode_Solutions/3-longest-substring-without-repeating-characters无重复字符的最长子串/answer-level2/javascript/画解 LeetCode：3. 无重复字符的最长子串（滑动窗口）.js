##  滑动窗口（首先想到的方法）

![6.png](https://pic.leetcode-cn.com/b8f593a76f06c7ef340159248aecb1cf0b8ac5c43b1bc8d3d98f53de7058fb77.png)


* 标签：`Sliding Window`
* 一句话：滑动找到所有不重复的子字符串，如果子串长度最长，记录为最长子串串
  1. 遍历数组，第一个不重复子字符串为最长字符串
  2. 如果当前字符不存在于子字符串，加入子字符串，如果当前字符串长度大于最长字符串，当前字符串设为最长字符串
  3. 如果存在，则去除子字符串中当前字符及以前的字符，继续遍历
* 时间复杂度：O(n)
* 空间复杂度：O(n)，需要额外空间


### 代码
```Java []
class Solution {
    public int lengthOfLongestSubstring(String s) {
        char[] arr = s.toCharArray();
        int maxLength = 0; // 最长不重复子串长度
        List<Character> list = new ArrayList<>(); // 当前相连不重复子串
        for (int i = 0; i < arr.length; i++) {

            if (!list.contains(arr[i])) {
                list.add(arr[i]);
                if (list.size() >= maxLength) {
                    maxLength = list.size();
                }
            } else {
                int index = list.indexOf(arr[i]);
                List<Character> needToRemoveChar = list.subList(0, index + 1);
                list.removeAll(needToRemoveChar);
                list.add(arr[i]);
            }
        }
        return maxLength;
    }
}
```
```JavaScript []
var lengthOfLongestSubstring = function (s) {
    let maxLength = 0;
    let arr = [];
    for (let i = 0; i < s.length; i++) {
        if (arr.indexOf(s[i]) < 0) {
            arr.push(s[i]);
            if (arr.length > maxLength) {
                maxLength = arr.length;
            }
        } else {
            arr.splice(0, arr.indexOf(s[i]) + 1);
            arr.push(s[i]);
        }
    }
    return maxLength;
};
```
### 画解

<![fr&lt;x&gt;ame_00001.png](https://pic.leetcode-cn.com/af63a7bcb066043ac31cc85c5cdac53182860411d8f060223c7a94b10d4b5969-file_1563724889270),![fr&lt;x&gt;ame_00002.png](https://pic.leetcode-cn.com/4bca0b3458a7615ab806e0d41e25e3d0201b705afe2b3abd217193b7af693b02-file_1563724889289),![fr&lt;x&gt;ame_00003.png](https://pic.leetcode-cn.com/152f3e4a9e7d762116c17b830bcd3f4f1eff4929032a8d062b5405499d10caea-file_1563724889299),![fr&lt;x&gt;ame_00004.png](https://pic.leetcode-cn.com/0332db8626628d1a34da495574ad8a31d721340998dd87535b0c744ac770d1aa-file_1563724889302),![fr&lt;x&gt;ame_00005.png](https://pic.leetcode-cn.com/0c1849f1cab63e1d89c04a90977257c4fd829886c0b8a8c9ed6a2f81be967cad-file_1563724889304),![fr&lt;x&gt;ame_00006.png](https://pic.leetcode-cn.com/915eaa460bc600fda14185c84ac8f99b760d330a2e03fcb0723af860a306550a-file_1563724889305),![fr&lt;x&gt;ame_00007.png](https://pic.leetcode-cn.com/5cb003ed5340201fc293b84f1057752cc84cfbea8c0d558fcb85196f0ef8d69f-file_1563724889306),![fr&lt;x&gt;ame_00008.png](https://pic.leetcode-cn.com/00def5d9ab8eba61dcd8195f1d7c0fb7fd233c566f0ada8cc11013253e675022-file_1563724889308)>


### 测试用例

输入 | " " | "nfpdmpi" | "pwwkew"
---|---|---|---
输出 | 1 | 5 | 3

ps：**拙劣的模仿者，感谢画解算法作者友情指导！**