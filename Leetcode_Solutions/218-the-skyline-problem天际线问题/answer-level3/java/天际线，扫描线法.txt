    
    class Solution {
        // 扫描线法
        // line sweep
        public List<List<Integer>> getSkyline(int[][] buildings) {
            // 1.create points
            List<List<Integer>> res = new ArrayList<>();
            List<List<Integer>> points = new ArrayList<>();
            for(int i = 0;i < buildings.length;i++) {
                List<Integer> leftUpper = new ArrayList<>();
                leftUpper.add(buildings[i][0]);
                leftUpper.add(-buildings[i][2]);
                points.add(leftUpper);
                
                List<Integer> rightUpper = new ArrayList<>();
                rightUpper.add(buildings[i][1]);
                rightUpper.add(buildings[i][2]);
                points.add(rightUpper);
            }
            // 2.sort points
            Collections.sort(points, new Comparator<List<Integer>>() {
                @Override
                public int compare(List<Integer> o1, List<Integer> o2) {
                    int x1 = o1.get(0);
                    int h1 = o1.get(1);
                    int x2 = o2.get(0);
                    int h2 = o2.get(1);
                    if(x1 != x2) {
                        return x1 - x2;
                    }else {
                        return h1 - h2;
                    }
                }
            });
            // 3.line sweep
            PriorityQueue<Integer> queue = new PriorityQueue<Integer>(new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {  // 大顶堆
                    return o2 - o1;
                }
            });
            queue.offer(0);
            int preMaxh = 0;
            for (List<Integer> point : points) {
                int x = point.get(0);
                int h = point.get(1);
                if(h < 0) {
                    queue.offer(-h);   // leftUpper
                }else {
                    queue.remove(h);   // rightUpper
                }
                int curMaxh = queue.peek();
                if(curMaxh != preMaxh) {    // curMax > preMax || curMax < preMax,the answer
                    List<Integer> ans = new ArrayList<>();
                    ans.add(x);
                    ans.add(curMaxh);
                    res.add(ans);
                    preMaxh = curMaxh;
                }
            }
            // 4.return
            return res;
        }
    }