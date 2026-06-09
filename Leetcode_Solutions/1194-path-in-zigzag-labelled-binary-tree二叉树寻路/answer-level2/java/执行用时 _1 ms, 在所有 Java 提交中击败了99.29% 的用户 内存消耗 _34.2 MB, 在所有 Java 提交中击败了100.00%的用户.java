`class Solution {
    private ArrayList<Integer> table;
    public List<Integer> pathInZigZagTree(int label) {
        List<Integer> list = new LinkedList<>();
        
        int i = 0;
        int n = 1;
        table = new ArrayList<>();
        table.add(n);
        while (n <= label) {
            n *= 2;
            i++;
            table.add(n);
        }
        int index;
        index = (i % 2 == 0) ? n - 1 - label : label - n / 2;
        n = n / 2; //i层的节点总数
        while (i > 0) {
            list.add(0, findNum(index+1, i--));
            index = index / 2;
        }
        return list;
        
    }
    public int findNum(int index, int deep) {
        int res;
        int max = table.get(deep);
        res = (deep % 2 == 0) ? max - index : max / 2 + index - 1;
        
        return res;
    }
}`