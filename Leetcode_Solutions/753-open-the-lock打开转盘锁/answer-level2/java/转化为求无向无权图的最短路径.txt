```
public class Solution {
    /**
     * 1. 问题分析
     *  "0000" --> target 求从"0000"到target需要的最小的旋转次数
     *  把"0000"和从"0000"到target每一次旋转后的数字都当成是一种状态
     *  整个问题就可以看成是从一种状态到另一种状态需要经过的最小路径
     *
     *  2. 经过上述分析, 脑海中应该可以浮现出求无权无向图的最短路径
     *
     *  3. 找到图的顶点和边, 使用BFS即可解决问题
     *      顶点: 所有的状态
     *      边: 不在deadends中的状态都相连
     */
    public int openLock(String[] deadends, String target) {
        // 因为后面会不断判断一个状态是否在deadends中,
        // 所以先定义一个hashset存储deadends中的状态
        HashSet<String> deadset = new HashSet<>(Arrays.asList(deadends));

        // 处理边界条件
        if (deadset.contains("0000")) return -1;
        if (deadset.contains(target)) return -1;
        if (target.equals("0000")) return 0;

        // BFS
        // - 需要定义一个visited存储每一个状态是否被访问过
        //   可以使用hashset保存被访问过的状态
        // - 还需要定义一个dis记录从"0000"到另外一个状态需要经过多少步
        //   可以使用一个hashmap保存字符串-->整数之间的映射
        // - 通过上面的分析可看出使用一个hashmap即可保存一个状态是否被访问过和其到"0000"经过的步数
        HashMap<String, Integer> visited = new HashMap<>();
        Queue<String> queue = new LinkedList<>();
        visited.put("0000", 0);
        queue.add("0000");

        while (!queue.isEmpty()) {
            String curs = queue.remove();
            // 把可以从curs通过转动一次锁之后所有的可能存储在一个ArrayList中
            ArrayList<String> nexts = new ArrayList<>();
            // TODO: nexts
            char[] curarray = curs.toCharArray();
            for (int i = 0; i < 4; i ++) {
                char o = curarray[i];
                // 第i位数字往上拨动一位
                curarray[i] = Character.forDigit ((curarray[i] - '0' + 1) % 10, 10);
                nexts.add(new String(curarray));
                curarray[i] = o;
                // 第i位数字往下拨动一位
                curarray[i] = Character.forDigit ((curarray[i] - '0' + 9) % 10, 10);
                nexts.add(new String(curarray));
                curarray[i] = o;
            }

            for (String next : nexts) {
                if (!deadset.contains(next) && !visited.containsKey(next)) {
                    queue.add(next);
                    visited.put(next, visited.get(curs)+1);

                    if (next.equals(target)) {
                        return visited.get(next);
                    }
                }
            }
        }

        return -1;
    }
}

```
