补一个java版本的，最开始超时，后来优化Map的遍历 空间换时间过了 ^_^

思路：
    1. 先判断组间依赖，如果有循环依赖则返回；如果没有循环依赖则进行组间拓扑排序
    2. 再判断组内依赖，如果组内有循环依赖则返回；如果没有循环依赖则进行组内拓扑排序


```
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

/**
 * 1203. 项目管理  ——拓扑排序
 * <p>
 * 执行用时 : 1259 ms , 在所有 java 提交中击败了 6.45% 的用户
 * 内存消耗 : 58.9 MB , 在所有 java 提交中击败了 100.00% 的用户
 * <p>
 * 公司共有 n 个项目和  m 个小组，每个项目要不没有归属，要不就由其中的一个小组负责。
 * 我们用 group[i] 代表第 i 个项目所属的小组，如果这个项目目前无人接手，那么 group[i] 就等于 -1。（项目和小组都是从零开始编号的）
 * 请你帮忙按要求安排这些项目的进度，并返回排序后的项目列表：
 * 同一小组的项目，排序后在列表中彼此相邻。
 * 项目之间存在一定的依赖关系，我们用一个列表 beforeItems 来表示，其中 beforeItems[i] 表示在进行第 i 个项目前（位于第 i 个项目左侧）应该完成的所有项目。
 * 结果要求：
 * 如果存在多个解决方案，只需要返回其中任意一个即可。
 * 如果没有合适的解决方案，就请返回一个 空列表。
 * <p>
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/sort-items-by-groups-respecting-dependencies
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * @author 
 * @since 2019-11-21
 */
class ProjectManagement {
    /**
     * 思路：
     * 1. 先判断组间依赖，如果有循环依赖则返回；如果没有循环依赖则进行组间拓扑排序
     * 2. 再判断组内依赖，如果组内有循环依赖则返回；如果没有循环依赖则进行组内拓扑排序
     *
     * @param n
     * @param m
     * @param group
     * @param beforeItems
     * @return
     */
    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
        if (group == null && group.length == 0 && beforeItems == null && beforeItems.size() == 0) {
            return new int[0];
        }

        // 将项目依赖转换为组依赖
        Map<Integer, List<Integer>> beforeGroup = genGroupDepends(group, beforeItems, n, m);

        // 对组进行拓扑排序,如果组间存在环，则返回空数组
        List<Integer> sortedGroup = sortTarget(beforeGroup);
        if (sortedGroup == null) {
            return new int[0];
        }

        // 对每个组内元素进行拓扑排序
        List<Integer> sortedItem = new ArrayList<>();
        Map<Integer, List<Integer>> beforePro;
        for (int groupId : sortedGroup) {
            if (groupId >= n) {
                // 针对组为-1的项目
                sortedItem.add(groupId - n);
            } else {
                // 针对已分配组的项目
                beforePro = genItemDepends(group, beforeItems, groupId);
                List<Integer> sortedPro = sortTarget(beforePro);
                // 如果组间存在环，则返回空数组
                if (sortedPro == null) {
                    return new int[0];
                }
                sortedItem.addAll(sortedPro);
            }
        }

        return sortedItem.stream().mapToInt(Integer::valueOf).toArray();
    }

    private Map<Integer, List<Integer>> genGroupDepends(int[] group, List<List<Integer>> beforeItems, int base,
        int capacity) {
        Map<Integer, List<Integer>> beforeGroup = new HashMap<>(capacity);
        for (int i = 0; i < base; i++) {
            // 生成组ID，其中针对未分配的组（-1），根据base+item生成唯一的ID
            int current = group[i] == -1 ? base + i : group[i];

            // 如果无依赖，依然需要加入beforeGroup
            if (beforeItems.get(i) == null || beforeItems.get(i).size() == 0) {
                // 当前组无依赖，加入加入空链表；有依赖时continue
                if (beforeGroup.get(current) == null) {
                    beforeGroup.put(current, new ArrayList<>());
                }
                continue;
            }

            for (Integer item : beforeItems.get(i)) {
                // 生成目标元素组ID
                int target = group[item] == -1 ? base + item : group[item];

                // 加入beforeGroup
                List<Integer> targets = beforeGroup.get(current);
                if (targets == null) {
                    List<Integer> groups = new ArrayList<>();
                    if (target != current) {
                        groups.add(target);
                    }
                    beforeGroup.put(current, groups);
                } else if (target != current && !targets.contains(target)) {
                    targets.add(target);
                }
            }
        }

        return beforeGroup;
    }

    private List<Integer> sortTarget(Map<Integer, List<Integer>> dependences) {
        List<Integer> result = new LinkedList<>();
        // 度为0的节点入队
        Queue<Integer> queue = new LinkedList<>();
        dependences.forEach((k, v) -> {
            if (v.size() == 0) {
                queue.offer(k);
            }
        });
        for (Integer target : queue) {
            dependences.remove(target);
        }

        // 空间换时间
        List<Integer> buff = new ArrayList<>();
        while (!queue.isEmpty()) {
            Integer target = queue.poll();
            result.add(target);

            dependences.forEach((k, v) -> {
                if (v.contains(target)) {
                    v.remove(v.indexOf(target));
                    if (v.size() == 0) {
                        queue.offer(k);
                        buff.add(k);
                    }
                }
            });

            for (Integer element : buff) {
                dependences.remove(element);
            }
            buff.clear();
        }

        return dependences.isEmpty() ? result : null;
    }

    private Map<Integer, List<Integer>> genItemDepends(int[] group, List<List<Integer>> beforeItems, int groupId) {
        Map<Integer, List<Integer>> beforePro = new HashMap<>();
        for (int k = 0; k < group.length; k++) {
            if (group[k] == groupId) {
                if (beforeItems.get(k) == null || beforeItems.get(k).size() == 0) {
                    beforePro.put(k, new ArrayList<>());
                } else {
                    List<Integer> items = new ArrayList<>();
                    beforeItems.get(k).forEach(item -> {
                        if (group[item] == groupId) {
                            items.add(item);
                        }
                    });
                    beforePro.put(k, items);
                }
            }
        }
        return beforePro;
    }
```