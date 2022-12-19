class Solution {
    public int[][] highFive(int[][] items) {
        Map<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();
        int count = 0;
        for (int i = 0; i < items.length; i++) {
            if (!map.containsKey(new Integer(items[i][0]))) {
                count++;
                Integer tmp = new Integer(items[i][0]);
                ArrayList<Integer> arr = new ArrayList<>();
                arr.add(items[i][1]);
                map.put(tmp, arr);
            } else {
                map.get(new Integer(items[i][0])).add(items[i][1]);
            }
        }
        int[][] result = new int[count][2];
        map.forEach((key, value) -> {
                    result[key.intValue() - 1][0] = key.intValue();
                    Integer[] array = new Integer[value.size()];
                    value.toArray(array);
                    Arrays.sort(array, Collections.reverseOrder());
                    int sum = 0;
                    for (int j = 0; j < 5; j++) {
                        sum += array[j].intValue();
                    }
                    int average = sum/5;
                    result[key.intValue() - 1][1] = average;
        });
        return result;
    }
}