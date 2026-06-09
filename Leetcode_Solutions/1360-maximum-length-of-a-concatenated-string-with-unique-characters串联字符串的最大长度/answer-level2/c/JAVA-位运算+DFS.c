# JAVA-DFS+位运算解法

此题有点像是合并字符的意思，但是看到只有26个小写字符，那么就可以忘位运算里面来靠，每个小写字母占据一个Bit位。我们需要对每个String进行计算其对于的bit表示。

那么，当表示完成后，如何判断两个字符之间有没有重合？很简单，当两个字符之间没有一个Bit重合时，应当a&b = 0，反之，如果a & b != 0，那么至少有一个bit位重合了。

解决了一个判决重合的条件，那么又如何计算对应bit位的长度？这里引入一个算法（不是我相处来的，来源见URL:https://blog.csdn.net/lvyanqin2013/article/details/80498736，需要仔细琢磨一下）。

```c
int bitcount (unsigned int n)
{
    int count=0;
    while (n) {
    count++ ;
    n &= (n - 1);
    }
    return count;
}
```

好，下面分段讲解如何操作：

1. 初始化每个字符对应的位：

```java
for (int i = 0; i < arr.size(); ++i) {
            String s = arr.get(i);
            int index;
            mark[i] = true;
            for (int j = 0; j < s.length(); j++) {
                index = s.charAt(j) - 'a';
                if ((chars[i] & (1 << index)) == 0) {
                    chars[i] |= (1 << index);
                } else {
                    mark[i] = false;
                    break;
                }
            }
        }
```

这里引入mark数组，如果字符本身有重合，那么后续就不访问这个了，也无需计算了

2. DFS搜索外围调用

```java
for (int i = 0; i < chars.length; i++) {
            if (mark[i]) {
                visited[i] = true;
                meSize = countSize(chars[i]);
                dfsSearchMaxLength(chars[i], chars, mark, visited, meSize, i);
                maxLength = Math.max(maxLength, meSize);
                visited[i] = false;
            }
        }
```

这里引入了visited数组，判断是否访问过，这样DFS时就不会重复访问了

3. DFS核心实现:

```java
private void dfsSearchMaxLength(int bits, int[] chars,  boolean[] mark, boolean []visited, int nowLen, int now) {
        int temp;

        for (int i = now + 1; i < chars.length; ++i) {
            if (!mark[i] || visited[i]) {
                continue;
            }

            temp = bits & chars[i];
            if (temp != 0) {
                continue;
            }

            temp = bits ^ chars[i];
            visited[i] = true;
            nowLen += countSize(chars[i]);
            if (nowLen > maxLength) {
                maxLength = nowLen;
            }
            dfsSearchMaxLength(temp, chars, mark, visited, nowLen, i);
            visited[i] = false;
            nowLen -= countSize(chars[i]);

        }
```

可见，DFS里面也是一次循环，跳过已经访问过和自身就是重复的字符。然后将当前字符和上一次字符去重判断，如果没有重复，则访问当前，维护和更新最大长度，继续DFS

完整代码如下:

```java
private int maxLength;

    private int countSize(int bits) {
        int count=0 ;
        while (bits != 0) {
            count++ ;
            bits &= (bits - 1) ;
        }
        return count ;
    }

    public int maxLength(List<String> arr) {
        int []chars = new int[arr.size()];
        int meSize;
        maxLength = 0;

        boolean[] mark = new boolean[arr.size()];
        boolean[] visited = new boolean[arr.size()];

        for (int i = 0; i < arr.size(); ++i) {
            String s = arr.get(i);
            int index;
            mark[i] = true;
            for (int j = 0; j < s.length(); j++) {
                index = s.charAt(j) - 'a';
                if ((chars[i] & (1 << index)) == 0) {
                    chars[i] |= (1 << index);
                } else {
                    mark[i] = false;
                    break;
                }
            }
        }

        for (int i = 0; i < chars.length; i++) {
            if (mark[i]) {
                visited[i] = true;
                meSize = countSize(chars[i]);
                dfsSearchMaxLength(chars[i], chars, mark, visited, meSize, i);
                maxLength = Math.max(maxLength, meSize);
                visited[i] = false;
            }
        }

        return maxLength;
    }

    private void dfsSearchMaxLength(int bits, int[] chars,  boolean[] mark, boolean []visited, int nowLen, int now) {
        int temp;

        for (int i = now + 1; i < chars.length; ++i) {
            if (!mark[i] || visited[i]) {
                continue;
            }

            temp = bits & chars[i];
            if (temp != 0) {
                continue;
            }

            temp = bits ^ chars[i];
            visited[i] = true;
            nowLen += countSize(chars[i]);
            if (nowLen > maxLength) {
                maxLength = nowLen;
            }
            dfsSearchMaxLength(temp, chars, mark, visited, nowLen, i);
            visited[i] = false;
            nowLen -= countSize(chars[i]);

        }
    }
```
运行速度还可以，就是内存不知为什么，我做的JAVA的消耗都特别大，以前写C就不会
![image.png](https://pic.leetcode-cn.com/c2c9840b3d2ce085a4a3b49519e2bef260747002bab79d23719a76dfcfb07adb-image.png)

