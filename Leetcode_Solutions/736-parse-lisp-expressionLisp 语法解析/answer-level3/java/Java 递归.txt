执行用时 :5 ms,在所有 java 提交中击败100.00%的用户
内存消耗 :36.5 MB,在所有 java 提交中击败了100.00%的用户

+ 利用递归一层层解析
+ 利用哈希表记录变量，每层独立的哈希表(继承上一层的哈希表数据)模拟作用域

代码如下：
```
    public int evaluate(String expression) {
        return slove(expression,new HashMap<>());
    }

    private int slove(String exp, Map<String,Integer> pre_map) {
        String[] exps=getExps(exp);
        if(exps[0].equals("let"))
        {
            Map<String,Integer> map=new HashMap<>(pre_map);
            for (int i=1;i<exps.length-2;i+=2)
            {
                int v=0;
                if(exps[i+1].charAt(0)=='(')v=slove(exps[i+1],map);
                else v=getValue(map,exps[i+1]);
                map.put(exps[i],v);
            }
            if(exps[exps.length-1].charAt(0)=='(')return slove(exps[exps.length-1],map);
            return getValue(map,exps[exps.length-1]);
        }
        else
        {
            int[] res=new int[2];
            for (int i=1;i<=2;i++)
            {
                if(exps[i].charAt(0)=='(')res[i-1]=slove(exps[i],pre_map);
                else res[i-1]=getValue(pre_map,exps[i]);
            }
            if(exps[0].equals("add"))return res[0]+res[1];
            return res[0]*res[1];
        }
    }

    private int getValue(Map<String, Integer> map, String exp) {
        if(map.containsKey(exp))return map.get(exp);
        return Integer.parseInt(exp);
    }

    private String[] getExps(String exp) {
        List<String> res=new ArrayList<>();
        char[] strs=exp.substring(1, exp.length()-1).toCharArray();
        int idx=0,pre=0;
        while (idx<strs.length)
        {
            if(strs[idx]==' ')
            {
                res.add(new String(strs,pre,idx-pre));
                pre=idx+1;
            }
            else if(strs[idx]=='(')
            {
                int cnt=0;
                while (idx<strs.length)
                {
                    if(strs[idx]=='(')cnt++;
                    else if(strs[idx]==')')cnt--;
                    idx++;
                    if(cnt==0)break;
                }
                res.add(new String(strs,pre,idx-pre));
                pre=idx+1;
            }
            idx++;
        }
        if(pre<strs.length)res.add(new String(strs,pre,strs.length-pre));
        return res.toArray(new String[res.size()]);
    }
```
