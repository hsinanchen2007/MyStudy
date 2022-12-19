### 解题思路
看了大佬后的代码才写出来的，自己还是太菜。
加油呀！
最开始想到的是DFS，想的思路是找最大数max，每次用n减去max*max，如果n小于0，就回溯，可是n不可能小于0，因为有1这个完全平方数

用DFS把所有的实现都写出来，然后选择一个最小的，方法很笨拙，就当加深自己对于知识的理解好了。

### 代码

```java
class Solution {
    public int numSquares(int n) {
        int level = 0;
        Set<Integer> set = new HashSet<>();
        List<Integer> list = new ArrayList<>();
        list.add(n);
        set.add(n);
        while (list.size() != 0){
            int len = list.size();
            while (len-- != 0){
                Integer remove = list.remove(0);
                if (remove == 0)
                    return level;
                int k = findI(n);
                for(int i = 1;i <= k;i++){
                    int x = remove-i*i;
                    if (!set.contains(x)){
                        list.add(x);
                        set.add(x);
                    }
                }
            }
            level++;
        }
        return -1;
    }

    private int findI(int n){
        int i = 1;
        while (i*i <= n)
            i++;
        return i-1;
    }
}
```

```java
DFS 其中result[0]为最小次数，result[1]为总次数。
public int numSquares1(int n){
        int[] result  = new int[2];
        result[0] = Integer.MAX_VALUE;
        result[1] = 0;
        dfs(n,new ArrayList<>(),result);
        System.out.println("all -> :"+result[1]);
        System.out.println("min -> :"+result[0]);
        return result[0];
    }

    private void dfs(int n,List<Integer> list,int[] min){
        if (n == 0){
            min[1] = min[1] + 1;
            if (list.size() < min[0])
                min[0] = list.size();
            return;
        }
        int i = findI(n);
        for(int k= 1;k <= i;k++){
            list.add(k);
            dfs(n-k*k,list,min);
            list.remove(list.size()-1);
        }
    }
```