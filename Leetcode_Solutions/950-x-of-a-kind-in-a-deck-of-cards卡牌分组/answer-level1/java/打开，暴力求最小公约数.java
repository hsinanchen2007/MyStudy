    
    class Solution {
        public boolean hasGroupsSizeX(int[] deck) {
            Arrays.sort(deck);
            int min = Integer.MAX_VALUE;
            int left = 0, right = 0;
            List<Integer> list = new ArrayList<>();
            while(right < deck.length) {
                while(right < deck.length && deck[right] == deck[left]) {right++;}
                min = Math.min(min, right - left);
                list.add(right - left);
                left = right;
            }
            int res = getscb(list, min);
            return res <= 1 ? false : true;
        }

        public int getscb(List<Integer> list, int min) {
            if(list.size() == 0) {
                return 0;
            }
            if(list.size() == 1) {
                return list.get(0);
            }
            outer :for(int i = 2;i <= min;i++) {
                for(int j = 0;j < list.size();j++) {
                    if(list.get(j) % i != 0) {
                        continue outer;
                    }
                }
                return i;
            }
            return 1;
        }
    }