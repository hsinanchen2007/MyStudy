
思路很简单，首先判断，让小数为起始点，大数为结束点。之后进行遍历，在起始点和结束点之间的存为d1，即顺时针，剩下的存为d2，即逆时针，之后比较两个数，留下较小的数返回就可以了

class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int d1 = 0;
        int d2 = 0;
        if(start>destination){
            int n = destination;
            destination = start;
            start = n;
        }
        for(int i=0;i<distance.length;i++){
            if(i>=start&&i<destination){
                d1+=distance[i];
            }else{
                d2+=distance[i];
            }
        }
        int value = 0;
        if(d1<d2){
            value = d1;
        }else{
            value = d2;
        }
        return value;
    }
}