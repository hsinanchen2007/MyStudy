```
  public List<List<String>> partitionMine(String s) {
        List<List<String>> res = new ArrayList<>();
        List<String> list = new ArrayList<>();
        MyDfs(0,s.length()-1,list,res,s);
        return res;
    }

    private void MyDfs(int start, int end, List<String> cur, List<List<String>> res,String s) {
        if(start > end) {
            res.add(new ArrayList<>(cur));
            return;
        }
        for(int i = start; i<= end; i++) {
            if(isPar(s,start,i)) {
                cur.add(s.substring(start,i+1));
                MyDfs(i+1,end,cur,res,s);
                // 要把之前加的回文字符串去掉
                cur.remove(cur.size()-1);
            }
        }
    }

    private boolean isPar(String s, int start, int j) {
        while (start < j) {
            if(s.charAt(start) != s.charAt(j)) return false;
            start++;
            j--;
        }
        return true;
    }
```
