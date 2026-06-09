### 解题思路
![image.png](https://pic.leetcode-cn.com/657ca97ff856b0e018fa1c42f6ff3cc80ab63f1df8c257ec903ba052ab333123-image.png)

最开始尝试将每个节点作为根节点，然后求出最短的那些。并用记忆法减少重复计算，但是事件复杂度过高。
然后使用拖布排序，但是空间复杂度过高
之后将邻接表从数组换成List<HashSet<Integer>>，总算做出来了。
### 代码

```java
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if(edges.length == 0) {
            List<Integer> rr = new ArrayList<>();
            rr.add(0);
            return rr;
        }
        int[] rudu = new int[n];
//        int[][] map = new int[n][n];
        List<HashSet<Integer>> map = new ArrayList<>();
        for(int i = 0; i < n; ++i){
            map.add(new HashSet<>());
        }
        for(int[] i : edges){
            map.get(i[0]).add(i[1]);
            map.get(i[1]).add(i[0]);
            rudu[i[1]]++;
            rudu[i[0]]++;
        }
        int total = n;
        while(total > 2){
            // this.print(rudu);/////////////////
            List<Integer> list = new ArrayList<>();
            for(int i = 0; i < rudu.length; ++i){
                if(rudu[i] == 1){
                    list.add(i);
                }
            }
            for(int ii : list){
                int ling = 0;
                for(int j : map.get(ii)){
                    ling = j;
                    break;
                }
                map.get(ii).remove(ling);
                map.get(ling).remove(ii);
                rudu[ii]--;
                total--;
                if(total == 1){
                    List<Integer> r = new ArrayList<>();
                    r.add(ling);
                    return r;
                }
                rudu[ling]--;
            }
        }
        List<Integer> res = new ArrayList<>();
        for(int i = 0; i < n; ++i){
            if(rudu[i] != 0){
                res.add(i);
            }
        }
        // this.print(rudu);///////////////////
        return res;
    }
    public void print(int[] a){
        for(int i : a){
            System.out.printf("%d ", i);
        }
        System.out.printf("\r\n");
    }
}
```