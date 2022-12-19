### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sortByBits(int[] arr) {
        LinkedList<Pair> list = new LinkedList<>();
        for (int i : arr) {
            list.add(new Pair(i, (int) Integer.toBinaryString(i).chars().filter(ch -> ch == '1').count()));
        }
        Collections.sort(list, (o1, o2) -> o1.count - o2.count == 0 ? o1.i - o2.i : o1.count - o2.count);
        return list.stream().mapToInt(Pair::getI).toArray();
    }
    static class Pair {
        int i;

        int count;

        public Pair(Integer key, int counter) {
            i = key;
            count = counter;
        }

        public int getI() {
            return i;
        }

        public void setI(int i) {
            this.i = i;
        }
    }
}
```