```
class Solution {
    private int getIndex(char c){
        return c - 'A';
    }

    public String rankTeams(String[] votes) {
        int[][] ranks = new int[26][26];
        for (int i = 0; i < 26; i++) {
            Arrays.fill(ranks[i], 0);
        }

        // String to Character[] 有没有好一点的办法，求助。
        Character[] cs = new Character[votes[0].length()];
        int ci = 0;
        for (Character c:votes[0].toCharArray()) {
            cs[ci++] = c;
        }
        
        for (String vote: votes) {
            for (int i = 0; i < vote.length(); i++) {
                ranks[getIndex(vote.charAt(i))][i] ++;
            }
        }
        Arrays.sort(cs, (c1, c2)->{
            int i1 = getIndex(c1);
            int i2 = getIndex(c2);
            for (int ii = 0; ii < 26; ii++) {
                if(ranks[i1][ii] != ranks[i2][ii]) 
                    return ranks[i2][ii] - ranks[i1][ii];
            }
            return i1 - i2;
        });

        // Character[] to String 有没有好一点的办法，求助。
        StringBuilder sb = new StringBuilder();
        for(char cg: cs)
            sb.append(cg);
        return sb.toString();
    }
}
```
感觉时间主要在读取一个个投票的，填充数组那边。是O(m*n) 排序O(nlogn) (n是参赛队伍个数)
空间复杂度 O(1)。固定的，最多 26*26