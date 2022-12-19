 public String getPermutation(int n, int k) {
        int fac = 1;
        List<Integer> list = new LinkedList<Integer>();

        for (int i = 1; i <= n; i++) {
            fac *= i;
            list.add(i);
        }
        int root ;
        StringBuilder sb = new StringBuilder();
        while (!list.isEmpty()){
            fac = fac/list.size();
            root = k % fac == 0 ? k / fac-1 : k / fac ;
            sb.append(list.remove(root));//此处应该进一步优化，暂时没有想到
            k = k - root  * fac;
        }
        return sb.toString();
    }