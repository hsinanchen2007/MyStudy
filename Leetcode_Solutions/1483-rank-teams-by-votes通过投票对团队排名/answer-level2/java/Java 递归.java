由题知 votes[i].length == votes[j].length for 0 <= i, j < votes.length 即每个投票所涉及的队伍是一样多且不重复的，可以创建一个int[][]结构存储每个队伍获得第几名的投票数量，然后根据此查找排名
对于每次查找排名（便于索引，参数rank比实际排名少1），我建立了两个结构：**team**, **failTeam** 存储有可能争得此的队伍集，和在争夺中失败的队伍集
1. 排名小于等于总参赛队伍(TEAMS in *fandRank*)时
    - 若**team**只有一个队伍，则该队伍获得当前排名，排名字符串增加该队伍，**failTeam**继续争夺余下排名
    - 若**team**有多个队伍，则参考下一排名投票，直到完全排序该队伍集后，**failTeam**继续争夺余下排名
2. 排名大于总参赛队伍(TEAMS in *fandRank*)且CHECKTEAMS不为空集时，说明该队伍集排名并列，按照字母表顺序排序后返回排名字符串
3. 其余情况返回空字符串
```
class Solution {
    public String rankTeams(String[] votes) {
        List<String> teams = new LinkedList<>(Arrays.asList(votes[0].split("")));
        int[][] scores = new int[teams.size()][teams.size()];
        for (int j = 0; j < teams.size(); j++) {
            for (int i = 0; i < votes.length; i ++) {
                scores[j][teams.indexOf(votes[i].substring(j, j + 1))]++;
            }
        }
        return findRank(scores, 0, teams, teams);
    }

    public String findRank(int[][]scores, int rank, List<String> teams, List<String>  checkTeams) {
       if (rank < teams.size() && !checkTeams.isEmpty()) {
            int maxSocre = 0;
            List<String> team = new LinkedList<>();
            List<String> failTeam = new LinkedList<>();
            for (int i = 0; i < checkTeams.size(); i++) {
                if (scores[rank][teams.indexOf(checkTeams.get(i))] > maxSocre) {
                    maxSocre = scores[rank][teams.indexOf(checkTeams.get(i))];
                    failTeam.addAll(team);
                    team.clear();
                    team.add(checkTeams.get(i));
                } else if (scores[rank][teams.indexOf(checkTeams.get(i))] == maxSocre) {
                    team.add(checkTeams.get(i));
                } else {
                    failTeam.add(checkTeams.get(i));
                }
            }
            if (team.size() == 1) {
                return team.get(0) + findRank(scores, rank, teams, failTeam);
            } else {
                String result = findRank(scores, rank + 1, teams, team);
                if (failTeam.isEmpty()) {
                    return result;
                } else {
                    return result + findRank(scores, rank, teams, failTeam);
                }
            }
        } else if (rank == teams.size() && !checkTeams.isEmpty()) {
            Collections.sort(checkTeams);
            String result = "";
            for (String i : checkTeams.toArray(new String[checkTeams.size()])) {
                result += i;
            }
            return result;
        } else {
            return "";
        }
    }
}
```
