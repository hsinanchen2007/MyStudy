    
    class Solution {  
        public List<String> generateParenthesis(int n) {
            List<String> res = new ArrayList<>();
            StringBuilder sb = new StringBuilder();
            dfs(0, 0, n, sb, res);
            return res;
        }

        public void dfs(int left, int right, int n, StringBuilder sb, List<String> res) {
            if(left == n && left == right) {
                res.add(sb.toString());
                return;
            }
            if(left == right) {
                sb.append("(");
                dfs(left + 1, right, n, sb, res);
                sb.deleteCharAt(sb.length() - 1);
            }
            if(left > right) {
                if(left < n) {
                    sb.append("(");
                    dfs(left + 1, right, n, sb, res);
                    sb.deleteCharAt(sb.length() - 1);
                }
                sb.append(")");
                dfs(left, right + 1, n, sb, res);
                sb.deleteCharAt(sb.length() - 1);
            }
        }
    }