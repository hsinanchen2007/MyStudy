暴力搜索一遍，然后去除末尾空格。
```
public List<String> printVertically(String s) {
        List<String> res = new LinkedList<>();
        String[] tp = s.split(" ");
        int max = 0;//3
        for (String p : tp){
            max = Math.max(max,p.length());
        }
        int n = tp.length;
        for (int i = 0;i < max;i++){
            res.add("");
        }
        for (int i = 0;i < n;i++){
            for (int j = 0;j < max;j++){
                if (j >= tp[i].length()){
                    String tmp = res.get(j).concat(" ");
                    res.remove(j);
                    res.add(j,tmp);
                }else{
                    String tmp = res.get(j).concat(tp[i].charAt(j) + "");
                    res.remove(j);
                    res.add(j,tmp);
                }
            }
        }
        for (int i = 0;i < res.size();i++){
            String x = res.get(i).replaceAll("\\s+$","");
            res.remove(i);
            res.add(i,x);
        }
        return res;
    }
```
