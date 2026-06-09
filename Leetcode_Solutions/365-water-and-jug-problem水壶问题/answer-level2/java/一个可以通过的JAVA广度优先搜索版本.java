![题解.JPG](https://pic.leetcode-cn.com/070d25d330a0402ddb86375694ca18a7412b0d6d1de0cb0e87033686c383d36d-%E9%A2%98%E8%A7%A3.JPG)

比较容易理解，没有什么高深的，就是六种状态，广度优先遍历搜索，虽然不快，但是符合人的逻辑思维

```
public boolean canMeasureWater(int x, int y, int z) {
        if (x + y < z) {
            return false;
        }
        if (x == 0 || y == 0) {
            return x == z || y == z;
        }
        Queue<List<Integer>> queue = new LinkedList<>();
        Set<List<Integer>> set = new HashSet<>();
        List<Integer> list = Arrays.asList(0, 0);
        queue.offer(list);
        set.add(list);

        while (!queue.isEmpty()) {
            List<Integer> temp = queue.poll();
            int cur_x = temp.get(0);
            int cur_y = temp.get(1);
            if (z == cur_x || z == cur_y || z == cur_x + cur_y) {
                return true;
            }
            //1、给x加满水
            List<Integer> condition1 = Arrays.asList(x, cur_y);
            if (!set.contains(condition1)) {
                set.add(condition1);
                queue.offer(condition1);
            }
            //2、给y加满水
            List<Integer> condition2 = Arrays.asList(cur_x, y);
            if (!set.contains(condition2)) {
                set.add(condition2);
                queue.offer(condition2);
            }
            //3、清空x的水
            List<Integer> condition3 = Arrays.asList(0, cur_y);
            if (!set.contains(condition3)) {
                set.add(condition3);
                queue.offer(condition3);
            }
            //4、清空y的水
            List<Integer> condition4 = Arrays.asList(cur_x, 0);
            if (!set.contains(condition4)) {
                set.add(condition4);
                queue.offer(condition4);
            }
            //5、x给y倒水
            List<Integer> condition5 = (cur_x + cur_y >= y) ?
                    Arrays.asList(cur_x + cur_y - y, y) :
                    Arrays.asList(0, cur_x + cur_y);
            if (!set.contains(condition5)) {
                set.add(condition5);
                queue.offer(condition5);
            }
            //6、y给x倒水
            List<Integer> condition6 = (cur_x + cur_y >= x) ?
                    Arrays.asList(x, cur_x + cur_y - x) :
                    Arrays.asList(cur_x + cur_y, 0);
            if (!set.contains(condition6)) {
                set.add(condition6);
                queue.offer(condition6);
            }
        }
        return false;
    }
```


