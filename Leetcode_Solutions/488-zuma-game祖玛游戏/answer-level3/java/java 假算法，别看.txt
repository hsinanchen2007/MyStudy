**说在前面的话**
以下AC的1ms的代码是我看错题目的结果，漏看了题目说的 **接着，如果有出现三个或者三个以上颜色相同的球相连的话，就把它们移除掉** 这句话，我的算法碰到连续三个相同字符及以上的可能不会立马删除，而是放到后面再删除。但是也不能说明以下的算法是错误的，我在想，是否可以证明不立马删除连续三个相同及以上字符和立马删除连续三个相同及以上字符得到的结果是等价的。若能证明是等价的，则以下AC的算法就是正确的。（各位大佬如果知道怎么证明的，求告知~ 谢谢~）

**思路**
假设一个字符串"RWYWRRWRR"，我们可以根据连续的字符个数，分成三类：
1. 连续1个相同字符；如'R', 'W', 'Y'等。
2. 连续2个相同字符；如'RR'。
3. 连续3个及以上相同字符。（这种情况初始不可能存在，但是在删除过程中可能出现），如以上字符串先删掉最后一个'W',之后变成RWYWRRRR，后面会出现四个连续的R。

因此，我们递归遍历的时候，每次可以选择先删满足以上任意情况的任一连续的字符。具体代码如下：

```java
 private int ansMin = Integer.MAX_VALUE;

    private List<int[]> getIndexList(List<Character> boardList, int needCount) {
        int count = 1;
        int start = 0;
        List<int[]> posList = new ArrayList<>();
        for (int i = 1; i < boardList.size(); i++) {
            if (boardList.get(i) == boardList.get(i-1)) {
                count++;
            } else {
                // 需要考虑1，2，>=3个的情况
                if (needCount < 3) {
                    if (count == needCount) {
                        posList.add(new int[]{start, needCount});
                    }
                } else {
                    if (count >= 3) {
                        posList.add(new int[]{start, count});
                    }
                }

                count = 1;
                start = i;
            }
        }

        if (needCount < 3) {
            if (count == needCount) {
                posList.add(new int[]{start, needCount});
            }
        } else {
            if (count >= 3) {
                posList.add(new int[]{start, count});
            }
        }

        return posList;
    }

    private void rec(List<Character> boardList, int[] handCountMap, int useCount) {
        if (useCount >= ansMin) {
            return;
        }

        if (boardList.isEmpty()) {
            ansMin = Math.min(ansMin, useCount);
            return;
        }

        // 分成先删连续1个字符、连续2个字符，连续3个及以上字符
        // 对单个字符，可能需要填充两个字符, 对连续2个字符，需要填充一个字符。
        for (int i = 1; i <= 2; i++) {
            List<int[]> indexList = getIndexList(boardList, i);
            int needCount = 3 - i; // 需要多少才能凑到3个
            for (int[] pos: indexList) {
                int index = pos[0];
                char c = boardList.get(index);
                int leftCount = handCountMap[c - 'A'];
                if (leftCount >= needCount) {
                    handCountMap[c - 'A'] = leftCount - needCount;
                    List<Character> nextBoardList = new ArrayList<>(boardList);
                    for (int j = 1; j <= i; j++) {
                        nextBoardList.remove(index);
                    }
                    rec(nextBoardList, handCountMap, useCount + needCount);
                    handCountMap[c - 'A'] = leftCount;
                }
            }
        }

        // 可能先删连续三个字符及以上的连续字符
        List<int[]> treePosList = getIndexList(boardList, 3);
        for (int[] pos : treePosList) {
            int index = pos[0];
            int cnt = pos[1];
            List<Character> nextBoardList = new ArrayList<>();
            nextBoardList.addAll(boardList.subList(0, index));
            if (index + cnt < boardList.size()) {
                nextBoardList.addAll(boardList.subList(index + cnt, boardList.size()));
            }
            rec(nextBoardList, handCountMap, useCount);
        }
    }

    public int findMinStep(String board, String hand) {
        List<Character> boardList = new ArrayList<>();
        for (char c : board.toCharArray()) {
            boardList.add(c);
        }

        int[] handCountMap = new int[26];
        for (char c : hand.toCharArray()) {
            handCountMap[c - 'A']++;
        }

        rec(boardList, handCountMap, 0);
        return ansMin == Integer.MAX_VALUE ? -1 : ansMin;
    }
```