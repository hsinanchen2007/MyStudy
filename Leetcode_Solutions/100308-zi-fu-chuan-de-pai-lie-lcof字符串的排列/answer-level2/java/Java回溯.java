```
    public String[] permutation(String s)
    {
        int[] qq = new int[256];
        for (int i = 0; i < s.length();i++)
        {
            qq[s.charAt(i)]++;
        }
//将字符统计在数组中
        List<String> list = new ArrayList<>();
        getPermutation(s.length(),"",qq,list);
        String[] res = new String[list.size()];
        list.toArray(res);
        return res;

    }
    public void getPermutation(int n,String now,int[] qq,List<String> list)
    {
        if (now.length() == n)
        {
            list.add(now);
            return;
        }
//够长了，就返回
        for (int i = 0; i < qq.length;i++)
        {
            if (qq[i] > 0)
            {
                qq[i]--;
                getPermutation(n,now + (char)(i),qq,list);
                qq[i]++;
            }
//这么取不需要考虑去重问题
        }
    }
```
