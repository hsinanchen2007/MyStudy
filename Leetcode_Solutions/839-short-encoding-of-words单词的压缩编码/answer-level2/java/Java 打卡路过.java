### 解题思路
没有看清题目，还以为不用#号结束的。放入队列从大到小，最大的不用比较，之后就endwith判定就好。时间复杂度O(n2) 空间复杂读O(n)

### 代码

```java
import java.util.Arrays;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;

public class Solution {
    public int minimumLengthEncoding(String[] words) {
        Set<String> set = new HashSet<>(Arrays.asList(words));
        PriorityQueue<String> pq = new PriorityQueue<>((i, j)-> j.length()-i.length());
        pq.addAll(set);
        Set<String> res = new HashSet<>();
        String largest = pq.poll();
        res.add(largest);
        while (!pq.isEmpty()){
            String cmp = pq.poll();
            if (cmp.length()==largest.length()){
                res.add(cmp);
            }else{
                boolean isContained = false;
                for (String s :res){
                    if (s.endsWith(cmp)){
                        isContained = true;
                        break;
                    }
                }
                if (!isContained) res.add(cmp);
            }
        }
        int ans = 0;
        for (String i : res){
            ans += i.length()+1;
        }
        return ans;
    }
}

```