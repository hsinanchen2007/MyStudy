    public boolean isNStraightHand(int[] hand, int W) {
        Map<Integer, Integer> map = new HashMap<>();
        if(hand.length % W !=0) {
            return false;
        }
        if(W ==1 ){
             return true;
        }
        Arrays.sort(hand);
        for(int card : hand) {
            if(map.containsKey(card)) {
                map.put(card,map.get(card)+ 1);
            } else {
                map.put(card, 1);
            }
        }
        for(int card : hand) {
            if(map.containsKey(card) && map.get(card) > 0) {
                for(int i =0; i < W;i++) {
                    if(map.containsKey(card + i) && map.get(card + i) > 0) {
                        map.put(card+i, map.get(card+i) - 1);
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }