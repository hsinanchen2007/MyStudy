优化的线性法（优化滑动窗口）

### 此题可根据暴力法，滑动窗口解答，本题解使用滑动窗口法

### 思路
#### 题目描述，在一串字符串中找出最长的无重复子串，例如 abcbc ， 那么 abc 则为最长无重复子串，我们可以利用快慢指针法来创造一个滑动窗口，并使用一种数据结构存储快指针已经遍历过的值，如果快指针遇到的值已经在存储的值中重复，则更新滑动窗口，即将慢指针指向已经存储的那个重复值的下一位，重新创建窗口。以此类推，最终计算出结果。这里我们存储值的数据结构是`集合`。
```
Set<Character> set = new HashSet<>();
int max = 0;

for (int i = 0, j = 0; j < s.length(); j++) {
    while (set.contains(s.charAt(j))) {
        set.remove(s.charAt(j));
        i++;
    }

    set.add(s.charAt(j));
    max = Math.max(0, set.size());
}

return max;

```

#### 虽然上面解决了问题，但是此算法尚可优化，利用 hashMap 存储每个字母的索引，则再遇到重复值的时候，就不必一个一个地从前到后遍历 remove， 可直接取出索引并 + 1，来重新创建窗口，大大提高了我们的效率。 这里稍微补充一下，可能会遇到一种特殊情况，在创建完新的滑动窗口之后，快指针下一个要检测的值很有可能是被之前废弃调的值，这个时候我们不必回到原来废弃值的索引上了，所以需要将当前慢指针的值与 hashMap 取出的索引值做 max 对比。代码改动如下：


```
HashMap<Character, Integer> hashMap = new HashMap<>();
int max = 0;

for (int i = 0, j = 0; j < s.length(); j++) {
    if (hashMap.containsKey(s.charAt(j))) {
        i = Math.max(i, hashMap.get(s.charAt(j)) + 1);
    }

    hashMap.put(s.charAt(j), j);
    max = Math.max(0, j - i + 1);
}

return max;

```