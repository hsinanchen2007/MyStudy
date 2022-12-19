#### 解法一：滑动窗口

**直觉**

本问题要求我们返回字符串$S$ 中包含字符串$T$的全部字符的最小窗口。我们称包含$T$的全部字母的窗口为`可行`窗口。

可以用简单的滑动窗口法来解决本问题。

在滑动窗口类型的问题中都会有两个指针。一个用于延伸现有窗口的 $right$指针，和一个用于收缩窗口的$left$ 指针。在任意时刻，只有一个指针运动，而另一个保持静止。

本题的解法很符合直觉。我们通过移动right指针不断扩张窗口。当窗口包含全部所需的字符后，如果能收缩，我们就收缩窗口直到得到最小窗口。

答案是最小的可行窗口。

举个例子，` S = "ABAACBAB"，T = "ABC"`。则问题答案是 `"ACB"` ，下图是可行窗口中的一个。

![image.png](https://pic.leetcode-cn.com/5171b6699007904e71719eca2a0dcbc5f80cf8242a96c2c86f98ea906a07fc60-image.png)

**算法**

1. 初始，$left$指针和$right$指针都指向$S$的第一个元素.

2. 将 $right$ 指针右移，扩张窗口，直到得到一个可行窗口，亦即包含$T$的全部字母的窗口。

3. 得到可行的窗口后，将$leftt$指针逐个右移，若得到的窗口依然可行，则更新最小窗口大小。
4. 若窗口不再可行，则跳转至 $2$。

![image.png](https://pic.leetcode-cn.com/d3d70a1281ae22ade274cefdccd9226b3d9d4686412978e7e38a100099effeef-image.png)
重复以上步骤，直到遍历完全部窗口。返回最小的窗口。


![image.png](https://pic.leetcode-cn.com/b04f46bdbdc6104acaf22eb73a65c45440fb5babf77dca0103c800f092a1bbec-image.png)

```Java [solution1]
class Solution {
  public String minWindow(String s, String t) {

      if (s.length() == 0 || t.length() == 0) {
          return "";
      }

      // Dictionary which keeps a count of all the unique characters in t.
      Map<Character, Integer> dictT = new HashMap<Character, Integer>();
      for (int i = 0; i < t.length(); i++) {
          int count = dictT.getOrDefault(t.charAt(i), 0);
          dictT.put(t.charAt(i), count + 1);
      }

      // Number of unique characters in t, which need to be present in the desired window.
      int required = dictT.size();

      // Left and Right pointer
      int l = 0, r = 0;

      // formed is used to keep track of how many unique characters in t
      // are present in the current window in its desired frequency.
      // e.g. if t is "AABC" then the window must have two A's, one B and one C.
      // Thus formed would be = 3 when all these conditions are met.
      int formed = 0;

      // Dictionary which keeps a count of all the unique characters in the current window.
      Map<Character, Integer> windowCounts = new HashMap<Character, Integer>();

      // ans list of the form (window length, left, right)
      int[] ans = {-1, 0, 0};

      while (r < s.length()) {
          // Add one character from the right to the window
          char c = s.charAt(r);
          int count = windowCounts.getOrDefault(c, 0);
          windowCounts.put(c, count + 1);

          // If the frequency of the current character added equals to the
          // desired count in t then increment the formed count by 1.
          if (dictT.containsKey(c) && windowCounts.get(c).intValue() == dictT.get(c).intValue()) {
              formed++;
          }

          // Try and co***act the window till the point where it ceases to be 'desirable'.
          while (l <= r && formed == required) {
              c = s.charAt(l);
              // Save the smallest window until now.
              if (ans[0] == -1 || r - l + 1 < ans[0]) {
                  ans[0] = r - l + 1;
                  ans[1] = l;
                  ans[2] = r;
              }

              // The character at the position pointed by the
              // `Left` pointer is no longer a part of the window.
              windowCounts.put(c, windowCounts.get(c) - 1);
              if (dictT.containsKey(c) && windowCounts.get(c).intValue() < dictT.get(c).intValue()) {
                  formed--;
              }

              // Move the left pointer ahead, this would help to look for a new window.
              l++;
          }

          // Keep expanding the window once we are done co***acting.
          r++;   
      }

      return ans[0] == -1 ? "" : s.substring(ans[1], ans[2] + 1);
  }
}
```

```Python [solution1]
def minWindow(self, s, t):
    """
    :type s: str
    :type t: str
    :rtype: str
    """

    if not t or not s:
        return ""

    # Dictionary which keeps a count of all the unique characters in t.
    dict_t = Counter(t)

    # Number of unique characters in t, which need to be present in the desired window.
    required = len(dict_t)

    # left and right pointer
    l, r = 0, 0

    # formed is used to keep track of how many unique characters in t are present in the current window in its desired frequency.
    # e.g. if t is "AABC" then the window must have two A's, one B and one C. Thus formed would be = 3 when all these conditions are met.
    formed = 0

    # Dictionary which keeps a count of all the unique characters in the current window.
    window_counts = {}

    # ans tuple of the form (window length, left, right)
    ans = float("inf"), None, None

    while r < len(s):

        # Add one character from the right to the window
        character = s[r]
        window_counts[character] = window_counts.get(character, 0) + 1

        # If the frequency of the current character added equals to the desired count in t then increment the formed count by 1.
        if character in dict_t and window_counts[character] == dict_t[character]:
            formed += 1

        # Try and co***act the window till the point where it ceases to be 'desirable'.
        while l <= r and formed == required:
            character = s[l]

            # Save the smallest window until now.
            if r - l + 1 < ans[0]:
                ans = (r - l + 1, l, r)

            # The character at the position pointed by the `left` pointer is no longer a part of the window.
            window_counts[character] -= 1
            if character in dict_t and window_counts[character] < dict_t[character]:
                formed -= 1

            # Move the left pointer ahead, this would help to look for a new window.
            l += 1    

        # Keep expanding the window once we are done co***acting.
        r += 1    
    return "" if ans[0] == float("inf") else s[ans[1] : ans[2] + 1]
```

**复杂度分析**

* 时间复杂度: $O(|S| + |T|)$，其中 $|S|$ 和 $|T|$ 代表字符串 $S$ 和 $T$的长度。在最坏的情况下，可能会对$S$ 中的每个元素遍历两遍，左指针和右指针各一遍。

* 空间复杂度: $O(|S| + |T|)$。当窗口大小等于$|S|$时为 $S$。当 $|T|$ 包括全部唯一字符时为 $T$ 。
<br/>
<br/>

---

#### 解法二：优化滑动窗口

**直觉**

对上一方法进行改进，可以将时间复杂度下降到 $O(2*|filtered\_S| + |S| + |T|)$，其中 $filtered\_S$ 是从$S$中去除所有在$T$中不存在的元素后，得到的字符串。

当 $|filtered\_S| <<< |S|$时，优化效果显著。这种情况可能是由于$T$ 的长度远远小于$S$，因此$S$ 中包括大量$T$中不存在的自负。

**算法**

我们建立一个 $filtered\_S$列表，其中包括 $S$ 中的全部字符以及它们在$S$的下标，但这些字符必须在 $T$中出现。

`S = "ABCDDDDDDEEAFFBC" T = "ABC"
`
`filtered_S = [(0, 'A'), (1, 'B'), (2, 'C'), (11, 'A'), (14, 'B'), (15, 'C')]`

此处的(0, 'A')表示字符'A' 在字符串$S$的下表为0。

现在我们可以在更短的字符串$filtered\_S$中使用滑动窗口法。

```java [solution2]
import javafx.util.Pair;

class Solution {
    public String minWindow(String s, String t) {

        if (s.length() == 0 || t.length() == 0) {
            return "";
        }

        Map<Character, Integer> dictT = new HashMap<Character, Integer>();

        for (int i = 0; i < t.length(); i++) {
            int count = dictT.getOrDefault(t.charAt(i), 0);
            dictT.put(t.charAt(i), count + 1);
        }

        int required = dictT.size();

        // Filter all the characters from s into a new list along with their index.
        // The filtering criteria is that the character should be present in t.
        List<Pair<Integer, Character>> filteredS = new ArrayList<Pair<Integer, Character>>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (dictT.containsKey(c)) {
                filteredS.add(new Pair<Integer, Character>(i, c));
            }
        }

        int l = 0, r = 0, formed = 0;
        Map<Character, Integer> windowCounts = new HashMap<Character, Integer>();  
        int[] ans = {-1, 0, 0};

        // Look for the characters only in the filtered list instead of entire s.
        // This helps to reduce our search.
        // Hence, we follow the sliding window approach on as small list.
        while (r < filteredS.size()) {
            char c = filteredS.get(r).getValue();
            int count = windowCounts.getOrDefault(c, 0);
            windowCounts.put(c, count + 1);

            if (dictT.containsKey(c) && windowCounts.get(c).intValue() == dictT.get(c).intValue()) {
                formed++;
            }

            // Try and co***act the window till the point where it ceases to be 'desirable'.
            while (l <= r && formed == required) {
                c = filteredS.get(l).getValue();

                // Save the smallest window until now.
                int end = filteredS.get(r).getKey();
                int start = filteredS.get(l).getKey();
                if (ans[0] == -1 || end - start + 1 < ans[0]) {
                    ans[0] = end - start + 1;
                    ans[1] = start;
                    ans[2] = end;
                }

                windowCounts.put(c, windowCounts.get(c) - 1);
                if (dictT.containsKey(c) && windowCounts.get(c).intValue() < dictT.get(c).intValue()) {
                    formed--;
                }
                l++;
            }
            r++;   
        }
        return ans[0] == -1 ? "" : s.substring(ans[1], ans[2] + 1);
    }
}
```

```python [solution2]
def minWindow(self, s, t):
    """
    :type s: str
    :type t: str
    :rtype: str
    """
    if not t or not s:
        return ""

    dict_t = Counter(t)

    required = len(dict_t)

    # Filter all the characters from s into a new list along with their index.
    # The filtering criteria is that the character should be present in t.
    filtered_s = []
    for i, char in enumerate(s):
        if char in dict_t:
            filtered_s.append((i, char))

    l, r = 0, 0
    formed = 0
    window_counts = {}

    ans = float("inf"), None, None

    # Look for the characters only in the filtered list instead of entire s. This helps to reduce our search.
    # Hence, we follow the sliding window approach on as small list.
    while r < len(filtered_s):
        character = filtered_s[r][1]
        window_counts[character] = window_counts.get(character, 0) + 1

        if window_counts[character] == dict_t[character]:
            formed += 1

        # If the current window has all the characters in desired frequencies i.e. t is present in the window
        while l <= r and formed == required:
            character = filtered_s[l][1]

            # Save the smallest window until now.
            end = filtered_s[r][0]
            start = filtered_s[l][0]
            if end - start + 1 < ans[0]:
                ans = (end - start + 1, start, end)

            window_counts[character] -= 1
            if window_counts[character] < dict_t[character]:
                formed -= 1
            l += 1    

        r += 1    
    return "" if ans[0] == float("inf") else s[ans[1] : ans[2] + 1]
```

**复杂度分析**

* 时间复杂度 : $O(|S| + |T|)$， 其中 $|S|$ 和 $|T|$ 分别代表字符串$S$ 和 $T$的长度。 本方法时间复杂度与方法一相同，但当$|filtered\_S|$<<<$|S|$时，复杂度会下降，因为此时迭代次数是 $2*|filtered\_S| + |S| + |T|$。
* 空间复杂度 : $O(|S| + |T|)$。
