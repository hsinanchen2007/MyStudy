代码如下，思路见注释

class Solution {
    
    public String predictPartyVictory(String senate) {
        int length = senate.length();
        boolean[] deleted = new boolean[length];
        for (int i = 0; i < deleted.length; i++) {
            deleted[i] = false;
        }
        while (true) {
            int rUnused = 0;/*本轮中已遍历但尚未投票的R数量*/
            int dUnused = 0;
            int rLived = 0;/*本轮中已遍历剩余存活的R数量*/
            int dLived = 0;
            for (int i = 0; i < length; i++) {
                if (deleted[i]) {
                    continue;
                }
                char ch = senate.charAt(i);
                if (ch == 'R') {
                    if (dUnused == 0) {/*说明本节点不会被前面的敌人投死，会暂时存活下来*/
                        rLived++;
                        /*活下来的节点优先弄死其后面的敌人，防止他们投票*/
                        rUnused++;
                    } else {/*说明本节点会被前面的敌人投死,无投票权*/
                        dUnused--;
                        deleted[i] = true;
                    }
                } else if (ch == 'D') {
                    if (rUnused == 0) {
                        dLived++;
                        dUnused++;
                    } else {
                        rUnused--;
                        deleted[i] = true;
                    }
                }
            }
            if (rUnused > 0) {
                dLived -= rUnused;
            }
            if (dUnused > 0) {
                rLived -= dUnused;
            }

            if (rLived <= 0) {
                return "Dire";
            }
            if (dLived <= 0) {
                return "Radiant";
            }
            /*标记该死的节点*/
            for (int i = 0; i < length; i++) {
                if (dUnused == 0 && rUnused == 0) {
                    break;
                }
                char ch = senate.charAt(i);
                if (!deleted[i] && ch == 'R' && dUnused-- > 0) {
                    deleted[i] = true;
                }
                if (!deleted[i] && ch == 'D' && rUnused-- > 0) {
                    deleted[i] = true;
                }
            }
        }
    }
}