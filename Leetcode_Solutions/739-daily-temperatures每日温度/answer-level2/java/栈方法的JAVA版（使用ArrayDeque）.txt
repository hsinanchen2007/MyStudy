```
class Solution {
    public int[] dailyTemperatures(int[] T) {
        ArrayDeque<Integer> chun = new ArrayDeque(T.length);
        int[] result = new int[T.length];
        for(int i = 0;i<T.length;i++)
        {
            while(chun.isEmpty()==false&&T[i]>T[chun.getFirst()])
            {result[chun.getFirst()] = i-chun.getFirst();
            chun.pop();
            }
            chun.push(i);
        }
        return result;
    }
}
```
**也是官方题解的正向循环，因为JAVA推荐使用ArrayDeque，所以放弃使用stack。（Aver58的方法的JAVA版，详细思想请看Aver58的题解）**
