```
class Solution {
    private HashMap<String, Character> map = new HashMap<>();   //key: i+" "+j   value:该位置的字符
    private int left = 0, right = 0, bottom = 0, top = 0;   //记录边界位置
    private int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};    //顺时针方向
    private char[] directionsWithCharacter = {'R', 'D', 'L', 'U'};  //与上一个数组一一对应
    private int dir = 0;    //上两个方向数组的下标。当前为'_'，dir向右走，反之向左。
    public List<String> printKMoves(int K) {
        helper(0, 0, K);    //获得map
        List<String> res = new ArrayList<>();
        for (int i = top; i <= bottom; i++) {       //组合字符，并返回答案
            StringBuilder sb = new StringBuilder();
            for (int j = left; j <= right; j++) {
                String s = i + " " + j;
                char c = map.getOrDefault(s, '_');
                sb.append(c);
            }
            res.add(sb.toString());
        }
        return res;
    }
    private void helper(int x, int y, int K) {
        top = Math.min(top, x);       //是否改变界限
        bottom = Math.max(bottom, x);
        left = Math.min(left, y);
        right = Math.max(right, y);
        String s = x + " " + y;     //key
        char c = map.getOrDefault(s, '_');
        map.put(s, c == '_' ? 'X' : '_');   //反转
        if (K == 0) {   //递归边界，当前朝向放进去，返回
            map.put(s, directionsWithCharacter[dir % 4]);
            return;
        }
        if (c == '_') {     //按顺时针方向走
            dir = (dir + 1) % 4;
        } else {            //按逆时针方向走
            dir = (dir - 1 + 4) % 4;
        }
        int newX = x + directions[dir % 4][0];  //下一个位置
        int newY = y + directions[dir % 4][1];
        helper(newX, newY, K - 1);
    }
}
```
