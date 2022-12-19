    
    class Solution {
        public List<String> res = new ArrayList<String>();
        public List<String> restoreIpAddresses(String s) {
            List<Integer> list = new ArrayList<>();
            dfs(0,s,list);
            return res;
        }

        public void dfs(int index, String s, List<Integer> list) {
            if(list.size() < 4 && index == s.length()) {   //不满足回溯
                return;
            }
            if(list.size() == 4 && index == s.length()) {  //满足记录一下结果
                StringBuilder sb = new StringBuilder();
                sb.append(list.get(0));
                for(int i = 1;i < list.size();i++) {
                    sb.append("." + list.get(i));
                }
                res.add(sb.toString());
                return;
            }
            if(list.size() > 4 && index <= s.length()) {   //不满足回溯
                return;
            }
            
            int range = 3;
            if(s.charAt(index) == '0') {      //0需要特殊处理一下
                range = 1;
            }
            
            for(int len = 1;len <= range;len++) {
                if(index + len <= s.length()) {
                    int num = Integer.parseInt(s.substring(index, index + len));
                    if(num <= 255) {
                        list.add(num);
                        dfs(index + len,s,list);
                        list.remove(list.size() - 1);
                    }
                }
            }
        }
    }