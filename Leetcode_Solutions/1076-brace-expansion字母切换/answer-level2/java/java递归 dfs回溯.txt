class Solution {
      public String[] expand(String S) {
        if(!S.contains("{")) {
            return new String[]{S}; 
        }
        String s = S.replaceAll("\\{", " ").replaceAll("\\}", " ").replaceAll(",", "");
        String[] strs = s.split(" ");
        List<String> list = new ArrayList<>();
        for (int i = 0; i < strs.length; i++) {
            if (strs[i].length() != 0) {//"" length is 0
                list.add(strs[i]);
            }
        }
        
        List<String> listresult = new ArrayList<>();
        Stack<Character> stack = new Stack<>();
        backtraceDfs(list, 0, stack, listresult);
        
        Collections.sort(listresult);
        
        System.out.println(listresult);
        String[] resultstrs = new String[listresult.size()];
        listresult.toArray(resultstrs);
        return resultstrs;
    }

     void backtraceDfs( List<String> list, int index, Stack<Character> stack,List<String> listresult) {

        if (stack.size() == list.size()) {
            StringBuilder builder = new StringBuilder();
            for(int k = 0; k < stack.size(); k++) {
                builder.append(stack.get(k));
            }
            listresult.add(builder.toString());
           
            return;
        }

        for (int j = 0; j < list.get(index).length(); j++) {
            stack.add(list.get(index).charAt(j));
            backtraceDfs(list, index + 1, stack,listresult);
            stack.pop();
        }
    }
}