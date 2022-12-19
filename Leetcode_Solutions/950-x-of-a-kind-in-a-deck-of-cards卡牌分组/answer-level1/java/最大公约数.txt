class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        // 题意看懂： 这副牌必须是按照最大公约数的的倍数出牌。且最大公约数要大于等于2.
        // 并且是所有牌都是这样的X个一对才算是true。
        // 数组或set保存每张牌的数量，取所有牌的数量的公约数。
        // 如果公约数>=2，并且，则ok。
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        for( int i=0; i<deck.length; i++ ){
            map.put( deck[i], map.getOrDefault(deck[i],0)+1 );
        }
        int x= -1;
        for(Map.Entry<Integer, Integer> a:map.entrySet()){
            x = x==-1 ? a.getValue() : gcd( a.getValue(),x );
            if( x==1 ) return false;
        }
        return true;
    }

    // gcd算法
    int gcd(int a,int b){
        return b == 0 ? a:gcd( b, a%b ); 
    }

}