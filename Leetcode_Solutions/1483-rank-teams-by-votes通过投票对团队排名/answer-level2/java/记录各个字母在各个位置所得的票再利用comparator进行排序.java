### 解题思路
记录各个字母在各个位置所得的票再利用comparator进行排序。

### 代码

```java
class Solution {
    public String rankTeams(String[] votes) {
        //投票人数
        int voters = votes.length;
        //队伍总数
        int teamNum = votes[0].length();
        if(teamNum == 1 || voters == 1)
            return votes[0];
        //记录票数
        int[][] chars = new int[26][teamNum];
        for(int i = 0; i < voters; i++){
            for(int j = 0; j < teamNum; j++){
                chars[votes[i].charAt(j) - 65][j]++;
            }
        }
        //comparator比较的是对象，因此建立Character数组
        Character[] res = new Character[teamNum];
        for (int i = 0; i < teamNum; i++) {
            res[i] = new Character(votes[0].charAt(i));
        }
        //排序
        Arrays.sort(res, new Comparator<Character>(){
            @Override
            public int compare(Character c1, Character c2){
                for(int i = 0; i < teamNum; i++){
                    if(chars[c1 - 65][i] > chars[c2 - 65][i])
                        return -1;
                    if(chars[c1 - 65][i] < chars[c2 - 65][i])
                        return 1;
                }
                return c1 - c2;
            }
        });
        //将排序结果转为String
        char[] temp = new char[teamNum];
        for (int i = 0; i < teamNum; i++) {
            char c = res[i];
            temp[i] = c;
        }
        return String.valueOf(temp);
    }
}
```