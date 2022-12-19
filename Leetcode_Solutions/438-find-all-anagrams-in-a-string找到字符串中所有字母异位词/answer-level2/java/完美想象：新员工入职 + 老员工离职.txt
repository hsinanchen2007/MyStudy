- 不求最高赞，只求让更多人得到身临其境地体会
- 琢磨大半天了，看了几乎所有内外站的高赞题解，都在专业的讲解 **字符串特征** 与 **滑动窗口**，也许对摸不着头脑的同学们，更是越看越捉急、越不懂越烦躁
- 忘掉他们，现试试这个有趣的场景

# 题意转换

- `s` 改为 `students` 表示应届生程序员，`p` 改为 `plans` 表示公司对人才配比的期望
- "滑动窗口" 就好比 **新员工入职** + **老员工离职**

# 现在开始，忘掉原题，理解新题意

- **公司期望达到预计的人才配比，hr很苦恼：一边有新员工面试，一边有老员工离职，如何才能完美实现人才配比？**（招多了烧钱，招少了缺人，刚刚好才叫完美）
- hr很聪明，找到两个关键维度，能够快速识别如何达到完美配比
    - 现在总人才缺口是多少 `expected: int`
    - 当前各岗位的人才储备计划 `hire: int[26]`

```java
for (人才顺序) {
    if (老员工离职) {
        列入对应岗位人才储备计划
        if (在公司的计划中 && 当前此岗位缺人) {
            总人才缺口增大
        }
    }

    if (新员工入职) {
        if (在公司的计划中 && 当前此岗位缺人) {
            总人才缺口减小
        }
        从对应岗位人才储备计划划掉
    }

    if (完美配比) 邀功领赏
}
```

```java []
// 带注释
public List<Integer> findAnagrams(String students, String plans) {
    // 应届生人数太少，不可能达到完美配置
    if (students.length() < plans.length()) return Collections.emptyList();

    // 完美配置的结果
    List<Integer> perfect = new LinkedList<>();
    // 公司需要的人才配置(董事会不变的需求)
    int[] need = new int[26]; // 26个不同的岗位
    // 人才招聘计划(随人员来来去去而动态变动)
    int[] hire = new int[26]; // 26个不同的岗位
    // 按照公司需要的人才配置，初始人才招聘册
    for (char plan : plans.toCharArray()) {
        need[plan - 'a']++;
        hire[plan - 'a'] = need[plan - 'a'];
    }

    int needCnt = plans.length(); // 计划招聘人数
    int expected = needCnt; // 当前人才缺口
    char[] coders = students.toCharArray(); // 应届生程序员

    // 逐个应届生程序员面试
    for (int i = 0; i < coders.length; i++) {
        // 老员工离职
        if (i > needCnt - 1) {
            char leaving = coders[i - needCnt]; // 谁要离职
            hire[leaving - 'a']++; // 加入对应岗位招聘计划（若本就人手富裕，相当于逐渐抵消富裕的状况）
            if (need[leaving - 'a'] > 0 && hire[leaving - 'a'] > 0) {
                // 是想留的 && 当前此岗位还未满足
                expected++; // 总人才缺口增大
            }
        }

        // 新应届生面试
        char hiring = coders[i]; // 谁来面试
        if (need[hiring - 'a'] > 0 && hire[hiring - 'a'] > 0) {
            // 来的正是期望的 && 当前此岗位还未满足
            expected--; // 总人才缺口减小
        }
        hire[hiring - 'a']--; // 不管缺不缺，先招进来（若人手富余，则为负数）

        if (expected == 0) perfect.add(i - needCnt + 1); // 达到最佳配置，准备向公司邀功领赏
    }

    return perfect;
}
```
```java []
// 去掉注释，其实也没几行代码
public List<Integer> findAnagrams(String students, String plans) {
    if (students.length() < plans.length()) return Collections.emptyList();
    List<Integer> perfect = new LinkedList<>();
    int[] need = new int[26], hire = new int[26];
    for (char plan : plans.toCharArray()) hire[plan - 'a'] = ++need[plan - 'a'];

    int needCnt = plans.length(), expected = needCnt;
    char[] coders = students.toCharArray();

    for (int i = 0; i < coders.length; i++) {
        if (i > needCnt - 1) {
            char leaving = coders[i - needCnt];
            hire[leaving - 'a']++;
            if (need[leaving - 'a'] > 0 && hire[leaving - 'a'] > 0) expected++;
        }

        char hiring = coders[i];
        if (need[hiring - 'a'] > 0 && hire[hiring - 'a'] > 0) expected--;
        hire[hiring - 'a']--;

        if (expected == 0) perfect.add(i - needCnt + 1);
    }
    return perfect;
}
```
- 关键易错点：
    - 在老员工离职时，为何先 `hire[leaving - 'a']++;` ，再 `if` 判断 `hire`
    - 而新员工入职时，为何先 `if` 判断 `hire`， 再 `hire[leaving - 'a']--;`
    - 纯代码理解，都把 `if` 放在后面也行，不过老员工就要 `hire[leaving - 'a'] >= 0` 而不是 `> 0`
    - 有趣的场景理解
        - **老员工离职，先告诉岗位领导要走，再上升到公司。** 先岗位 `hire` 受影响，再公司 `expected` 受影响
        - **而新员工入职，先和公司谈完薪酬，再分配到对应岗位。** 先公司 `expected` 受影响，再岗位 `hire` 受影响

# 默写模板

- 最后提供一个默写的模板
- 看看能够根据自己的理解，补全代码？

```java
public List<Integer> findAnagrams(String students, String plans) {
    // TODO: 应届生不足，肯定无法完美匹配

    int[] need = new int[26], hire = new int[26];
    // TODO: 公司对各岗位的人才要求，存入 need，并按 need 初始 hire

    int needCnt = plans.length(), expected = needCnt;
    char[] coders = students.toCharArray();
    List<Integer> perfect = new LinkedList<>();

    for (int i = 0; i < coders.length; i++) {
        if (/* 何时第一个老员工离职 */) {
            // 谁离职
            // 当前岗位影响
            // 公司人才影响
        }
        
        // 谁入职
        // 公司先谈待遇
        // 岗位得到补充

        // 完美匹配，邀功领赏
    }
    return perfect;
}
```

# 相似题

- [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)

```java
// two points
public String minWindow(String s, String t) {
    int min = Integer.MAX_VALUE, slen = s.length(), tlen = t.length();
    if (slen < tlen) return "";

    char[] sarr = s.toCharArray(), tarr = t.toCharArray();
    int[] need = new int[256], hire = new int[256];
    int expected = tarr.length;
    for (char c : tarr) need[c] = ++hire[c]; // O(n)

    int l = 0, r = l, len = 0, minL = 0, minLen = 0;
    while (l < slen - tlen + 1 && r < slen) { // O(n+m)
        if (len < r - l + 1) { // 以 len (当前公司总人数)变化，判断是入职还是离职
            // 入职
            int hiring = sarr[r];
            if (need[hiring] > 0 && hire[hiring] > 0) expected--; // 公司先谈待遇
            hire[hiring]--; // 岗位得到补充
        } else {
            // 离职
            int leaving = sarr[l - 1];
            hire[leaving]++; // 当前岗位影响
            if (need[leaving] > 0 && hire[leaving] > 0) expected++; // 公司人才影响
        }
        len = r - l + 1;
        if (expected <= 0) { // 够了就行，无需完美匹配
            if (len < min) {
                min = len;
                minL = l;
                minLen = len;
            }
            l++;
        } else r++;
    }

    return min == Integer.MAX_VALUE ? "" : new String(sarr, minL, minLen);
}
```
