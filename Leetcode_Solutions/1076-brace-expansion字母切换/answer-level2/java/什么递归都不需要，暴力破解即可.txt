```
    int idx = 0;
    public String[] expand(String S) {
        List<String> res= new ArrayList<>();

        if (S == null) return null;
        if (S.isEmpty()) return new String[0];
        char[] arr = S.toCharArray();
        StringBuilder sb = new StringBuilder();

        while (idx<arr.length){
            if (arr[idx]>='a' && arr[idx] <='z'){
                if (res.isEmpty()){
                    res.add(arr[idx]+"");
                } else {
                    List<String> tmp = new ArrayList<>();
                    for (String s: res){
                        tmp.add(s+arr[idx]);
                    }
                    res = new ArrayList<>(tmp);
                }
            }

            if (arr[idx] == '{'){
                int end = idx+1;
                while (end<arr.length && arr[end]!='}') end++;
                List<String> tmpRes = handle(S.substring(idx + 1, end));
                if (res.isEmpty()) res.addAll(tmpRes);
                else{
                    List<String> tmp = new ArrayList<>();
                    for (String s1: res){
                        for(String s2: tmpRes){
                            tmp.add(s1+s2);
                        }
                    }

                    res = new ArrayList<>(tmp);
                }
                idx = end;
            }
            idx++;
        }

        Collections.sort(res);
        String[] r = new String[res.size()];
        for (int i = 0; i < res.size(); i++) {
            r[i] = res.get(i);
        }
        return r;
    }

    private List<String> handle(String substring) {
        List<String> res = new ArrayList<>();
        for(String s: substring.split(",")) res.add(s);

        return res;
    }
```
