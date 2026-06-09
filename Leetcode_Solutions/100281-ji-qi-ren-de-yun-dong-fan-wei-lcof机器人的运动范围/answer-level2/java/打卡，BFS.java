    
    class Solution {
        public int movingCount(int m, int n, int k) {
            HashSet<String> hs = new HashSet<>();
            Queue<int[]> queue = new LinkedList<>();
            hs.add(0 + "#" + 0);
            queue.add(new int[] {0, 0});
            int count = 0;
            while(!queue.isEmpty()) {
                int[] arr = queue.poll();
                count++;
                int x = arr[0], y = arr[1];
                if(y + 1 < n && !hs.contains(x + "#" + (y + 1)) && deal(x) + deal(y + 1) <= k) {
                    hs.add(x + "#" + (y + 1));
                    queue.add(new int[] {x, y + 1});
                }
                if(x + 1 < m && !hs.contains((x + 1) + "#" + y) && deal(x + 1) + deal(y) <= k) {
                    hs.add((x + 1) + "#" + y);
                    queue.add(new int[] {x + 1, y});
                }
            }
            return count;
        }

        public static int deal(int x) {
            int sum = 0;
            while(x != 0) {
                sum += x % 10;
                x /= 10;
            }
            return sum;
        }
    }