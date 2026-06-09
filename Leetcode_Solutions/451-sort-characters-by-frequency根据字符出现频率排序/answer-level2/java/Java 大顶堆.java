### 解题思路
Java 大顶堆
执行用时 :4 ms, 在所有 Java 提交中击败了99.71%的用户
内存消耗 :37.3 MB, 在所有 Java 提交中击败了98.86%的用户

首先这里采用常规方法统计字符频率 这里固定申请了256个空间完全够常用字符集了，当然这里也是可优化的点。
当我们统计到字符频率的时候，就可以利用堆排序将频率高的字符进行“上浮”，最后我们在遍历的时候就是频率最高字符在首位，然后再一次打印即可。
### 代码

```java
class Solution {
 public String frequencySort(String s) {
        //初始化字母数组
        int[] latters = new int[256];
        //填充数组
        for(char c:s.toCharArray()){
            latters[c]++;
        }
        //排序
        PriorityQueue<Latter> queue = new PriorityQueue<>();

        for (int i = 0;i<latters.length;i++){
            if (latters[i]!=0){
                queue.add(new Latter((char) i,latters[i]));
            }
        }
        StringBuilder stringBuilder = new StringBuilder();

        while (!queue.isEmpty()){
            Latter latter = queue.poll();
            for (int i =0;i<latter.count;i++)
                stringBuilder.append(latter.latter);
        }


        return stringBuilder.toString();
    }

    public class Latter implements Comparable<Latter>{
        public char latter = '0';
        public int count = 0;

        public Latter(char latter, int count) {
            this.latter = latter;
            this.count = count;
        }

        @Override
        public int compareTo(Latter o) {
            return o.count - this.count;
        }
    }
}
```