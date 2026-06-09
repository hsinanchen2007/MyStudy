z的处理，是一个关键。先上或者左，在下或者右。

class Solution {
    public String alphabetBoardPath(String target) {
        String restr = "";
        Map<Character, String> letmap = new HashMap<>();

        for (int i = 0; i < 5; i++) {//列
            for (int j = 0; j < 5; j++) {//行
                String addstr = Integer.toOctalString(i) + ":" + Integer.toOctalString(j);
                //    System.out.println("XVALUE");
                letmap.put((char) (i * 5 + j + 97), addstr);
            }
        }

        letmap.put('z', "5:0");

        int curR = 0;//行
        int curL = 0;//列
        for (char c : target.toCharArray()) {
            String tmpstr = letmap.get(c);
            int nowR = Integer.parseInt(Character.toString(tmpstr.charAt(0)));//列
            int nowL = Integer.parseInt(Character.toString(tmpstr.charAt(2)));//行
            Boolean isz = false;
            if (nowR == 5 && curR!=5) {
                isz = true;
                nowR = 4;
            }

            if (nowR - curR > 0) {
                //向下走N步  'D'
            for (int k = 0; k < nowR - curR; k++) {
                    restr = restr + "D";
                }
                curR = nowR;
            } else if (nowR - curR < 0) {
                //向上走N步 'U'
                for (int k = 0; k < curR - nowR; k++) {
                    restr = restr + "U";
                }
                curR = nowR;
            }

            if (nowL - curL > 0) {//行
                for (int k = 0; k < nowL - curL; k++) {
                    restr = restr + "R";
                }
                curL = nowL;
                //向右走N步
            } else if (nowL - curL < 0) {
                for (int k = 0; k < curL - nowL; k++) {
                    restr = restr + "L";
                }
                curL = nowL;
                //向左走N步  'L'
            }
            if (isz) {
                restr = restr + "D";
              //  nowR = 5;
                curR = 5;
            }
            restr = restr + "!";
        }
        return restr;

    }
}