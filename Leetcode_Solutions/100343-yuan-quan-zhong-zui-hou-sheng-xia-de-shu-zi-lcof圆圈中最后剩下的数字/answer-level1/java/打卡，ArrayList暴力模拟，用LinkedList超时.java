    // 用ArrayList
    class Solution {
        public int lastRemaining(int n, int m) {
            List<Integer> list = new ArrayList<>();
            for(int i = 0;i < n;i++) {
                list.add(i);           
            }
            int index = 0;
            while(list.size() > 1) {
                index = (index + m - 1) % list.size();
                list.remove(index);
            }
            return list.get(0);
        }
    }