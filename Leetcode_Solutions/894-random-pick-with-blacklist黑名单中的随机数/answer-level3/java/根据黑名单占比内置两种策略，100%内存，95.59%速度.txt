### 解题思路
此处撰写解题思路
内置两种方法。
1. 当给出的黑名单大于N的一半时候，使用提取白名单的方法
2. 当给出的黑名单小于N的一半时候，使用简单的HashSet循环碰撞

执行用时 :73 ms, 在所有 Java 提交中击败了95.59%的用户
内存消耗 :54.5 MB, 在所有 Java 提交中击败了100.00%的用户


### 代码

```java
class Solution {

    private Random random = new Random();
    private List<Integer> white;
    private boolean type;
    private Set<Integer> set;
    private int n;


    public Solution(int N, int[] blacklist) {
        

        if (blacklist.length < (N >> 1)) {
            type = true;
            set = IntStream.of(blacklist).boxed().collect(Collectors.toSet());
            n = N;
            return;
        }
        Arrays.sort(blacklist);
        if (blacklist.length == 0) {
            white = IntStream.range(0, N).boxed().collect(Collectors.toList());
            return;
        }


        white = new ArrayList<>();
        List<Integer> s1 = IntStream.range(0, blacklist[0]).boxed().collect(Collectors.toList());
        if (!s1.isEmpty() && blacklist[0] != 0) {
            white.addAll(s1);
        }

        for (int i = 0; i < blacklist.length; i++) {

            if (i + 1 >= blacklist.length) {

                white.addAll(IntStream.range(blacklist[i] + 1, N).boxed().collect(Collectors.toList()));
                break;
            } else if (blacklist[i] != blacklist[i + 1] - 1) {
                white.addAll(IntStream.range(blacklist[i] + 1, blacklist[i + 1]).boxed().collect(Collectors.toList()));
            }
        }


    }

    public int pick() {
        if (type) {
            int i;
            while ((true)) {
                if (!set.contains(i = random.nextInt(n))) {
                    return i;
                }
            }
        }
        return white.get(random.nextInt(white.size()));
    }


}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
```