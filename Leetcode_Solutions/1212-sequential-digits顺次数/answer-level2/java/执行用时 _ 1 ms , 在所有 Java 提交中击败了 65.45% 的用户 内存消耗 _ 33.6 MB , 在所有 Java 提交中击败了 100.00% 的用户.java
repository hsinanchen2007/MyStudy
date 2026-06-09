```
代码块
``` public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> list = new ArrayList<>();
        List<Integer> res = new ArrayList<>();
        String s1 = String.valueOf(low);
        String s2 = String.valueOf(high);
        for (int i = s1.length(); i <= s2.length(); i++) {
            list.add(i);
        }
        for (int k = 0; k < list.size(); k++) {
            for (int i = 1; i <= 9; i++) {
                StringBuilder sb = new StringBuilder();
                for (int j = i; j <= i + list.get(k) - 1 && i + list.get(k) - 1 <= 9; j++) {
                    sb.append(j);
                }
                if(!sb.toString().equals("")){
                    Long integer = Long.valueOf(sb.toString());
                    if (integer >= low && integer <= high) {
                        res.add(Math.toIntExact(integer));
                    }
                }
            }
        }
        return res;
    }
