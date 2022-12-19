### 解题思路
这个题通过提示可以知道使用两层拓扑排序，但是坑还是挺多的。
1.需要给单独的项目创建一个组
2.需要通过项目ID找到关联的组，同时需要维护组本身的序列
一开始想图省事，用一个group[]表示，后来发现这样有耦合问题。改用List维护组本身，用数组维护项目到组的映射关系，初始化List为m个，如果遇到单独的项目，
则把当前List大小设置为组ID分配给这个项目。通过这个解决了项目ID和组ID耦合的问题。

![image.png](https://pic.leetcode-cn.com/67439b02f3c3e0d2d520e66187b71e679d42ea42067617411a82079223023f12-image.png)

### 代码

```java
class Solution {
    static class Item {
        int id;

        int inputCnt;

        List<Integer> nextItems = new ArrayList<>();

        Item(int id) {
            this.id = id;
        }
    }

    static class Group {
        int id;

        int inputCnt;

        List<Integer> items = new ArrayList<>();

        List<Group> nextGroups = new ArrayList<>();

        Group(int id) {
            this.id = id;
        }
    }

    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
        Item[] items = new Item[n];
        Group[] itemToGroup = new Group[n];
        List<Group> oriGroups = new ArrayList<>();

        for (int j = 0; j < m; j++) {
            oriGroups.add(new Group(j));
        }

        for (int i = 0; i < n; i++) {
            items[i] = new Item(i);
        }

        for (int i = 0; i < group.length; i++) {
            int groupId = group[i];
            if (groupId == -1) {// 项目不属于任何组
                Group temp = new Group(oriGroups.size());
                oriGroups.add(temp);
                temp.items.add(i);
                itemToGroup[i] = temp;
            } else {
                oriGroups.get(groupId).items.add(i);
                itemToGroup[i] = oriGroups.get(groupId);
            }
        }

        for (int i = 0; i < beforeItems.size(); i++) {
            List<Integer> array = beforeItems.get(i);
            items[i].inputCnt = array.size();
            for (Integer itemId : array) {
                items[itemId].nextItems.add(i);
                Group beforeGroup = itemToGroup[itemId];
                Group curGroup = itemToGroup[i];
                if (beforeGroup != curGroup) {
                    beforeGroup.nextGroups.add(curGroup);
                    curGroup.inputCnt++;
                }
            }
        }

        Queue<Group> groupQueue = new LinkedList<>();

        for (Group ele : oriGroups) {
            if (ele.inputCnt == 0) {
                groupQueue.offer(ele);
            }
        }

        if (groupQueue.isEmpty()) {
            return new int[0];
        }

        int[] result = new int[n];
        int resultIndex = 0;
        while (!groupQueue.isEmpty()) {
            int size = groupQueue.size();
            for (int i = 0; i < size; i++) {
                Group curGroup = groupQueue.poll();
                Queue<Integer> itemQueue = new LinkedList<>();
                if (curGroup.items.isEmpty()) {
                    continue;
                }

                for (int temp : curGroup.items) {
                    if (items[temp].inputCnt == 0) {
                        itemQueue.offer(temp);
                    }
                }

                if (itemQueue.isEmpty()) {
                    return new int[0];
                }

                while (!itemQueue.isEmpty()) {
                    int itemQueueSize = itemQueue.size();
                    for (int j = 0; j < itemQueueSize; j++) {
                        Integer itemId = itemQueue.poll();
                        result[resultIndex++] = itemId;
                        for (int nextItemId : items[itemId].nextItems) {
                            items[nextItemId].inputCnt--;
                            if (items[nextItemId].inputCnt == 0 && curGroup.items.contains(nextItemId)) {
                                itemQueue.offer(nextItemId);
                            }
                        }
                    }
                }

                for (int itemId : curGroup.items) {
                    if (items[itemId].inputCnt > 0) {
                        return new int[0];
                    }
                }

                for (Group nextGroup : curGroup.nextGroups) {
                    nextGroup.inputCnt--;
                    if (nextGroup.inputCnt == 0) {
                        groupQueue.offer(nextGroup);
                    }
                }
            }
        }

        for (Group ele : oriGroups) {
            if (ele.inputCnt > 0) {
                return new int[0];
            }
        }

        for (int k = 0; k < items.length; k++) {
            if (items[k].inputCnt > 0) {
                return new int[0];
            }
        }

        return result;
    }
}
```