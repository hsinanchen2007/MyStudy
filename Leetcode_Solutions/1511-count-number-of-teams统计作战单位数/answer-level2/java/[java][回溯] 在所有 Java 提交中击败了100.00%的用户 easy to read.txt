### run
执行用时 : 232ms，在所有 Java 提交中击败了100.00%的用户
内存消耗 :40.6 MB, 在所有 Java 提交中击败了100.00%的用户

### 解题思路

本质是是回溯问题，可以参考`subset`系列和`combination`系列问题。

临时写的代码有点啰嗦了，优化空间应该不小，各位可以post上来。

### 代码

```java
class Solution {
    public int numTeams(int[] rating) {
        if(rating == null || rating.length < 3) {
            return 0;
        }

        int[] res = {0};
        helper(rating, res, new ArrayList<>(), 0);

        return res[0];
    }

    private void helper(int[] rating, int[] res, List<Integer> temp, int sta) {
        if(temp.size() >= 3) {
            
            return;
        }

        for(int i=sta; i<rating.length; i++) {

            if(temp.size() == 0) {
                temp.add(rating[i]);
                helper(rating, res, temp, i+1);
                temp.remove(temp.size()-1);
            } else {
                if(rating[i] == temp.get(temp.size()-1)){
                    continue;
                }

                if(temp.size() == 1) {
                    temp.add(rating[i]);
                    helper(rating, res, temp, i+1);
                    temp.remove(temp.size()-1);
                }
                if(temp.size() == 2) {
                    if((temp.get(0) > temp.get(1)) ^ (temp.get(1) > rating[i])) {
                        continue;
                    }

                    res[0] += 1;
                }
            }
        }
    }
}
```