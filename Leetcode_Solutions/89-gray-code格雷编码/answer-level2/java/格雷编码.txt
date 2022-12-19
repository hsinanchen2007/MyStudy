首先要了解格雷编码的生成规则

public List<Integer> grayCode(int n) {
        List<Integer> list = new ArrayList<Integer>();
        int num = 1 << n;
        for(int i = 0; i < num; i++) {
        	list.add(i ^ (i >> 1));
        }
        return list;
}