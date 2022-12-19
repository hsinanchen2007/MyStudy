```
class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        // 第一个数前面加左括号
        // 最后一个数后面加右括号
        // 符号后，数字前加左括号
        // 符号前，数字后加右括号
        // 带着括号算数？递归一层层剥离
        // 从前往后算
        // 没涵盖完所有情况
        List<Integer> rs = new ArrayList<>();
        rs.addAll(cal(input));
        return rs;
    }

    private List<Integer> cal(String s) {
        // 哪两个数先算的问题
        // 两种情况
        List<Integer> rs = new ArrayList<>();
        int r = 0;
        while(r < s.length()) {
            while(r < s.length() && s.charAt(r) >= '0' && s.charAt(r) <= '9')
                r ++;
            if(r == s.length()) {
                if(rs.isEmpty()) {
                    rs.add(Integer.parseInt(s));
                }    
                return rs;
            }
            char op = s.charAt(r);
            List<Integer> rs1 = cal(s.substring(0, r));
            List<Integer> rs2 = cal(s.substring(r + 1, s.length()));
            //System.out.println("r1: " + s.substring(0, r));
            //System.out.println("r2: " + s.substring(r + 1, s.length()));
            addup(rs, rs1, op, rs2);
            r ++;
        }
        return rs;
    }   

    private void addup(List<Integer> rs, List<Integer> rs1, char op, List<Integer> rs2) {
        for(int i1 : rs1) {
            for(int i2 : rs2)
                rs.add(add(i1, op, i2));
        }
    }

    private int add(int c, char op, int n) {
        switch (op) {
            case '+':
                return c + n;
            case '-':
                return c - n;
            case '*':
                return c * n;
            default:
                return 0;
        }
    }
}
```
