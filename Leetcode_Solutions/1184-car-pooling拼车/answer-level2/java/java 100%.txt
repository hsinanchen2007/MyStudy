class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] change = new int[1001];
        int cur = 0;
        for(int i = 0 ; i<trips.length;i++){
            int tmp = trips[i][0];
            change[trips[i][1]]+=tmp;
            change[trips[i][2]]-=tmp;
        }
        for(int i = 0 ; i<change.length;i++){
            cur+=change[i];
            if(cur>capacity)return false;
        }
        return  true;
    }
}