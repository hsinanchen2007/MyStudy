class Solution {
    List<List<Integer>> listAll = new ArrayList<List<Integer>>();
    List<Integer> list = new ArrayList<Integer>();
    public List<List<Integer>> generate(int numRows) {
        if (numRows < 1) {
            return listAll;
        }
        if (numRows == 1) {
            list.add(1);
            listAll.add(list);
            return listAll;
        }
        generate(numRows - 1);
        list = new ArrayList<Integer>();
        for (int i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows - 1) {
                list.add(1);
                continue;
            }
            list.add(listAll.get(numRows - 2).get(i - 1) + listAll.get(numRows - 2).get(i));
        }
        listAll.add(list);
        return listAll;
    }
}