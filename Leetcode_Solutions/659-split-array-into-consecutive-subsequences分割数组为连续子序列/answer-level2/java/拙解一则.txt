### 解题思路
遵循以下几个原则：
1.子序列数小于数组长度/3
2.优先把数字拼到已有的子序列末尾
3.如果数字能够拼到多个子序列末尾，优先拼到最短的子序列末尾
4.如果不能拼，另起一行
5.无法另起一行则返回false
6.最终检查是否有长度小于3大于0的子序列

### 代码

```java
class Solution {
        private static int minQueueSize = 3;

    /**
     * 如果等于+1 放在候选者中
     * 找出第一个空队列用于存放下一行的开始
     * 如果候选者为空
     * 放在第一个空队列中
     * 如果候选者不为空
     * 放在最短候选者的队尾
     *
     * @param input
     * @return
     */
        public static boolean isPossible(int[] input) {
        int length = input.length;
        int lineMaxNum = length / minQueueSize;
        if (input.length < minQueueSize) {
            return false;
        }
        List<Integer>[] output = new ArrayList[lineMaxNum];
        for (int x = 0; x < lineMaxNum; x++) {
            output[x] = new ArrayList<>();
        }
        List<Integer> list1 = output[0];
        list1.add(input[0]);
        int i = 1;
        while (i < length) {
            int value = input[i];
            List<List<Integer>> tempList = new ArrayList<>();
            List<Integer> firstEmpty = null;
            for (int j = 0; j <= lineMaxNum - 1; j++) {
                List<Integer> list = output[j];
                if (list.isEmpty()) {
                    firstEmpty = list;
                    break;
                }
                int max = list.size();
                if (list.get(max - 1) + 1 == value) {
                    tempList.add(list);
                }
            }
            if (!tempList.isEmpty()) {
                List<Integer> list = getShortestList(tempList);
                list.add(value);
            } else if (null != firstEmpty) {
                firstEmpty.add(value);
            } else {
                return false;
            }
            i++;
        }
        for (List<Integer> list : output) {
//            System.out.println(list.toString());
            if (list.size() < 3 && list.size() > 0) {
                return false;
            }
        }

        return true;
    }

    private static List<Integer> getShortestList(List<List<Integer>> candidate) {
        int index = 0;
        for (List<Integer> list : candidate) {
            if (list.size() < candidate.get(index).size()) {
                index = candidate.indexOf(list);
            }
        }
        return candidate.get(index);
    }

}
```